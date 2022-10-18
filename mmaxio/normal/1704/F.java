import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}

	static class Value implements Comparable<Value> {
		double ord;
		int nim;

		public Value(double ord, int nim) {
			this.ord = ord;
			this.nim = nim;
		}

		static Value sum(Value a, Value b) {
			return new Value(a.ord + b.ord, a.nim ^ b.nim);
		}

		@Override
		public int compareTo(Value o) {
			if (ord != o.ord) {
				return ord < o.ord ? -1 : 1;
			}
			return Integer.compare(nim, o.nim);
		}

		@Override
		public String toString() {
			return "[" + ord + " " + nim + "*]";
		}
	}

	HashMap<String, Value> memo = new HashMap<>();

	Value solve(String s) {
		while (s.startsWith("__")) {
			s = s.substring(1);
		}
		while (s.endsWith("__")) {
			s = s.substring(0, s.length() - 1);
		}
		if (memo.containsKey(s)) {
			return memo.get(s);
		}
		ArrayList<Value> left = new ArrayList<>();
		ArrayList<Value> right = new ArrayList<>();

		for (int i = 0; i < s.length() - 1; i++) {
			String lft = s.substring(0, i) + "_";
			String rgh = "_" + s.substring(i + 2);
			Value cur = Value.sum(solve(lft), solve(rgh));
			if (s.charAt(i) == 'L' || s.charAt(i + 1) == 'L') {
				left.add(cur);
			}
			if (s.charAt(i) == 'R' || s.charAt(i + 1) == 'R') {
				right.add(cur);
			}
		}

		left = removeDominated(left, 1);
		right = removeDominated(right, -1);

		if (left.isEmpty() && right.isEmpty()) {
			Value val = new Value(0, 0);
			memo.put(s, val);
			return val;
		}
		
		if (left.isEmpty()) {
			Value val = new Value(before(right.get(0).ord), 0);
			memo.put(s, val);
			return val;
		}
		if (right.isEmpty()) {
			Value val = new Value(after(left.get(0).ord), 0);
			memo.put(s, val);
			return val;
		}
		if (left.get(0).ord != right.get(0).ord) {
			throw new AssertionError(s);
		}
		
		Value val = new Value(left.get(0).ord, nimCombine(left, right));
		memo.put(s, val);
		return val;
	}
	
	int nimCombine(ArrayList<Value> l, ArrayList<Value> r) {
		if (l.size() != r.size()) {
			throw new AssertionError();
		}
		for (int i = 0; i < l.size(); i++) {
			if (l.get(i).nim != r.get(i).nim) {
				throw new AssertionError();
			}
		}
		for (int i = 0; i < l.size(); i++) {
			if (l.get(i).nim != i) {
				return i;
			}
		}
		return l.size();
	}

	double before(double x) {
		if (x == 0) {
			return -1;
		}
		if (x < 0) {
			return before(x + 1) - 1;
		}
		throw new AssertionError();
	}

	double after(double x) {
		if (x == 0) {
			return 1;
		}
		if (x > 0) {
			return after(x - 1) + 1;
		}
		throw new AssertionError();
	}

	ArrayList<Value> removeDominated(ArrayList<Value> lst, int sign) {
		if (lst.isEmpty()) {
			return lst;
		}
		Collections.sort(lst);
		int sz = 0;
		for (int i = 0; i < lst.size(); i++) {
			if (i == 0 || lst.get(i).compareTo(lst.get(i - 1)) != 0) {
				lst.set(sz++, lst.get(i));
			}
		}
		while (lst.size() > sz) {
			lst.remove(lst.size() - 1);
		}
		if (sign == 1) {
			Collections.reverse(lst);
		}
		while (lst.get(lst.size() - 1).ord != lst.get(0).ord) {
			lst.remove(lst.size() - 1);
		}

		if (sign == 1) {
			Collections.reverse(lst);
		}

		return lst;
	}
	
	int fast(String s) {
		for (int i = 0; i < s.length() - 1; i++) {
			if (s.charAt(i) == s.charAt(i + 1)) {
				return solve(s.substring(0, i + 1)).nim ^ fast(s.substring(i + 1));
			}
		}
		return solve(s).nim;
	}

	void submit() {
		int t = in.nextInt();
		while (t-- > 0) {
			in.nextInt();
			String s = in.nextToken();
			int bal = 0;
			for (int i = 0; i < s.length(); i++) {
				bal += s.charAt(i) == 'R' ? 1 : -1;
			}
			if (bal > 0) {
				out.println("Alice");
			} else if (bal < 0) {
				out.println("Bob");
			} else {
				int xor = 0;
				int last = 0;
				for (int i = 0; i < s.length() - 1; i++) {
					if (s.charAt(i) == s.charAt(i + 1)) {
						xor ^= kek(i + 1 - last);
						last = i + 1;
					}
				}
				xor ^= kek(s.length() - last);
				out.println(xor != 0 ? "Alice" : "Bob");
			}
			
		}
//		String s = "RLRLRLRLRLRLRLRL" + "LRLRLRLRLRLRLRLRLR";
//		out.println(solve(s).toString());
		/*
//		s = "";
		String s = "";
//		for (int i = 1; i <= 8; i++) {
//			s += rng.nextBoolean() ? "L" : "R";
//		}
//		out.println(s + " " + solve(s));
		for (int i = 1; i <= 20; i++) {
			s += i % 2 == 0 ? "L" : "R";
//			s += "R";
			out.println(s + " " + solve(s));
		}
		
//		for (int tst = 0, succ = 0; succ < 1000000; tst++) {
//			int n = rand(1, 20);
//			StringBuilder sb = new StringBuilder();
//			double bal = 0;
//			for (int i = 0; i < n; i++) {
//				String c = rng.nextBoolean() ? "L" : "R";
//				sb.append(c);
//				bal += c.equals("L") ? 1 : -1;
//			}
//			String s = sb.toString();
//			if (bal == n || bal == -n) {
//				continue;
//			}
//			if (bal != 0) {
//				continue;
//			}
//			succ++;
//			if (solve(s).nim != fast(s)) {
//				System.err.println(s + " " + solve(s) + " " + fast(s));
//				throw new AssertionError();
//			}
//		}
//		System.err.println("OK!");*/
	}
	
	int kek(int n) {
		if (n > 60) {
			n = 60 + (n - 60) % 34;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(i % 2 == 0 ? 'L' : 'R');
		}
		return solve(sb.toString()).nim;
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) {
		new F().run();
	}

	FastIn in;
	FastOut out;

	static final int BUF_SZ = 1 << 14;

	static class FastIn {

		private InputStream is;

		public FastIn(InputStream is) {
			this.is = is;
		}

		private byte[] buf = new byte[BUF_SZ];
		private int sz = 0, ptr = 0;
		private ByteArrayOutputStream tokBuf = new ByteArrayOutputStream(BUF_SZ);

		int nextInt() {
			return (int) nextLong();
		}

		long nextLong() {
			long ret = 0;
			int b = scanNonTrash();
			if (b != '-' && !isDigit(b - '0')) {
				throw new InputMismatchException();
			}
			boolean neg = false;
			if (b == '-') {
				neg = true;
				b = scanByte();
			}
			for (;; b = scanByte()) {
				int d = b - '0';
				if (isDigit(d)) {
					ret = ret * 10 + d;
				} else {
					if (b != -1 && !isTrash(b)) {
						throw new InputMismatchException();
					}
					return neg ? -ret : ret;
				}
			}
		}

		String nextToken() {
			tokBuf.reset();
			for (int b = scanNonTrash(); !isTrash(b); b = scanByte()) {
				tokBuf.write(b);
			}
			return tokBuf.toString();
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		char nextChar() {
			return (char) scanNonTrash();
		}

		boolean sawEoF() {
			return sz < 0;
		}

		void close() {
			try {
				is.close();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private boolean isDigit(int d) {
			return d >= 0 && d < 10;
		}

		private int scanByte() {
			if (ptr < sz) {
				return buf[ptr++];
			}
			if (sawEoF()) {
				throw new UncheckedIOException("Reading past EoF", new EOFException());
			}
			ptr = 0;
			try {
				sz = is.read(buf);
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
			return sz > 0 ? buf[ptr++] : -1;
		}

		private boolean isTrash(int c) {
			return c < 33 || c > 126;
		}

		private int scanNonTrash() {
			int b;
			while ((b = scanByte()) != -1 && isTrash(b))
				;
			return b;
		}
	}

	static class FastOut {

		private OutputStream os;

		public FastOut(OutputStream os) {
			this.os = os;
			try {
				strField = String.class.getDeclaredField("value");
				strField.setAccessible(true);
				Object strValue = strField.get("");
				if (strValue instanceof byte[]) {
					j9Plus = true;
				} else if (strValue instanceof char[]) {
					j9Plus = false;
				} else {
					throw new RuntimeException("Weird string");
				}
			} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
				throw new RuntimeException("String reflection problem", e);
			}
		}

		private final java.lang.reflect.Field strField;
		private final boolean j9Plus;

		private byte[] buf = new byte[2 * BUF_SZ];
		private int ptr = 0;

		FastOut print(long x) {
			int d;
			if (x < 0) {
				if (x == Long.MIN_VALUE) {
					return print(x / 10).print('8');
				}
				d = strLen(x = -x);
				buf[ptr++] = '-';
			} else {
				d = strLen(x);
			}
			for (int i = ptr += d; d > 0; x /= 10, --d) {
				buf[--i] = (byte) ('0' + (x % 10));
			}
			return maybeBufFlush();
		}

		FastOut print(char c) {
			buf[ptr++] = (byte) c;
			return maybeBufFlush();
		}

		FastOut print(String s) {
			Object value;
			try {
				value = strField.get(s);
				if (j9Plus) {
					print((byte[]) value);
				} else {
					print((char[]) value);
				}
			} catch (IllegalArgumentException | IllegalAccessException e) {
				throw new RuntimeException("String reflection problem", e);
			}
			return this;
		}

		FastOut println(long x) {
			return print(x).println();
		}

		FastOut println(String s) {
			return print(s).println();
		}

		FastOut println() {
			return print('\n');
		}

		void flush() {
			bufFlush();
			try {
				os.flush();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		void close() {
			flush();
			try {
				os.close();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private FastOut maybeBufFlush() {
			if (ptr >= BUF_SZ) {
				bufFlush();
			}
			return this;
		}

		private void bufFlush() {
			try {
				os.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private void print(byte[] bytes) {
			int n = bytes.length;
			if (ptr + n >= BUF_SZ) {
				bufFlush();
				try {
					os.write(bytes);
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			} else {
				System.arraycopy(bytes, 0, buf, ptr, n);
				ptr += n;
			}
		}

		private void print(char[] chars) {
			int i = 0, s;
			while ((s = Math.min(chars.length - i, BUF_SZ)) > 0) {
				while (s-- > 0) {
					buf[ptr++] = (byte) chars[i++];
				}
				maybeBufFlush();
			}
		}

		private static final int strLen(long x) {
			long p = 10;
			for (int i = 1; i < 19; i++) {
				if (x < p)
					return i;
				p *= 10;
			}
			return 19;
		}

	}
}