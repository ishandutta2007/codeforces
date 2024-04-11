import java.io.*;
import java.util.*;

public class BTCD2013_RANBOT {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Node {
		int vl, vr;
		int max;
		Node left, right;

		public Node(int vl, int vr) {
			this.vl = vl;
			this.vr = vr;
			max = Integer.MIN_VALUE;
			int mid = (vl + vr) >> 1;
			if (vl + 1 != vr) {
				left = new Node(vl, mid);
				right = new Node(mid, vr);
			}
		}

		void set(int pos, int val) {
			if (vl == pos && pos + 1 == vr) {
				max = val;
				return;
			}
			(pos < left.vr ? left : right).set(pos, val);
			max = Math.max(left.max, right.max);
		}

		int get(int minPos, int minVal) {
			if (vr <= minPos || max <= minVal)
				return -1;
			if (vl + 1 == vr) {
				return vl;
			}
			int ret = left.get(minPos, minVal);
			if (ret == -1)
				ret = right.get(minPos, minVal);
			return ret;
		}

	}

	TreeSet<Integer>[] sets;

	void solve() throws IOException {
		int n = nextInt();
		int[] type = new int[n];
		int[] x = new int[n];
		int[] y = new int[n];

		List<Integer> listX = new ArrayList<Integer>();

		for (int i = 0; i < n; i++) {
			String s = nextToken();
			x[i] = nextInt();
			y[i] = nextInt();
			if (s.equals("add")) {
				type[i] = 0;
				listX.add(x[i]);
			}
			if (s.equals("remove")) {
				type[i] = 1;
				listX.add(x[i]);
			}
			if (s.equals("find")) {
                                x[i]++;
				type[i] = 2;
			}
		}

		int[] allX = unique(listX);
		
		listX = null;
		int N = allX.length;
		
		if (N == 0) {
			for (int i = 0; i < n; i++) {
				out.println(-1);
			}
			return;
		}

		sets = new TreeSet[N];

		Node root = new Node(0, N);

		for (int i = 0; i < N; i++) {
			sets[i] = new TreeSet<Integer>();
		}

		for (int i = 0; i < n; i++) {
			x[i] = Arrays.binarySearch(allX, x[i]);
			if (x[i] < 0) {
				if (type[i] != 2) {
					throw new AssertionError();
				}
				x[i] = ~x[i];
			}
			if (type[i] == 0) {
				sets[x[i]].add(y[i]);
				int val = sets[x[i]].last();
				root.set(x[i], val);
			}
			if (type[i] == 1) {
				if (!sets[x[i]].remove(y[i]))
					throw new AssertionError();
				int val = sets[x[i]].isEmpty() ? Integer.MIN_VALUE : sets[x[i]]
						.last();
				root.set(x[i], val);
			}
			if (type[i] == 2) {
				if (x[i] == N) {
					out.println(-1);
					continue;
				}
				int ansX = root.get(x[i], y[i]); // strictly greater!
				if (ansX == -1) {
					out.println(-1);
				} else {
					out.println(allX[ansX] + " " + sets[ansX].higher(y[i]));
				}
			}
		}
	}

	int[] unique(List<Integer> a) {
                if (a.isEmpty()) {
                    return new int[0];
                }
		Collections.sort(a);
		int sz = 1;
		for (int i = 1; i < a.size(); i++) {
			if (a.get(i).intValue() != a.get(sz - 1).intValue()) {
				a.set(sz++, a.get(i));
			}
		}

		int[] ret = new int[sz];
		for (int i = 0; i < sz; i++) {
			ret[i] = a.get(i);
		}

		return ret;
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new BTCD2013_RANBOT().inp();
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