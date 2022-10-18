import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		for (int i = 0; i < n; i++)
			b[i] = nextInt();
		
		ArrayList<Integer> out1 = new ArrayList<Integer>();
		ArrayList<Integer> out2 = new ArrayList<Integer>();

		for (int i = 0; i < n; i++) {
			int need = a[i];
			int swap = i;
			while (b[swap] != need) swap++;
			for (int j = swap - 1; j >= i; j--) {
				//out.println((j + 1) + " " + (j + 2));
				out1.add(j + 1);
				out2.add(j + 2);
				int tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
				
		}
		
		out.println(out1.size());
		
		for (int i = 0; i < out1.size(); i++)
			out.println(out1.get(i) + " " + out2.get(i));
			
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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