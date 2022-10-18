import java.io.*;
import java.util.*;

public class B {

//	interface Interactor {
//		int[] getNMC();
//
//		int putWhere(int x);
//	}
//
//	static final int C = 5;

//	class LocalInteractor implements Interactor {
//
//		int n, m, c;
//
//		int qry;
//		
//		@Override
//		public int[] getNMC() {
//			int n = rand(2, C);
//			int c = rand(1, C);
//			int m = n * ((c + 1) / 2);
//			return new int[] { n, m, c };
//		}
//
//		@Override
//		public int putWhere(int x) {
//			
//		}
//
//	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int c = nextInt();
		
		int[] arr = new int[n];
		Arrays.fill(arr, -1);
		
		int firstHalf = c / 2;
		
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int where;
			if (x < firstHalf) {
				where = 0;
				while (arr[where] != -1 && x >= arr[where]) {
					where++;
				}
			} else {
				where = n - 1;
				while (arr[where] != -1 && x <= arr[where]) {
					where--;
				}
			}
			arr[where] = x;
			out.println(where + 1);
			out.flush();
			
			boolean allDone = true;
			for (int z : arr) {
				allDone &= z != -1;
			}
			
			if (allDone) {
				return;
			}
			
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
		// stress();
		// test();
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