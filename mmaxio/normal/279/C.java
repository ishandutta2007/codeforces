import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		int[] toUp = new int[n];
		int[] toDown = new int[n];
		
		toUp[n - 1] = toDown[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] <= a[i + 1])
				toUp[i] = toUp[i + 1];
			else
				toUp[i] = i;
			if (a[i] >= a[i + 1])
				toDown[i] = toDown[i + 1];
			else
				toDown[i] = i;
		}
		
		while (q-- > 0) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			
			int end = toDown[toUp[l]];
			if (end >= r) {
				out.println("Yes");
			} else {
				out.println("No");
			}
		}
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