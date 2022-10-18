import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		long n = nextLong();
		if (n % 3 != 0) {
			out.println(0);
			return;
		}

		n /= 3;

		ArrayList<Long> divAL = new ArrayList<>();
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divAL.add(i);
				if (i * i != n)
					divAL.add(n / i);
			}
		}

		Collections.sort(divAL);

		long[] div = new long[divAL.size()];
		for (int i = 0; i < div.length; i++)
			div[i] = divAL.get(i);
		
		int ans = 0;
		for (int bigInd = 0; bigInd < div.length; bigInd++) {
			long big = div[bigInd];
			long rest = n / big;
			
			for (int smallInd = 0; smallInd <= bigInd; smallInd++) {
				long small = div[smallInd];
				if (small * small > rest)
					break;
				if (rest % small != 0)
					continue;
				long mid = rest / small;
				if (mid <= big && small + mid > big) {
					if (((big ^ mid ^ small) & 1) == 0) {
						
						if (big == mid && mid == small)
							ans++;
						else if (big == mid || mid == small)
							ans += 3;
						else
							ans += 6;
						
					}
				}
			}
		}
		out.println(ans);
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