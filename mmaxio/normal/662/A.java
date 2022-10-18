import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static boolean test(long mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		long need = 0;
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			long x = nextLong();
			long y = nextLong();
			need ^= x;
			a[i] = x ^ y;
		}

		boolean[][] A = new boolean[60][n];
		boolean[] B = new boolean[60];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 60; j++) {
				A[j][i] = test(a[i], j);
			}
		}

		for (int i = 0; i < 60; i++) {
			B[i] = test(need, i);
		}
		
		int rank = 0;
		
		for (int j = 0; j < n; j++) {
			int row = -1;
			for (int i = rank; i < 60; i++) {
				if (A[i][j]) {
					row = i;
					break;
				}
			}
			if (row == -1) {
				continue;
			}
			boolean[] tmp1 = A[row];
			A[row] = A[rank];
			A[rank] = tmp1;
			
			boolean tmp2 = B[row];
			B[row] = B[rank];
			B[rank] = tmp2;
			
			for (int i = rank + 1; i < 60; i++) {
				if (A[i][j]) {
					for (int k = j; k < n; k++) {
						A[i][k] ^= A[rank][k];
					}
					B[i] ^= B[rank];
				}
			}
			rank++;
		}
		
		for (int i = rank; i < 60; i++) {
			if (B[i]) {
				out.println("1/1");
				return;
			}
		}
		
//		out.println("rank = " + rank);
		
		out.println(((1L << rank) - 1) + "/" + (1L << rank));
		
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