import java.io.*;
import java.util.*;

public class D_nice {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int BOUND = 50_000_000;

	void solve() throws IOException {
		int n = nextInt();
		double[] p = new double[n];
		double[] q = new double[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			p[i] = x * 0.01;
			q[i] = (100 - x) * 0.01;
		}
		
		double[] qPow = new double[n];
		double pWin = 1;
		for (int i = 0; i < n; i++) {
			qPow[i] = q[i];
			pWin *= 1 - qPow[i];
		}
		
		double exp = n;
		
		for (int moves = n; ; moves++) {
			
			if (1 - pWin < 1e-11) {
				System.err.println(moves);
				break;
			}
			
			exp += 1 - pWin;
			
			double bestUpd = -1;
			int idx = 0;
			
			for (int i = 0; i < n; i++) {
				double upd = (1 - qPow[i] * q[i]) / (1 - qPow[i]);
				if (upd > bestUpd) {
					bestUpd = upd;
					idx = i;
				}
			}
			
			pWin *= bestUpd;
			qPow[idx] *= q[idx];
		}
		
		out.println(exp);
		
		
	}

	D_nice() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_nice();
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