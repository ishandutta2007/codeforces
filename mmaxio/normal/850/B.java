import java.io.*;
import java.util.*;

public class B {

	static final int N = 1_000_010;
	
	void submit() {
		int n = nextInt();
		int del = nextInt();
		int inc = nextInt();
		
		
		int len = del / inc;	
		
		int[] cnt = new int[N];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			cnt[x]++;
		}
		
		
		
		int[] prCnt = new int[N];
		long[] prSum = new long[N];
		
		for (int i = 1; i < N; i++) {
			prCnt[i] = prCnt[i - 1] + cnt[i];
			prSum[i] = prSum[i - 1] + (long)i * cnt[i];
		}
		
		PrimeRoutines pr = new PrimeRoutines(N);
		
		int[] primes = pr.p;
		
		long ans = Long.MAX_VALUE;
		
//		if (cnt[1] == n) {
//			ans = (long)(n - 1) * Math.min(inc, del) + inc;
//		} else {
//			ans = (long)(n - 1) * del;
//		}
		
		
		
		for (int p : primes) {
			
			int removeHere = n;
			long costHere = 0;
			
			for (int where = p; where - p < N; where += p) {
				
				int from = Math.max(where - len, where - p + 1);
				int to = Math.min(where, N - 1);
				
				if (from <= to) {
					
					int cntHere = prCnt[to] - prCnt[from - 1];
					long sumHere = prSum[to] - prSum[from - 1];
					
					removeHere -= cntHere;
					costHere += (long)where * cntHere - sumHere;
				}
				
			}
			
//			if (removeHere == n) {
//				continue;
//			}
			
			ans = Math.min(ans, (long)removeHere * del + costHere * inc);
		}
		
		out.println(ans);
		
	}
	
	public class PrimeRoutines {
		
		int[] lowDivIdx;
		int[] lowDiv;
		int[] p;
		int N;
		
		public PrimeRoutines(int N) {
			this.N = N;
			p = new int[(int)(N / Math.log(N))];
			lowDivIdx = new int[N + 1];
			lowDiv = new int[N + 1];
			Arrays.fill(lowDivIdx, -1);
			int pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (lowDivIdx[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					lowDivIdx[i] = pCnt;
					lowDiv[i] = i;
					p[pCnt++] = i;	
				}
				int toJ = Math.min(pCnt, lowDivIdx[i] + 1);
				for (int j = 0; j < toJ; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					lowDivIdx[x] = j;
					lowDiv[x] = p[j];
				}
			}
			p = Arrays.copyOf(p, pCnt); 
		}
		
		int[] divCount() {
			int[] ret = new int[N + 1];
			int[] tmp = new int[N + 1];
			ret[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p == lowDiv[j]) {
					int k = tmp[j];
					ret[i] = ret[j] / k * (k + 1);
					tmp[i] = k + 1;
				} else {
					ret[i] = ret[j] * 2;
					tmp[i] = 2;
				}
			}
			return ret;
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
				int p = lowDiv[i];
				int j = i / p;
				if (p != lowDiv[j]) {
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
				phi[i] = phi[j] * (p != lowDiv[j] ? p - 1 : p);
			}
			return phi;
		}
	}


	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
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
		new B();
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