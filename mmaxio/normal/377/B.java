import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Student implements Comparable<Student> {
		int level;
		int need;
		int ind;

		public Student(int level, int need, int ind) {
			this.level = level;
			this.need = need;
			this.ind = ind;
		}

		@Override
		public int compareTo(Student o) {
			return -Integer.compare(level, o.level);
		}

	}

	static class Bug implements Comparable<Bug> {
		int level;
		int ind;

		public Bug(int level, int ind) {
			this.level = level;
			this.ind = ind;
		}

		@Override
		public int compareTo(Bug o) {
			return -Integer.compare(level, o.level);
		}
	}

	static Comparator<Student> byCost = new Comparator<Student>() {

		@Override
		public int compare(Student o1, Student o2) {
			if (o1.need != o2.need)
				return Integer.compare(o1.need, o2.need);
			return Integer.compare(o1.ind, o2.ind);
		}
	};

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int s = nextInt();

		Bug[] b = new Bug[m];
		for (int i = 0; i < m; i++) {
			b[i] = new Bug(nextInt(), i);
		}

		int[] tmpArr0 = new int[n];
		int[] tmpArr1 = new int[n];
		for (int i = 0; i < n; i++) {
			tmpArr0[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			tmpArr1[i] = nextInt();
		}

		Student[] a = new Student[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Student(tmpArr0[i], tmpArr1[i], i);
		}

		Arrays.sort(a);
		Arrays.sort(b);

		if (a[0].level < b[0].level) {
			out.println("NO");
			return;
		}

		int low = 0; // can
		int high = m + 1; // can't

		PriorityQueue<Student> q = new PriorityQueue<>(n, byCost);
		
		int[] ans = null;
		int[] tmpAns = new int[m];

		while (low + 1 < high) {

			int mid = (low + high) >> 1;

			q.clear();

			int stPtr = 0;

			long need = 0;

			outer: for (int i = 0; i < m; i += mid) {
				while (stPtr < n && a[stPtr].level >= b[i].level) {
					q.add(a[stPtr++]);
				}
				if (q.isEmpty()) {
					need = s + 1;
					continue outer;
				}
				Student cur = q.poll();
				need += cur.need;
				for (int j = i; j < i + mid && j < m; j++) {
					tmpAns[b[j].ind] = cur.ind + 1;
				}
			}
			
			if (need <= s) {
				ans = tmpAns.clone();
				high = mid;
			} else {
				low = mid;
			}
		}
		
		if (ans == null) {
			out.println("NO");
			return;
		}
		out.println("YES");
		for (int i = 0; i < m; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
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