import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		int[] b = a.clone();
		
		Random rng = new Random();
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = b[j];
			b[j] = b[i];
			b[i] = tmp; 
		}
		
		Arrays.sort(b);
		int diff = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i])
				diff++;
		}
		
		out.println(diff <= 2 ? "YES" : "NO");
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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