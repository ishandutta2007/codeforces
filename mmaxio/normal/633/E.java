import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int l, r;

		int min, max;
		Node left, right;

		public Node(int l, int r, int[] minArr, int[] maxArr) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, minArr, maxArr);
				right = new Node(mid, r, minArr, maxArr);
				min = Math.min(left.min, right.min);
				max = Math.max(left.max, right.max);
			} else {
				min = minArr[l];
				max = maxArr[r];
			}
		}

	}

	int get(int[] stack, int size, int x) {
		int low = -1; // > x
		int high = size - 1; // <= x

		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (stack[mid] <= x) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return stack[high];
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] maxs = new int[n];
		int[] mins = new int[n];
		for (int i = 0; i < n; i++) {
			maxs[i] = nextInt() * 100;
		}
		for (int i = 0; i < n; i++) {
			mins[i] = nextInt();
		}

		int[] stMax = new int[n];
		int szMax = 0;
		int[] stMin = new int[n];
		int szMin = 0;

		int[] value = new int[n];

		for (int i = n - 1; i >= 0; i--) {
			while (szMax > 0 && maxs[i] >= maxs[stMax[szMax - 1]]) {
				szMax--;
			}
			stMax[szMax++] = i;

			while (szMin > 0 && mins[i] <= mins[stMin[szMin - 1]]) {
				szMin--;
			}
			stMin[szMin++] = i;

			int low = i - 1; // min >= max
			int high = n; // min < max

			while (high - low > 1) {
				int mid = (low + high) >> 1;
				int midMax = maxs[get(stMax, szMax, mid)];
				int midMin = mins[get(stMin, szMin, mid)];
				if (midMin >= midMax) {
					low = mid;
				} else {
					high = mid;
				}
			}

			if (low >= i) {
				value[i] = Math.max(
						value[i],
						Math.min(maxs[get(stMax, szMax, low)],
								mins[get(stMin, szMin, low)]));
			}

			if (high < n) {
				value[i] = Math.max(
						value[i],
						Math.min(maxs[get(stMax, szMax, high)],
								mins[get(stMin, szMin, high)]));
			}
			
//			if (i == 0) {
//				System.err.println(Arrays.toString(stMax) + " " + szMax);
//				System.err.println(Arrays.toString(stMin) + " " + szMin);
//			}
			
			
			
//			int tmpMin = Integer.MAX_VALUE;
//			int tmpMax = Integer.MIN_VALUE;
//			int globalMax = Integer.MIN_VALUE;
//			for (int j = i; j < n; j++) {
//				tmpMax = Math.max(tmpMax, maxs[j]);
//				tmpMin = Math.min(tmpMin, mins[j]);
//				globalMax = Math.max(globalMax, Math.min(tmpMin, tmpMax));
//			}
//			
//			if (globalMax != value[i]) {
//				System.err.println(i + " " + globalMax + " " + value[i]);
//			}
//			
			
			
		}

//		System.err.println(Arrays.toString(value));
		Arrays.sort(value);
		

		double ret = 0;
		double p = 1.0 * k / n;
		for (int i = 0; i <= n - k; i++) {
//			System.err.println(p);
			ret += value[i] * p;
			p = p * (n - i - k) / (n - i - 1);
		}

		out.printf("%.20f\n", ret);

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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