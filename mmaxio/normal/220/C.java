import java.io.*;
import java.util.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 2;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		final int[] a = new int[n + 1];
		for (int i = 0; i < n; i++)
			a[nextInt() - 1] = i;
		final int[] b = new int[n + 1];
		for (int i = 0; i < n; i++)
			b[nextInt() - 1] = i;

		int[] nowChange = new int[n];
		for (int i = 0; i < n; i++)
			nowChange[b[i]] = i;
		
		TreeSet<Integer> set = new TreeSet<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (a[o1] - b[o1] != a[o2] - b[o2])
					return Integer.compare(a[o1] - b[o1], a[o2] - b[o2]);
				return Integer.compare(o1, o2);
			}
		});
		
		for (int i = 0; i < n; i++)
			set.add(i);
		
		for (int i = 0; i < n; i++) {
			int ans = INF;
			Integer low = set.lower(n);
			if (low != null)
				ans = Math.min(ans, -(a[low] - b[low] + i));
			
			Integer high = set.higher(n);
			if (high != null)
				ans = Math.min(ans, a[high] - b[high] + i);
			
			//System.err.println(low + " " + high);
			
			out.println(ans);
			
			int tmp = nowChange[i];
			set.remove(tmp);
			b[tmp] += n;
			set.add(tmp);
			
			b[n]++;
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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