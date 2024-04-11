import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	int[] sorted(int[] a) {
		a = a.clone();
		for (int i = 0; i < a.length; i++) {
			int j = rand(0, i);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		return a;
	}

	void solve(int[] a, int s) {
		int n = a.length;

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Arrays.sort(order, Comparator.comparingInt(x -> a[x]));

		int[] perm = new int[n];
		Arrays.fill(perm, -1);
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] == a[order[i]]) {
				perm[i] = i;
			} else {
				sum++;
			}
		}

		if (sum > s) {
			out.println(-1);
			return;
		}

		for (int i = 0, j1 = 0, j2 = 0; i < sum; i++) {
			while (perm[order[j1]] == order[j1]) {
				j1++;
			}
			while (perm[j2] == j2) {
				j2++;
			}
			perm[order[j1]] = j2;
			j1++;
			j2++;
		}

		p = new int[n];
		Arrays.fill(p, -1);
		for (int i = 0; i < n; i++) {
			for (int j = i; p[j] == -1; j = perm[j]) {
				p[j] = i;
			}
		}

		int lastIdx = -1, lastVal = -1;

		for (int i = 0; i < n; i++) {
			int idx = order[i];
			if (perm[idx] == idx) {
				continue;
			}
			if (a[idx] == lastVal) {
				int v = get(idx);
				int u = get(lastIdx);
				if (v != u) {
					p[u] = v;
					int tmp = perm[idx];
					perm[idx] = perm[lastIdx];
					perm[lastIdx] = tmp;
				}

			}

			lastVal = a[idx];
			lastIdx = idx;
		}

		ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();

		boolean[] used = new boolean[n];

		for (int i = 0; i < n; i++) {
			if (perm[i] == i || used[i]) {
				continue;
			}
			ArrayList<Integer> cycle = new ArrayList<>();
			for (int j = i; !used[j]; j = perm[j]) {
				used[j] = true;
				cycle.add(j);
			}
			cycles.add(cycle);
		}

		if (false) {
			int sumCycles = 0;
			for (List<Integer> lst : cycles) {
				sumCycles += lst.size();
			}
			if (sumCycles != sum) {
				throw new AssertionError();
			}
		}

		for (int merge = cycles.size(); merge >= 0; merge--) {
			if (merge == 1 || merge == 2) {
				continue;
			}

			int cost = sum + merge;
			if (cost > s) {
				continue;
			}

			int pop = cycles.size() - merge;
			out.println(pop + (merge > 0 ? 2 : 0));

			for (int i = 0; i < pop; i++) {
				ArrayList<Integer> cycle = cycles.remove(cycles.size() - 1);
				out.println(cycle.size());
				for (int x : cycle) {
					out.print(x + 1 + " ");
				}
				out.println();
			}

			if (cycles.isEmpty()) {
				return;
			}

			int total = 0;
			for (ArrayList<Integer> cycle : cycles) {
				total += cycle.size();
			}

			out.println(total);
			for (ArrayList<Integer> cycle : cycles) {
				for (int x : cycle) {
					out.print(x + 1 + " ");
				}
			}
			out.println();

			out.println(cycles.size());
			for (int i = cycles.size() - 1; i >= 0; i--) {
				out.print(cycles.get(i).get(0) + 1 + " ");
			}
			out.println();

			return;
		}

		throw new AssertionError();
	}

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	int[] p;

	void test() {
		solve(new int[] { 1, 1, 0, 0, 0 }, 5);
		// solve(new int[] { 1, 0, 0 }, 3);
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int s = rand(0, n);

			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(0, n - 1);
			}
			System.err.println(Arrays.toString(a) + " " + s);
			solve(a, s);

			System.err.println(tst);
		}
	}

	void submit() {
		int n = nextInt();
		int s = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		solve(a, s);
	}

	E() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}