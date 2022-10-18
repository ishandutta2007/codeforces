import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		long n = nextLong();
		
		BigInteger bigDoubleN = BigInteger.valueOf(n << 1);
		
		List<Long> ans = new ArrayList<>();
		
		for (long mult = 1; mult - 1 <= n; mult <<= 1) {
			BigInteger P = BigInteger.valueOf((mult << 1) - 3);
			
			long low = 0; // <
			long high = 2_000_000_000; // >=
			
			while (low < high - 1) {
				long q = (low + high) >> 1;
				BigInteger bigQ = BigInteger.valueOf(q);
			
				BigInteger val = bigQ.multiply(P.add(bigQ));
				if (val.compareTo(bigDoubleN) < 0) {
					low = q;
				} else {
					high = q;
				}
			}
			
			BigInteger bigHigh = BigInteger.valueOf(high);
			if (!bigHigh.testBit(0)) {
				continue;
			}
			BigInteger bigCand = bigHigh.multiply(BigInteger.valueOf(mult));
			if (bigHigh.multiply(bigHigh.add(P)).equals(bigDoubleN)) {
				ans.add(bigCand.longValue());
			}
		}
		
		if (ans.isEmpty()) {
			out.println(-1);
			return;
		}
		
		Collections.sort(ans);
		for (int i = 0; i < ans.size(); i++) {
			out.println(ans.get(i));
		}
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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