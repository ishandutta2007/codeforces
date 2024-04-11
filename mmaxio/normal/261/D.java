import java.io.*;
import java.util.*;

public class D_submit_fromcustomtest {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int tests = nextInt();
		int n = nextInt();
		int maxB = nextInt();
		int rep = nextInt();
		
		int[] a = new int[n];
		
		int[] map = new int[maxB];
		int mapVer = 0;
		
		int[] mapToSmall = new int[maxB];	
		
		int[] d = new int[maxB + 1];
		
		//long start = System.currentTimeMillis();
		
		testStart: while (tests-- > 0) {
			
			//long now = System.currentTimeMillis();
			//System.err.println("prev iteration took " + (now - start));
			//start = now;
			
			mapVer++;
			
			int cntDiff = 0;
			
			for (int i = 0; i < n; i++) {
				int x = a[i] = nextInt() - 1;
				if (map[x] != mapVer) {
					cntDiff++;
					map[x] = mapVer;
				}
			}
			
			if (rep >= cntDiff) {
				out.println(cntDiff);
				continue testStart;
			}
			
			for (int i = 0, j = 0; i < maxB; i++)
				if (map[i] == mapVer) {
					mapToSmall[i] = j++;
				}
			
//			System.err.println(Arrays.toString(mapToSmall));
			
			for (int i = 0; i < n; i++)
				a[i] = mapToSmall[a[i]];
			
			Arrays.fill(d, maxB);
			d[0] = -1;
			
			int curLen = 0;
			
			for (int i = 0; i < rep; i++) // now d[i] = i - 1 and never change again!
				for (int j = 0; j < n; j++) {
					int x = a[j];
					if (x < i)
						continue;
					
					int low = i; // d[low] < x
					int high = curLen + 1; // d[high] >= x
					while (low < high - 1) {
						int mid = (low + high) >> 1;
						if (d[mid] < x)
							low = mid;
						else
							high = mid;
					}
					d[high] = x;
					if (high == curLen + 1) {
						curLen++;
						if (curLen == cntDiff) {
							out.println(cntDiff);
							continue testStart;
						}
					}
				}
			out.println(curLen);
		}
	}

	D_submit_fromcustomtest() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_submit_fromcustomtest();
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