import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		final int[] a = new int[n];
		long[] sum = new long[n + 1];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sum[i + 1] = sum[i] + Math.max(a[i], 0);
		}
		
		Integer[] pos = new Integer[n];
		for (int i = 0; i < n; i++) {
			pos[i] = i;
		}
		
		Arrays.sort(pos, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (a[o1] != a[o2]) {
					return Integer.compare(a[o1], a[o2]);
				}
				return o1.compareTo(o2);
			}
			
		});
		
		long maxAns = Long.MIN_VALUE;
		int ansFrom = -1;
		int ansTo = -1;
		
		for (int i = 0; i < n; ) {
			int j = i + 1;
			while (j < n && a[pos[i]] == a[pos[j]])
				j++;
			if (j > i + 1) {
				int first = pos[i];
				int last = pos[j - 1];
				long curAns = 2 * a[first] + sum[last] - sum[first + 1];
				if (curAns > maxAns) {
					maxAns = curAns;
					ansFrom = first;
					ansTo = last;
				}
			}
			i = j;
		}
		
		out.print(maxAns + " ");
		boolean[] cut = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (i == ansFrom || i == ansTo)
				continue;
			if (i < ansFrom || i > ansTo)
				cut[i] = true;
			else
				cut[i] = a[i] < 0;
		}
		int cntCut = 0;
		for (int i = 0; i < n; i++)
			if (cut[i])
				cntCut++;
		
		out.println(cntCut);
		for (int i = 0; i < n; i++)
			if (cut[i]) {
				out.print(i + 1 + " ");
			}
		
		
		out.println();
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