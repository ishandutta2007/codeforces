import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		BigInteger onesA = BigInteger.ZERO;
		BigInteger phisA = BigInteger.ZERO;
		String s = nextToken();
		for (int i = 0; i < s.length(); i++) {
			BigInteger newOnesA = phisA;
			phisA = phisA.add(onesA);
			onesA = newOnesA;
			if (s.charAt(i) == '1') {
				onesA = onesA.add(BigInteger.ONE);
			}
		}
		s = nextToken();
		BigInteger onesB = BigInteger.ZERO;
		BigInteger phisB = BigInteger.ZERO;
		for (int i = 0; i < s.length(); i++) {
			BigInteger newOnesB = phisB;
			phisB = phisB.add(onesB);
			onesB = newOnesB;
			if (s.charAt(i) == '1') {
				onesB = onesB.add(BigInteger.ONE);
			}
		}

		BigInteger ones = onesA.subtract(onesB);
		BigInteger phis = phisA.subtract(phisB);

		BigInteger just = ones.shiftLeft(1).add(phis);
		BigInteger sqrt5 = phis;

		int signJust = just.signum();
		int signSqrt5 = sqrt5.signum();
		if (signJust == 0 && signSqrt5 == 0) {
			out.println("=");
			return;
		}
		if (signJust >= 0 && signSqrt5 >= 0) {
			out.println(">");
			return;
		}
		if (signJust <= 0 && signSqrt5 <= 0) {
			out.println("<");
			return;
		}

		sqrt5 = sqrt5.negate();
		boolean neg = just.signum() < 0;
		boolean ret = (just.pow(2).compareTo(
				sqrt5.pow(2).multiply(BigInteger.valueOf(5))) > 0)
				^ neg;
		out.println(ret ? ">" : "<");
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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