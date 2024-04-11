import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] addL = new int[m];
		int[] addR = new int[m];
		int[] addD = new int[m];

		for (int i = 0; i < m; i++) {
			addL[i] = nextInt() - 1;
			addR[i] = nextInt() - 1;
			addD[i] = nextInt();
		}

		int[] qCnt = new int[m];
		for (int i = 0; i < k; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			qCnt[l]++;
			if (r != m - 1)
				qCnt[r + 1]--;
		}
		for (int i = 1; i < m; i++) {
			qCnt[i] += qCnt[i - 1];
		}

		long[] b = new long[n];
		for (int i = 0; i < m; i++) {
			long curAdd = (long) addD[i] * qCnt[i];
			b[addL[i]] += curAdd;
			if (addR[i] != n - 1) {
				b[addR[i] + 1] -= curAdd;
			}
		}
		
		for (int i = 1; i < n; i++) {
			b[i] += b[i - 1];
		}
		
		for (int i = 0; i < n; i++) {
			out.print(a[i] + b[i] + " ");
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