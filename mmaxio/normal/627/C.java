import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Gas implements Comparable<Gas> {
		int x, cost;

		public Gas(int x, int cost) {
			this.x = x;
			this.cost = cost;
		}

		@Override
		public int compareTo(Gas o) {
			return Integer.compare(x, o.x);
		}
	}

	void solve() throws IOException {
		int d = nextInt();
		int vol = nextInt();
		int n = nextInt();

		Gas[] a = new Gas[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Gas(nextInt(), nextInt());
		}

		Arrays.sort(a);

		int[] stPos = new int[n + 1];
		int[] stCost = new int[n + 1];
		int size = 0;

		stPos[size] = 0;
		stCost[size] = 0;
		size++;

		/*
		 * 10 10 9 1 1 2 1 3 1 4 1 5 2 6 1 7 1 8 1 9 2
		 */

		int prev = 0;

		for (Gas g : a) {
			if (g.x - prev > vol) {
				out.println(-1);
				return;
			}

			if (stCost[size - 1] <= g.cost) {
				stCost[size] = g.cost;
				stPos[size] = prev + vol;
				size++;
			} else {

				while (size >= 0 && stCost[size - 1] >= g.cost
						&& stPos[size - 1] >= g.x) {
					size--;
				}

				stCost[size] = g.cost;
				if (stCost[size - 1] >= g.cost) {
					stPos[size] = g.x;
				}
				size++;
			}

			prev = g.x;

		}
		
//		10 10 3
//		4 10
//		5 8
//		8 19

		if (d - prev > vol) {
			out.println(-1);
			return;
		}

		long ret = 0;

		while (size >= 0 && stPos[size - 1] >= d) {
			size--;
		}

		prev = d;
		for (int i = size - 1; i >= 0; i--) {
			ret += (long) stCost[i] * (prev - stPos[i]);
			prev = stPos[i];
		}

		out.println(ret);

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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