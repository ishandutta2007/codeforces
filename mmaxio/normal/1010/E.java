import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	static class Point implements Comparable<Point> {
		int x, y, z;

		public Point(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		@Override
		public int compareTo(Point o) {
			return Integer.compare(x, o.x);
		}
	}
	
	static class Query implements Comparable<Query> {
		int x, y, z;
		int sign;
		int id;
		public Query(int x, int y, int z, int sign, int id) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.sign = sign;
			this.id = id;
		}
		@Override
		public int compareTo(Query o) {
			return Integer.compare(x, o.x);
		}
	}
	
	void submit() {
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		
		int x1 = a, x2 = 0, y1 = b, y2 = 0, z1 = c, z2 = 0;
		
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int z = nextInt() - 1;
			x1 = Math.min(x1, x);
			x2 = Math.max(x2, x);
			y1 = Math.min(y1, y);
			y2 = Math.max(y2, y);
			z1 = Math.min(z1, z);
			z2 = Math.max(z2, z);
		}
		
		Point[] bad = new Point[m];
		
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int z = nextInt() - 1;
			if (x1 <= x && x <= x2 && y1 <= y && y <= y2 && z1 <= z && z <= z2) {
				out.println("INCORRECT");
				return;
			}
			bad[i] = new Point(x, y, z);
		}
		
		out.println("CORRECT");
		int[] ans = new int[k];
		Query[] qs = new Query[8 * k];
		int ptr = 0;
		for (int i = 0; i < k; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int z = nextInt() - 1;
			if (!(x1 <= x && x <= x2 && y1 <= y && y <= y2 && z1 <= z && z <= z2)) {
				ans[i] |= 2;
				
				int qx1 = Math.min(x1, x) - 1;
				int qx2 = Math.max(x2, x);
				int qy1 = Math.min(y1, y) - 1;
				int qy2 = Math.max(y2, y);
				int qz1 = Math.min(z1, z) - 1;
				int qz2 = Math.max(z2, z);
				
				qs[ptr++] = new Query(qx2, qy2, qz2, 1, i);
				qs[ptr++] = new Query(qx1, qy2, qz2, -1, i);
				qs[ptr++] = new Query(qx2, qy1, qz2, -1, i);
				qs[ptr++] = new Query(qx1, qy1, qz2, 1, i);
				qs[ptr++] = new Query(qx2, qy2, qz1, -1, i);
				qs[ptr++] = new Query(qx1, qy2, qz1, 1, i);
				qs[ptr++] = new Query(qx2, qy1, qz1, 1, i);
				qs[ptr++] = new Query(qx1, qy1, qz1, -1, i);
				
			} else {
				ans[i] |= 1;
			}
		}
		
		qs = Arrays.copyOf(qs, ptr);
		
		ArrayList<Integer>[] ptsAL = new ArrayList[b];
		for (int i = 0; i < b; i++) {
			ptsAL[i] = new ArrayList<Integer>();
		}
		
		for (Point p : bad) {
			int y = p.y;
			int z = p.z;
			
			for (int i = y; i < b; i |= i + 1) {
				ptsAL[i].add(z);
			}
		}

		int[][] pts = new int[b][];
		int[][] fens = new int[b][];
		
		for (int i = 0; i < b; i++) {
			pts[i] = makeUnique(ptsAL[i]);
			fens[i] = new int[pts[i].length];
		}
		
		Arrays.sort(bad);
		Arrays.sort(qs);
		
		int[] count = new int[k];
		
		ptr = 0;
		for (Query q : qs) {
			while (ptr < bad.length && bad[ptr].x <= q.x) {
				int y = bad[ptr].y;
				int z = bad[ptr].z;
				
				for (int i = y; i < b; i |= i + 1) {
					
					int idx = Arrays.binarySearch(pts[i], z);
					int[] fensI = fens[i];
					int ptsLen = pts[i].length;
					for (int j = idx; j < ptsLen; j |= j + 1) {
						fensI[j]++;
					}
				}
				
				ptr++;
			}
			
			if (q.x < 0 || q.y < 0 || q.z < 0) {
				continue;
			}
			
			int qVal = 0;
			int qz = q.z;
			for (int i = q.y; i >= 0; i = (i & (i + 1)) - 1) {
				int idx = Arrays.binarySearch(pts[i], qz);
				if (idx < 0) {
					idx = -idx - 2;
				}
				int[] fensI = fens[i];
				for (int j = idx; j >= 0; j = (j & (j + 1)) - 1) {
					qVal += fensI[j];
				}
			}
			
			count[q.id] += q.sign * qVal;
		}
		
		for (int i = 0; i < k; i++) {
			if (count[i] == 0) {
				ans[i] |= 1;
			}
		}
		
		for (int i = 0; i < k; i++) {
			out.println(new String[]{"OPEN", "CLOSED", "UNKNOWN"}[ans[i] - 1]);
		}
	}
	
	int[] makeUnique(ArrayList<Integer> a) {
		Collections.sort(a);
		int sz = 0;
		for (int i = 0; i < a.size(); i++) {
			if (i == 0 || a.get(i).intValue() != a.get(i - 1).intValue()) {
				a.set(sz, a.get(i));
				sz++;
			}
		}
		
		int[] ret = new int[sz];
		for (int i = 0; i < sz; i++) {
			ret[i] = a.get(i);
		}
		return ret;
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

	E() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
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
		new E();
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