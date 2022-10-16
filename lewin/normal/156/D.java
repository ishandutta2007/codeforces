import java.io.*;
import java.util.*;

public class D157_1 {
	private static Reader in;
	private static PrintWriter out;
	
	private static int [] eadj, elast, eprev;
	private static int eidx;
	private static boolean [] vis;

	public static void main(String[] args) throws IOException {
		in = new Reader();
		out = new PrintWriter(System.out, true);

		int N = in.nextInt (), M = in.nextInt(), mod = in.nextInt();
		if (mod == 1) {
			out.println (0);
			out.close();
			System.exit(0);
		}
		
		eadj = new int [2 * M];
		elast = new int [N];
		eprev = new int [2 * M];
		Arrays.fill (elast, -1);
		eidx = 0;
		
		for (int i = 0; i < M; i++)
			addEdge (in.nextInt() - 1, in.nextInt() - 1);
		
		vis = new boolean [N];
		
		int numGroups = 0;
		int [] groups = new int [N];
		
		for (int i = 0; i < N; i++)
			if (!vis [i])
				groups [numGroups++] = mark (i);
		
		if (numGroups == 1) {
			out.println (1);
			System.exit(0);
		}
		
		long sum = 0;
		for (int i = 0; i < numGroups; i++) {
			sum += groups [i];
			if (sum >= mod) sum -= mod;
		}
		
		long prod = exp (sum, numGroups - 2, mod);
		for (int i = 0; i < numGroups; i++) {
			prod = (prod * groups [i]) % mod;
		}
		
		out.println (prod);
		out.close();
		System.exit(0);
	}
	
	private static long exp (long b, int e, int mod) {
		long res = 1;
		while (e > 0) {
			if ((e & 1) != 0)
				res = (res * b) % mod;
			b = (b * b) % mod;
			e >>= 1;
		}
		return res;
	}
	
	private static int mark (int node) {
		if (vis [node]) return 0;
		vis [node] = true;
		int count = 1;
		for (int e = elast [node]; e != -1; e = eprev [e]) {
			count += mark (eadj [e]);
		}
		return count;
	}
	
	private static void addEdge (int a, int b) {
		eadj [eidx] = b; eprev [eidx] = elast [a]; elast [a] = eidx++;
		eadj [eidx] = a; eprev [eidx] = elast [b]; elast [b] = eidx++;
	}

	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[1024];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}