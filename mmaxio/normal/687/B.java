import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	public class PrimeRoutines {
		
		int[] lowDiv;
		int[] p = new int[1];
		
		int pCnt;
		
		int N;
		
		public PrimeRoutines(int N) {
			this.N = N;
			lowDiv = new int[N + 1];
			Arrays.fill(lowDiv, -1);
			pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (lowDiv[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					p[pCnt++] = i;
					lowDiv[i] = pCnt - 1;
				}
				for (int j = 0; j < pCnt && j <= lowDiv[i]; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					lowDiv[x] = j;
				}
			}
			p = Arrays.copyOf(p, pCnt); 
		}
		
		List<Integer> getDivsNotSorted(int x) {
			List<Integer> ret = new ArrayList<Integer>(0);
			ret.add(1);
			while (x > 1) {
				int sz = ret.size();
				int pr = lowDiv[x];
				while (lowDiv[x] == pr) {
					int to = ret.size();
					for (int i = ret.size() - sz; i < to; i++) {
						ret.add(ret.get(i) * pr);
					}
					x /= pr;
				}
			}
			return ret;
		}

		int[] moebiusFunction() {
			int[] mu = new int[N + 1];
			mu[1] = 1;
			for (int i = 2; i <= N; i++) {
				int j = i / lowDiv[i];
				if (lowDiv[i] != lowDiv[j]) {
					mu[i] = -mu[j];
				}
			}
			return mu;
		}

		int[] eulerFunction() {
			int[] phi = new int[N + 1];
			phi[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p != lowDiv[j]) {
					phi[i] = phi[j] * (p - 1);
				} else {
					phi[i] = phi[j] * p;
				}
			}
			return phi;
		}
	}


	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		PrimeRoutines pr = new PrimeRoutines(1_000_000);
		
		int[] kk = new int[pr.pCnt];
		while (k > 1) {
			kk[pr.lowDiv[k]]++;
			k /= pr.p[pr.lowDiv[k]];
		}
		
		int[] rest = new int[pr.pCnt];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			while (x > 1) {
				int curIdx = pr.lowDiv[x];
				int curP = pr.p[curIdx];
				
				int cnt = 0;
				
				while (pr.lowDiv[x] == curIdx) {
					cnt++;
					x /= curP;
				}
				
				rest[curIdx] = Math.max(rest[curIdx], cnt);
			}
		}
		
		for (int i = 0; i < pr.pCnt; i++) {
			if (rest[i] < kk[i]) {
				out.println("No");
				return;
			}
		}
		
		out.println("Yes");
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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