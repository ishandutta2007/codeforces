import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long P = 1_000_000_009;

	static class Coord {

		int x, y;

		public Coord(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			return x * 10000010 + y;
		}

		@Override
		public boolean equals(Object obj) {
			Coord other = (Coord) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		Coord[] a = new Coord[n];
		HashMap<Coord, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			a[i] = new Coord(nextInt(), nextInt());
			map.put(a[i], i);
		}

		Coord seeker = new Coord(-1, -1);

		List<Integer>[] below = new List[n];
		for (int i = 0; i < n; i++) {
			below[i] = new ArrayList<>(3);
		}

		for (int i = 0; i < n; i++) {
			int x = a[i].x;
			int y = a[i].y;
			if (y != 0) {
				for (int cx = x - 1; cx <= x + 1; cx++) {
					seeker.x = cx;
					seeker.y = y - 1;
					Integer id = map.get(seeker);
					if (id != null) {
						below[i].add(id);
					}
				}
			}
		}

		boolean[] inQ = new boolean[n];
		Arrays.fill(inQ, true);
		for (int i = 0; i < n; i++) {
			if (below[i].size() == 1) {
				inQ[below[i].get(0)] = false;
			}
		}

		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			if (inQ[i]) {
				set.add(i);
			}
		}

		long ret = 0;

		for (int i = 0, move = 1; i < n; i++, move *= -1) {
			Integer now;
			if (move == 1) {
				now = set.last();
			} else {
				now = set.first();
			}
			
//			System.err.println(now + " " + Arrays.toString(below) + " " + set);
			set.remove(now);
			
			ret = (ret * n + now) % P;
			int x = a[now].x;
			int y = a[now].y;

			map.remove(a[now]);

			for (int cx = x - 1; cx <= x + 1; cx++) {
				seeker.x = cx;
				seeker.y = y + 1;
				Integer id = map.get(seeker);
				if (id != null) {
					below[id].remove(now);
					if (below[id].size() == 1) {
						set.remove(below[id].get(0));
					}
				}
			}

			for (int cx = x - 1; cx <= x + 1; cx++) {
				seeker.x = cx;
				seeker.y = y - 1;
				Integer id = map.get(seeker);
				if (id != null) {
					below[id].remove(now);
					if (below[id].size() == 1) {
						set.remove(below[id].get(0));
					}
					boolean canAdd = true;
					for (int dx = cx - 1; dx <= cx + 1; dx++) {
						seeker.x = dx;
						seeker.y = y;
						Integer id2 = map.get(seeker);
						if (id2 != null) {
							if (below[id2].size() == 1) {
								canAdd = false;
							}
						}
					}
					if (canAdd) {
						set.add(id);
					}

				}
			}

		}
		
		out.println(ret);

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