import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	public static class Modular
	{
		int mod;
		int inv;
		int r2;
		int level;
		int omega;
		int ONE;
		Modular(int m)
		{
			mod = m;
			assert(mod % 2 == 1);
			inv = m;
			for (int i = 0; i < 5; ++i) inv *= 2 - inv * mod;
			assert(inv * mod == 1);
			r2 = (int)((1L << 32) % mod);
			r2 = (int)((long)r2 * r2 % mod);
			ONE = this.init(1);
		}
		Modular(int m, int g)
		{
			mod = m;
			assert(mod % 2 == 1);
			inv = m;
			for (int i = 0; i < 5; ++i) inv *= 2 - inv * mod;
			assert(inv * mod == 1);
			r2 = (int)((1L << 32) % mod);
			r2 = (int)((long)r2 * r2 % mod);
			ONE = this.init(1);
			level = Integer.numberOfTrailingZeros(mod - 1);
			omega = this.pow(this.init(g), (mod - 1) >> level);
		}
		private int reduce(long x)
		{
			int y = (int)(x >>> 32) - (int)((((long)((int)x * inv) & ((1L << 32) - 1)) * mod) >>> 32);
			return y < 0 ? y + mod : y;
		}
		int init(int x)
		{
			return reduce((long)x * r2);
		}
		int add(int a, int b)
		{
			int c = a + b - mod;
			if (c < 0) c += mod;
			return c;
		}
		int subtract(int a, int b)
		{
			int c = a - b;
			if (c < 0) c += mod;
			return c;
		}
		int multiply(int a, int b)
		{
			return reduce((long)a * b);
		}
		int pow(int a, int exp)
		{
			int res = ONE;
			for (int base = a; exp != 0; exp >>= 1, base = multiply(base, base))
			{
				if ((exp & 1) == 1) res = multiply(res, base);
			}
			return res;
		}
		int inverse(int a)
		{
			return pow(a, mod - 2);
		}
		int get(int x)
		{
			return reduce(x);
		}
	}

	public static class NumberTheoryTransform
	{
		Modular mod;
		NumberTheoryTransform(int mod, int g)
		{
			this.mod = new Modular(mod, g);
		}
		int[] lhs, rhs;
		int[] multiply(int[] a, int[] b)
		{
			int n = a.length, m = b.length;
			int s = n + m - 1;
			int size = 1;
			while (size < s) size <<= 1;
			int[] roots = new int[mod.level];
			roots[0] = mod.omega;
			for (int i = 1; i < mod.level; ++i) roots[i] = mod.multiply(roots[i - 1], roots[i - 1]);
			if (lhs == null || lhs.length < size)
			{
				lhs = new int[size];
				rhs = new int[size];
			}
			for (int i = 0; i < n; ++i) lhs[i] = a[i];
			Arrays.fill(lhs, n, size, 0);
			for (int i = 0; i < m; ++i) rhs[i] = b[i];
			Arrays.fill(rhs, m, size, 0);
			transform(lhs, size, 1, roots);
			transform(rhs, size, 1, roots);
			for (int i = 0; i < size; ++i) lhs[i] = mod.multiply(lhs[i], rhs[i]);
			transform(lhs, size, -1, roots);
			int inv = mod.inverse(mod.init(size));
			for (int i = 0; i < s; ++i) lhs[i] = mod.multiply(lhs[i], inv);
			return Arrays.copyOf(lhs, s);
		}
		void revPermute(int[] a, int n)
		{
			int r = 0, nh = n >> 1;
			for (int i = 1; i < n; ++i)
			{
				int h = nh;
				while (true)
				{
					r ^= h;
					if ((r & h) != 0) break;
					h >>= 1;
				}
				if (r > i)
				{
					int tmp = a[i];
					a[i] = a[r];
					a[r] = tmp;
				}
			}
		}
		void transform(int[] a, int n, int sign, int[] roots)
		{
			revPermute(a, n);
			int logn = Integer.numberOfTrailingZeros(n);
			assert(logn <= mod.level);
			if ((logn & 1) == 1)
			{
				for (int i = 0; i < n; i += 2)
				{
					int x = a[i], y = a[i + 1];
					a[i] = mod.add(x, y);
					a[i + 1] = mod.subtract(x, y);
				}
			}
			int imag = roots[mod.level - 2];
			if (sign == -1) imag = mod.inverse(imag);

			for (int e = 2 + (logn & 1); e <= logn; e += 2)
			{
				int m = 1 << e;
				int m4 = m >> 2;
				int dw = roots[mod.level - e];
				if (sign == -1) dw = mod.inverse(dw);
				int block = Math.min(n, Math.max(m, 1 << 12));
				for (int k = 0; k < n; k += block)
				{
					int w = mod.ONE, w2 = mod.ONE, w3 = mod.ONE;
					for (int j = 0; j < m4; ++j)
					{
						for (int i = k + j; i < k + block; i += m)
						{
							int a0 = a[i];
							int a2 = mod.multiply(a[i + m4], w2);
							int a1 = mod.multiply(a[i + m4 * 2], w);
							int a3 = mod.multiply(a[i + m4 * 3], w3);
							int t02 = mod.add(a0, a2);
							int t13 = mod.add(a1, a3);
							a[i] = mod.add(t02, t13);
							a[i + m4 * 2] = mod.subtract(t02, t13);
							t02 = mod.subtract(a0, a2);
							t13 = mod.multiply(mod.subtract(a1, a3), imag);
							a[i + m4] = mod.add(t02, t13);
							a[i + m4 * 3] = mod.subtract(t02, t13);
						}
						w = mod.multiply(w, dw);
						w2 = mod.multiply(w, w);
						w3 = mod.multiply(w2, w);
					}
				}
			}
		}
	}
	
	void solve()
	{
		NumberTheoryTransform ntt = new NumberTheoryTransform(998244353, 3);
		int n = ni(), x = ni(), y = ni();
		int[] a = new int[x + 1];
		int[] b = new int[x + 1];
		for (int i = 0; i <= n; ++i)
		{
			int p = ni();
			a[p] = ntt.mod.ONE;
			b[x - p] = ntt.mod.ONE;
		}

		int[] c = ntt.multiply(a, b);

		int N = 500000;
		int[] res = new int[N+1];
		for (int i = 0; i <= 2*x; ++i)
		{
			if (ntt.mod.get(c[i]) == 0) continue;
			int p = Math.abs(i-x);
			if (p == 0) continue;
			if (p+y <= N)
			{
				res[p+y] = 1;
			}
		}
		for (int i = N; i >= 1; -- i)
			if (res[i] == 1)
			{
				for (int j = i; j <= N; j += i)
					res[j] = Math.max(res[j], i);
			}
		int q = ni();
		for (int i = 0; i < q; ++i)
		{
			int p = ni()/2;
			if (res[p] == 0)
				out.println(-1);
			else
				out.println(res[p]*2);
		}
	}

	void run()
	{
		//is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		is = System.in;
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}

	public static void main(String[] args) throws Exception
	{
		new Thread(null, new Runnable()
		{
			public void run()
			{
				new Main().run();
			}
		}, "whatever", 1<<28).start();
	}
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}