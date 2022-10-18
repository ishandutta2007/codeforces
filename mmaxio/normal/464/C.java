import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;
	static final int PHI = P - 1;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		int n = nextInt();
		int[] from = new int[n];
		String[] to = new String[n];
		for (int i = 0; i < n; i++) {
			String raw = nextToken();
			from[i] = raw.charAt(0) - '0';
			to[i] = raw.substring(3);
		}
		int[] len = new int[10];
		int[] val = new int[10];
		Arrays.fill(len, 1);
		for (int i = 0; i < 10; i++) {
			val[i] = i;
		}
		for (int i = n - 1; i >= 0; i--) {
			int dig = from[i];
			int newLen = 0;
			int newVal = 0;
			String newS = to[i];
			for (int j = 0; j < newS.length(); j++) {
				int x = newS.charAt(j) - '0';
				newLen += len[x];
				newLen %= PHI;
				newVal = (int) ((long) newVal * pow(10, len[x]) % P);
				newVal += val[x];
				newVal %= P;
			}
			len[dig] = newLen;
			val[dig] = newVal;
		}
		
		int ans = 0;
		for (int i = 0; i < s.length; i++) {
			int x = s[i] - '0';
			ans = (int)((long)ans * pow(10, len[x]) % P);
			ans += val[x];
			ans %= P;
		}
		out.println(ans);
	}

	static int pow(int a, int b) {
		int ret = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % P);
			}
			a = (int) ((long) a * a % P);
			b >>= 1;
		}
		return ret;
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