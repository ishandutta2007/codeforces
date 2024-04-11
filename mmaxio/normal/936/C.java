import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	int find(char c, int delta) {
		int i = delta > 0 ? 0 : s.length - 1;
		while (s[i] != c) {
			i += delta;
		}
		return i;
	}

	ArrayList<Integer> ans = new ArrayList<>();

	void shift(int x) {
		ans.add(x);
		char[] newS = new char[s.length];
		int pos = s.length - x;
		int ptr = 0;
		for (int i = s.length - 1; i >= pos; i--) {
			newS[ptr++] = s[i];
		}
		for (int i = 0; i < pos; i++) {
			newS[ptr++] = s[i];
		}
		s = newS;
	}

	void makeLast(int pos) {
		shift(s.length - 1 - pos);
	}

	void go(int l, int r) {
		int len = Math.abs(r - l) + 1;
		if (l == r) {
			makeLast(find(t[l], 1));
			return;
		}
		if (l < r) {
			if (len > 2) {
				go(r, l + 2);
			}
			int x = find(t[l + 1], 1);
			makeLast(x);
			shift(1);
			int y = find(t[l], -1);
			makeLast(y - 1);
			shift(y - len + 1);
		} else {
			if (len > 2) {
				go(r, l - 2);
			}
			int x = find(t[l - 1], 1);
			makeLast(x);
			shift(1);
			int y = find(t[l], -1);
			makeLast(y - 1);
			shift(y - len + 1);
		}
	}

	char[] s, t;

	void submit() {
		nextInt();
		s = nextToken().toCharArray();
		t = nextToken().toCharArray();

		char[] ss = s.clone();
		char[] tt = t.clone();
		Arrays.sort(ss);
		Arrays.sort(tt);
		if (!Arrays.equals(ss, tt)) {
			out.println(-1);
			return;
		}

		go(0, s.length - 1);
		
//		if (!Arrays.equals(s, t)) {
//			throw new AssertionError();
//		}
		
		out.println(ans.size());
		for (int x : ans) {
			out.print(x + " ");
		}
	}

	void preCalc() {

	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	C() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}