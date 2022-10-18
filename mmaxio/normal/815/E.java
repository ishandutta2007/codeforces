import java.io.*;
import java.util.*;

public class E {

	TreeMap<Long, Long> getCount(long len) {
		TreeMap<Long, Long> ret = new TreeMap<>();
		ret.put(len, 1L);
		long prev = Long.MAX_VALUE;
		while (true) {
			Map.Entry<Long, Long> e = ret.lowerEntry(prev);
			long key = e.getKey();
			prev = key;
			long cnt = e.getValue();
			if (key <= 1) {
				break;
			}

			for (int z = 0; z < 2; z++) {
				long toKey = (key - z) / 2;
				if (toKey == 0) {
					break;
				}
				ret.merge(toKey, cnt, Long::sum);
			}
		}
		return ret;
	}

	long getDist(long len) {
		return (len - 1) / 2;
	}

	void submit() {
		long n = nextLong();
		long k = nextLong() - 1;
		if (k < 2) {
			out.println(k == 0 ? 1 : n);
			return;
		}

		k -= 2;

		TreeMap<Long, Long> lens = new TreeMap<>(Collections.reverseOrder());
		TreeMap<Long, Long> tmp = getCount(n - 2);
		for (Map.Entry<Long, Long> e : tmp.entrySet()) {
			long len = e.getKey();
			long cnt = e.getValue();
			lens.merge(getDist(len), cnt, Long::sum);
		}

		long whatDist = -1;
		for (Map.Entry<Long, Long> e : lens.entrySet()) {
			long dist = e.getKey();
			long cnt = e.getValue();
			if (k >= cnt) {
				k -= cnt;
			} else {
				whatDist = dist;
				break;
			}
		}

		if (whatDist == -1) {
			throw new AssertionError();
		}

		long l = 2;
		long r = n - 1;

		while (true) {
			long m = (l + r) >> 1;
			if (getDist(r - l + 1) == whatDist) {
				if (k == 0) {
					out.println(m);
					return;
				} else {
					k--;
				}
			}
			tmp = getCount(m - l);
			long leftDist = tmp.getOrDefault(2 * whatDist + 1, 0L)
					+ tmp.getOrDefault(2 * whatDist + 2, 0L);
			if (k >= leftDist) {
				k -= leftDist;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
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
		new E();
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