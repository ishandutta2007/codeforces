import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

//	void put(HashMap<Integer, ArrayList<Integer>> map, int key, int val) {
//		ArrayList<Integer> al = map.get(key);
//		if (al == null) {
//			al = new ArrayList<>();
//			map.put(key, al);
//		}
//		al.add(val);
//	}
	
	static final int C = 500_010;
	
	void submit() {
		int n = nextInt();
//		HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
		
		int[] arrPos = new int[C];
		int[] arrNeg = new int[C];
		
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			int bal = 0;
			int min = 0;
			for (char c : s.toCharArray()) {
				int delta = c == '(' ? 1 : -1;
				bal += delta;
				min = Math.min(min, bal);
			}
//			put(map, bal, min);
			if (bal >= 0) {
				arrPos[bal] += min >= 0 ? 1 : 0;
			} else {
				arrNeg[-bal] += min >= bal ? 1 : 0;
			}
		}
		
		int ans = arrPos[0] / 2;
		
		for (int i = 1; i < C; i++) {
			ans += Math.min(arrPos[i], arrNeg[i]);
		}
		
//		for (Map.Entry<Integer, ArrayList<Integer>> e : map.entrySet()) {
//			if (e.getKey() < 0) {
//				continue;
//			}
//			ArrayList<Integer> pos = e.getValue();
//			ArrayList<Integer> neg = map.get(-e.getKey());
//			if (neg == null) {
//				continue;
//			}
//			
//			int okPos = 0;
//			for (int x : pos) {
//				if (x >= 0) {
//					okPos++;
//				}
//			}
//			
//			int okNeg = 0;
//			for (int x : neg) {
//				if (x >= -e.getKey()) {
//					okNeg++;
//				}
//			}
//			
//			if (e.getKey() != 0) {
//				ans += Math.min(okPos, okNeg);
//			} else {
//				ans += okPos / 2;
//			}
//		}
		
		out.println(ans);
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
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

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