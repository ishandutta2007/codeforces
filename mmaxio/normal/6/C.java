import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++)
			t[i] = nextInt();
		
		if (n == 1) {
			out.println("1 0");
			return;
		}
		
		int ansA = 0;
		int ansB = 0;
		
		int tA = t[0];
		int tB = t[n - 1];
		
		int l = 0;
		int r = n - 1;
		
		while (r - l > 1) {
			
			//System.err.println(l + " " + tA + " - " + r + " " + tB);
			
			int adv = Math.min(tA, tB);
			tA -= adv;
			tB -= adv;
			if (tA == 0)
				tA = t[++l];
			if (tB == 0)
				tB = t[--r];
		}
		
		out.println((l + 1) + " " + (n - l - 1));
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