import java.io.*;
import java.util.*;

public class B_new {

	static class Dancer {
		int type;
		int x;
		int id;

		int initPos;

		public Dancer(int type, int x, int id) {
			this.type = type;
			this.x = x;
			this.id = id;
		}
	}

	int[] xs;
	int[] ys;
	
	int n, w, h;
	
	void go(ArrayList<Dancer> lst) {
		Collections.sort(lst, new Comparator<Dancer>() {

			@Override
			public int compare(Dancer o1, Dancer o2) {
				if (o1.type != o2.type) {
					return o1.type > o2.type ? -1 : 1;
				}
				if (o1.type == 2) {
					return -Integer.compare(o1.x, o2.x);
				} else {
					return Integer.compare(o1.x, o2.x);
				}
			}

		});

		for (int i = 0; i < lst.size(); i++) {
			lst.get(i).initPos = i;
		}

		Collections.sort(lst, new Comparator<Dancer>() {

			@Override
			public int compare(Dancer o1, Dancer o2) {
				if (o1.type != o2.type) {
					return o1.type < o2.type ? -1 : 1;
				}
				if (o1.type == 2) {
					return -Integer.compare(o1.x, o2.x);
				} else {
					return Integer.compare(o1.x, o2.x);
				}
			}

		});

		for (Dancer d : lst) {

			int endAt = d.initPos;

			Dancer dd = lst.get(endAt);

			int ansId = d.id;

			if (dd.type == 1) {
				xs[ansId] = dd.x;
				ys[ansId] = h;
			} else {
				xs[ansId] = w;
				ys[ansId] = dd.x;
			}

		}
	}
	
	void submit() {
		n = nextInt();
		w = nextInt();
		h = nextInt();

		
		HashMap<Integer, ArrayList<Dancer>> map = new HashMap<>();
		
		for (int i = 0; i < n; i++) {
			int type = nextInt();
			int x = nextInt();
			int time = nextInt();
			
			Dancer d = new Dancer(type, x, i);
			ArrayList<Dancer> lst = map.get(x - time);
			if (lst == null) {
				lst = new ArrayList<>();
				map.put(x - time, lst);
			}
			lst.add(d);
		}
		
		xs = new int[n];
		ys = new int[n];
		
		for (ArrayList<Dancer> lst : map.values()) {
			go(lst);
		}

		for (int i = 0; i < n; i++) {
			out.println(xs[i] + " " + ys[i]);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B_new() throws IOException {
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
		new B_new();
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