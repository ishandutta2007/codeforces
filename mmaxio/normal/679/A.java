import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int count = 0;

	boolean isDivisor(int x) {
		count++;
		out.println(x);
		out.flush();
		String res = nextToken();
		return res.equals("yes");
	}

	void ansPrime() {
		out.println("prime");
//		out.println("!" + count);
		out.flush();
	}

	void ansComposite() {
		out.println("composite");
//		out.println("!" + count);
		out.flush();
	}

	void solve() throws IOException {
		int[] tmp = { 2, 3, 5, 7 };

		int cnt = 0;
		int div = -1;

		for (int i = 0; i < 4; i++) {
			boolean good = isDivisor(tmp[i]);
			if (good) {
				cnt++;
				div = tmp[i];
			}
		}

		if (cnt == 0) {
			ansPrime();
			return;
		}

		if (cnt > 1) {
			ansComposite();
			return;
		}

		if (div != 2) {

			for (int i = 2; i <= 100; i++) {
				if (i == div) {
					continue;
				}
				boolean cand = true;
				for (int j = 0; j < 4; j++) {
					cand &= (i % tmp[j] == 0) == (div == tmp[j]);
				}
				if (!cand) {
					continue;
				}
				if (isDivisor(i)) {
					ansComposite();
					return;
				}
			}
			ansPrime();
			return;
		}
		
		if (isDivisor(4)) {
			ansComposite();
			return;
		}
		
		for (int i = 2; i <= 100; i++) {
			if (i == div || i % 4 == 0) {
				continue;
			}
			boolean cand = true;
			for (int j = 0; j < 4; j++) {
				cand &= (i % tmp[j] == 0) == (div == tmp[j]);
			}
			if (!cand) {
				continue;
			}
			if (isDivisor(i)) {
				ansComposite();
				return;
			}
		}
		ansPrime();
		return;

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