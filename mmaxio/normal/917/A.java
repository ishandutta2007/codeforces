import java.io.*;
import java.util.*;

public class A {

	String rand(int n) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append("()?".charAt(rand(0, 2)));
		}
		return sb.toString();
	}
	
	static final int INF = Integer.MAX_VALUE / 3;
	
	void submit() {
		String s = nextToken();
//		String s = rand(5000);
		int n = s.length();
		
		byte[][] ans = new byte[n][n];
		
		int[] minVal = new int[n + 1];
		
		for (int i = 0; i < n; i++) {
			
			Arrays.fill(minVal, INF);
			minVal[0] = 0;
			
			int bal = 0;
			int wild = 0;
			for (int j = i; j < n; j++) {
				char c = s.charAt(j);
				if (c == '(') {
					bal++;
				} else if (c == ')') {
					bal--;
				} else if (c == '?') {
					wild++;
				}
				
				if (wild > 0) {
					minVal[wild] = Math.min(minVal[wild], minVal[wild - 1]);
				}
				
				minVal[wild] = Math.min(minVal[wild], bal + wild);
				
				if ((j - i) % 2 == 0) {
					continue;
				}
				
				if (bal - wild <= 0 && bal + wild >= 0) {
					int x = (wild - bal) / 2;
					if (minVal[x] >= 0) {
						ans[i][j] |= 1;
					}
				}
			}
		}
		
		for (int i = n - 1; i >= 0; i--) {
			
			Arrays.fill(minVal, INF);
			minVal[0] = 0;
			
			int bal = 0;
			int wild = 0;
			for (int j = i; j >= 0; j--) {
				char c = s.charAt(j);
				if (c == ')') {
					bal++;
				} else if (c == '(') {
					bal--;
				} else if (c == '?') {
					wild++;
				}
				
				if (wild > 0) {
					minVal[wild] = Math.min(minVal[wild], minVal[wild - 1]);
				}
				
				minVal[wild] = Math.min(minVal[wild], bal + wild);
				
				if ((j - i) % 2 == 0) {
					continue;
				}
				
				if (bal - wild <= 0 && bal + wild >= 0) {
					int x = (wild - bal) / 2;
					if (minVal[x] >= 0) {
						ans[j][i] |= 2;
					}
				}
			}
		}
		
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (ans[i][j] == 3) {
					ret++;
				}
			}
		}
		
		out.println(ret);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}