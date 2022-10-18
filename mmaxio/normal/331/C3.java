import java.io.*;
import java.util.*;

public class C3 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Pair {
		long longF;
		int intF;

		public Pair(long longF, int intF) {
			this.longF = longF;
			this.intF = intF;
		}

		@Override
		public int hashCode() {
			return (int) (longF ^ (longF >>> 32) ^ intF);
		}

		@Override
		public boolean equals(Object obj) {
			Pair other = (Pair) obj;
			return longF == other.longF && intF == other.intF;
		}

	}

	Map<Pair, Pair> memo = new HashMap<>();

	Pair go(Pair state) {
		
		Pair ret = memo.get(state);
		if (ret != null)
			return ret;

		if (state.longF < 10) {
			if (state.longF == 0 && state.intF == 0)
				ret = new Pair(0, 0);
			else
				ret = new Pair(1, Math.max((int) (state.intF - state.longF), 0));
			memo.put(state, ret);
			return ret;
		}

		long tmp = state.longF;
		long pow10 = 1;
		while (tmp >= 10) {
			tmp /= 10;
			pow10 *= 10;
		}

		int firstDigit = (int) tmp;
		Pair res1 = go(new Pair(state.longF - firstDigit * pow10, Math.max(
				state.intF, firstDigit)));
		
		Pair nextState = new Pair(firstDigit * pow10 - res1.intF, state.intF);
		
		Pair res2 = go(nextState);
		ret = new Pair(res1.longF + res2.longF, res2.intF);
		memo.put(state, ret);
		return ret;
	}

	long solve(long n) {
		return go(new Pair(n, 0)).longF;
	}

	C3() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve(nextLong()));  
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C3();
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