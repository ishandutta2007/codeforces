import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	static class Value {
		int rem, mult;

		public Value(int rem, int mult) {
			this.rem = rem;
			this.mult = mult;
		}

		void append(Value o) {
			rem = plus(times(rem, o.mult), o.rem);
			mult = times(mult, o.mult);
		}
	}

	static int minus(int a, int b) {
		a -= b;
		if (a < 0) {
			a += P;
		}
		return a;
	}

	static int plus(int a, int b) {
		a += b;
		if (a >= P) {
			a -= P;
		}
		return a;
	}

	static int times(int a, int b) {
		return (int) ((long) a * b % P);
	}

	static int divide(int a, int b) {
		return (int) ((long) a * pow(b, P - 2) % P);
	}

	static int pow(int a, int b, int mod) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % mod);
			}
			a = (int) ((long) a * a % mod);
		}
		return ret;
	}

	static int pow(int a, int b) {
		return pow(a, b, P);
	}

	Value sameLen(int x7, int x6, int y7, int y6, int p) {
		int diff6 = y6 - x6;
		if (diff6 < 0) {
			diff6 += P - 1;
		}

		int sub1 = minus(p, 1);
		int pow = pow(p, diff6);

		return new Value(divide(
				plus(times(minus(times(x7, times(pow, p)), y7), sub1),
						times(p, minus(pow, 1))), times(sub1, sub1)), times(
				pow, p));

		// return new Value(0, mult)
	}

	int getRem(String s, int mod) {
		int ret = 0;
		for (int i = 0; i < s.length(); i++) {
			ret = (int) ((10L * ret + s.charAt(i) - '0') % mod);
		}
		return ret;
	}

	Value dash(String low, String high) {
		int x7 = getRem(low, P);
		int x6 = getRem(low, P - 1);

		int y7 = getRem(high, P);
		int y6 = getRem(high, P - 1);

		int p7 = pow(10, low.length() - 1);
		int p6 = pow(10, low.length() - 1, P - 1);

		Value ret = new Value(0, 1);

		for (int len = low.length(); len <= high.length(); len++) {
			int nextP7 = times(10, p7);
			int nextP6 = (int) (10L * p6 % (P - 1));
			Value tmp = sameLen(len == low.length() ? x7 : p7,
					len == low.length() ? x6 : p6, len == high.length() ? y7
							: nextP7 - 1, len == high.length() ? y6
							: nextP6 - 1, nextP7);
			ret.append(tmp);
			p7 = nextP7;
			p6 = nextP6;
		}

		return ret;
	}

	Value number(String s) {
		return dash(s, s);
	}

	Value copy(String s, Value what) {
		if (what.mult != 1) {

			int s6 = getRem(s, P - 1);

			int pow = pow(what.mult, s6);

			return new Value(times(what.rem,
					divide(minus(pow, 1), minus(what.mult, 1))), pow);
		}
		
		int s7 = getRem(s, P);
		
		return new Value(times(s7, what.rem), 1);
	}

	Value parseExpr(Lexer lex) {
		Value what = parseTerm(lex);
		while (lex.get().equals("+")) {
			lex.advance();
			Value rhs = parseExpr(lex);
			what.append(rhs);
		}
		return what;
	}

	Value parseTerm(Lexer lex) {
		String num = lex.get();
		lex.advance();

		String tmp = lex.get();
		if (tmp.equals("-")) {
			lex.advance();
			String num2 = lex.get();
			lex.advance();
			return dash(num, num2);
		}

		if (tmp.equals("(")) {
			lex.advance();
			Value inside = parseExpr(lex);
			if (!lex.get().equals(")")) {
				throw new AssertionError();
			}
			lex.advance();
			return copy(num, inside);
		}

		return number(num);
	}

	void solve() throws IOException {
		String s = nextToken();
		Lexer lex = new Lexer(s);
		out.println(parseExpr(lex).rem);
	}

	static final String NUMBERS_CHARS = "0123456789";

	static class Lexer {
		String s;
		int ptr = 0;

		String curLex;

		public Lexer(String s) {
			this.s = s;
			advance();
		}

		String get() {
			return curLex;
		}

		void advance() {
			if (ptr == s.length()) {
				curLex = "EOF";
				return;
			}
			if (NUMBERS_CHARS.indexOf(s.charAt(ptr)) == -1) {
				curLex = s.substring(ptr, ptr + 1);
				ptr++;
				return;
			}
			int toPtr = ptr;
			while (toPtr < s.length()
					&& NUMBERS_CHARS.indexOf(s.charAt(toPtr)) != -1) {
				toPtr++;
			}
			curLex = s.substring(ptr, toPtr);
			ptr = toPtr;
			return;
		}
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}