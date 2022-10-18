import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		final int[] a = new int[n];
		
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		Integer[] ord = new Integer[n];
		for (int i = 0; i < n; i++)
			ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(a[o1], a[o2]);
			}
		});
		
		TreeSet<Integer> setPos = new TreeSet<>();
		
		int ans = -1;
		
		for (int i = n - 1; i >= 0; i--) {
			int curPos = ord[i];
			
			Integer posBefore = setPos.lower(curPos);
			if (posBefore != null) {
				ans = Math.max(ans, a[curPos] ^ a[posBefore]);
			}
			
			Integer posAfter = setPos.higher(curPos);
			if (posAfter != null) {
				ans = Math.max(ans, a[curPos] ^ a[posAfter]);
			}
			
			setPos.add(curPos);
		}
		
		out.println(ans);
		
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