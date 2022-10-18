import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	Random rng = new Random();
	
	void sort(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		sort(a);
		int ansCnt = 1;
		int ansNum = a[0];
		long sum = 0;
		
		for (int i = 1, j = 0; i < n; i++) {
			sum += (long)(i - j) * (a[i] - a[i - 1]);
			while (sum > k) {
				sum -= a[i] - a[j++];
			}
			if (i - j + 1 > ansCnt) {
				ansCnt = i - j + 1;
				ansNum = a[i];
			}
		}
		
		out.println(ansCnt + " " + ansNum);
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