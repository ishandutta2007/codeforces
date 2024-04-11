import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	boolean allSame(String s) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(0)) {
				return false;
			}
		}
		return true;
	}

	int count(String s, char c) {
		int ret = 0;
		for (int i = 0; i < s.length(); i++) {
			ret += s.charAt(i) == c ? 1 : 0;
		}
		return ret;
	}

	String tryFirstTwoSame(char[] buf) {
		int n = buf.length;
		int fst = 0;
		while (buf[0] == buf[fst]) {
			fst++;
		}
		// fst >= 2 since we checked with count() before
		int rest = n - fst;

		int ptr = 0;
		int ptrRest = fst;

		if (rest >= fst - 2) {
			char[] ret = new char[n];
			ret[ptr++] = buf[0];
			for (int i = 1; i < fst; i++) {
				ret[ptr++] = buf[0];
				// unless it's the end
				if (i != fst - 1) {
					ret[ptr++] = buf[ptrRest++];
				}
			}
			if (ptr != ptrRest) {
				throw new AssertionError();
			}
			for (int i = ptr; i < n; i++) {
				ret[i] = buf[i];
			}
			return new String(ret);
		}
		return null;
	}
	
	String twoFirstTwoDiff(char[] buf) {
		int n = buf.length;
		int fst = 0;
		while (buf[0] == buf[fst]) {
			fst++;
		}
		
		int rest = n - fst;

		if (buf[fst] == buf[n - 1]) {
			StringBuilder sb = new StringBuilder();
			sb.append(buf[0]);
			for (int i = 0; i < rest; i++) {
				sb.append(buf[fst]);
			}
			for (int i = 1; i < fst; i++) {
				sb.append(buf[0]);
			}
			return sb.toString();
		}
		
		int snd = fst;
		while (buf[fst] == buf[snd]) {
			snd++;
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(buf[0]);
		sb.append(buf[fst]);
		for (int i = 1; i < fst; i++) {
			sb.append(buf[0]);
		}
		sb.append(buf[snd]);
		for (int i = fst; i < n; i++) {
			if (i != fst && i != snd) {
				sb.append(buf[i]);
			}
		}
		return sb.toString();
	}

	String solve(String s) {
		if (allSame(s)) {
			return s;
		}

		char[] buf = s.toCharArray();
		

		for (char c = 'a'; c <= 'z'; c++) {
			if (count(s, c) == 1) {
				int idx = s.indexOf(c);
				char tmp = buf[idx];
				buf[idx] = buf[0];
				buf[0] = tmp;
				Arrays.sort(buf, 1, s.length());
				return new String(buf);
			}
		}

		Arrays.sort(buf);
		
		String cand = tryFirstTwoSame(buf);
		if (cand != null) {
			return cand;
		}

		return twoFirstTwoDiff(buf);
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			out.println(solve(nextToken()));
		}
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