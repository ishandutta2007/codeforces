import java.io.*;
import java.util.*;

public class A {

	static class Plane implements Comparable<Plane> {
		int cost;
		int id;
		
		@Override
		public int compareTo(Plane o) {
			return -Integer.compare(cost, o.cost);
		}

		public Plane(int cost, int id) {
			this.cost = cost;
			this.id = id;
		}
	}
	
	void submit() {
		int n = nextInt();
		int k = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		PriorityQueue<Plane> pq = new PriorityQueue<>();
		long cost = 0;
		
		long costInHeap = 0;
		
		for (int i = 0; i < k; i++) {
			pq.add(new Plane(a[i], i));
			costInHeap += a[i];
			
			cost += (long)(k - i) * a[i];
		}
		
		int[] ans = new int[n];
		
		for (int i = k; i < k + n; i++) {
			if (i < n) {
				pq.add(new Plane(a[i], i));
				costInHeap += a[i];
			}
			
			Plane fly = pq.poll();
			ans[fly.id] = i;
			costInHeap -= fly.cost;
			
			cost += costInHeap;
		}
		
		out.println(cost);
		for (int x : ans) {
			out.print((x + 1) + " ");
		}
		out.println();
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new A();
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