import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Task implements Comparable<Task> {
		int l, r, id;

		public Task(int l, int r, int id) {
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Task o) {
			if (l != o.l) {
				return l < o.l ? -1 : 1;
			}
			return Integer.compare(r, o.r);
		}
	}

	static class Worker implements Comparable<Worker> {
		int l, r, cap, id;

		public Worker(int l, int r, int cap, int id) {
			this.l = l;
			this.r = r;
			this.cap = cap;
			this.id = id;
		}

		@Override
		public int compareTo(Worker o) {
			if (r != o.r) {
				return r < o.r ? -1 : 1;
			}
			if (l != o.l) {
				return l < o.l ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		Task[] a = new Task[n];
		for (int i = 0; i < n; i++) {
			int l = nextInt();
			int r = nextInt();
			a[i] = new Task(l, r, i);
		}

		int m = nextInt();
		Worker[] b = new Worker[m];
		for (int i = 0; i < m; i++) {
			int l = nextInt();
			int r = nextInt();
			int cap = nextInt();
			b[i] = new Worker(l, r, cap, i);
		}

		Arrays.sort(a);

		Arrays.sort(b, new Comparator<Worker>() {

			@Override
			public int compare(Worker o1, Worker o2) {
				if (o1.l != o2.l) {
					return o1.l < o2.l ? -1 : 1;
				}
				return Integer.compare(o1.r, o2.r);
			}

		});

		TreeSet<Worker> set = new TreeSet<>();

		Worker seeker = new Worker(-1, -1, -1, -1);

		int[] ans = new int[n];

		for (int i = 0, j = 0; i < n; i++) {
			while (j < m && b[j].l <= a[i].l) {
				set.add(b[j++]);
			}
			seeker.l = -1;
			seeker.r = a[i].r;
			Worker use = set.higher(seeker);
			if (use == null) {
				out.println("NO");
				return;
			}

			ans[a[i].id] = use.id;
			use.cap--;
			if (use.cap == 0) {
				set.remove(use);
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + 1 + " " );
		}
		out.println();

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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