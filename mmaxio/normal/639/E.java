import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Problem {
		int score, time;

		public Problem(int score, int time) {
			this.score = score;
			this.time = time;
		}

		long fstAC, lstAC;
	}

	static Comparator<Problem> byRatio = new Comparator<Problem>() {

		@Override
		public int compare(Problem o1, Problem o2) {
			// score / time > o.score / o.time ? -1 : 1
			long val1 = (long) o1.score * o2.time;
			long val2 = (long) o1.time * o2.score;
			return -Long.compare(val1, val2);
		}
	};

	static Comparator<Problem> byScore = new Comparator<Problem>() {

		@Override
		public int compare(Problem o1, Problem o2) {
			return Integer.compare(o1.score, o2.score);
		}
	};

	void solve() throws IOException {
		int n = nextInt();

		long T = 0;

		Problem[] set = new Problem[n];

		int[] sc = new int[n];
		int[] tme = new int[n];
		for (int i = 0; i < n; i++) {
			sc[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			tme[i] = nextInt();
			T += tme[i];
		}

		for (int i = 0; i < n; i++) {
			set[i] = new Problem(sc[i], tme[i]);
		}

		Arrays.sort(set, byRatio);

		long curTime = 0;

		for (int i = 0; i < n;) {
			int j = i;

			long deltaTime = 0;

			while (j < n && byRatio.compare(set[i], set[j]) == 0) {
				deltaTime += set[j].time;
				j++;
			}

			for (int k = i; k < j; k++) {
				set[k].fstAC = curTime + set[k].time;
				set[k].lstAC = curTime + deltaTime;
			}

			curTime += deltaTime;

			i = j;
		}

		Arrays.sort(set, byScore);

		double low = 0;
		double high = 1;

		outer: for (int it = 0; it < 100; it++) {
			double c = (low + high) * 0.5;
			// outer: for (int it = 0; it < 1; it++) {
			// double c = 0.7;
			double maxSoFar = -1e20;
			for (int i = 0; i < n;) {

				int j = i;
				while (j < n && set[i].score == set[j].score) {
					double val = set[j].score * (1 - c * set[j].lstAC / T);
					if (val < maxSoFar) {
						high = c;
						continue outer;
					}
					j++;
				}

				for (int k = i; k < j; k++) {
					maxSoFar = Math.max(maxSoFar, set[k].score
							* (1 - c * set[k].fstAC / T));
				}

				i = j;
			}
			low = c;
		}

		out.println((low + high) * 0.5);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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