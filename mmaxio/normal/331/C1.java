import java.io.*;
import java.util.*;

public class C2 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int mod = 1_000_000;

	void solve(long n) {
		int[] bigDigit = new int[mod];
		for (int i = 0; i < mod; i++) {
			int val = 0;
			int tmp = i;
			while (tmp > 0) {
				val = Math.max(val, tmp % 10);
				tmp /= 10;
			}
			bigDigit[i] = val;
		}
		
		int[][] cnt = new int[10][mod];
		int[][] decr = new int[10][mod];
		
		cnt[0][0] = 0;
		decr[0][0] = 0;
		
		for (int has = 0; has < 10; has++) {
			int[] cntHas = cnt[has];
			int[] decrHas = decr[has];
			for (int i = has == 0 ? 1 : 0; i < mod; i++) {
				int next = i - Math.max(has, bigDigit[i]);
				if (next < 0) {
					cntHas[i] = 1;
					decrHas[i] = next;
				} else {
					cntHas[i] = cntHas[next] + 1;
					decrHas[i] = decrHas[next];
				}
			}
		}
		
		long ans = 0;
		
		if (n == (long)mod * mod) {
			ans++;
			n--;
		}

		int part1 = (int) (n / mod);
		int part2 = (int) (n % mod);
		
		
		
		while (part1 >= 0) {
			int has = bigDigit[part1];
			ans += cnt[has][part2];
			
			part2 = mod + decr[has][part2];
			part1--;
		}
		
		out.println(ans);
	}

	C2() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve(nextLong());
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C2();
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