import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class G {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] vals = new int[m];
		int sum = 0;
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
			sum += vals[i];
		}
		int ans = (sum + n - 1) / n;
		int rem = ans * n - sum;
		vals[0] += rem;
		PriorityQueue<Elem> pq = new PriorityQueue<>();
		PriorityQueue<Elem> tmpPq = new PriorityQueue<>();
		for (int i = 0; i < m; i++) {
			if (vals[i] > 0) {
				pq.add(new Elem(vals[i], i, 1));
			}
		}
		int[][] ret = new int[m][ans];
		int[] sizes = new int[m];
		Elem cur = null;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < ans; j++) {
				Elem cur1 = pq.peek();
				Elem cur2 = tmpPq.peek();
				if (cur1 != null && (cur2 == null || cur1.compareTo(cur2) < 0)) {
					cur = pq.poll();
				} else {
					cur = tmpPq.poll();
				}
				sizes[i] = cur.total / cur.divBy;
				ret[i][j] = cur.index;
				cur.divBy++;
				tmpPq.add(cur);
			}
			if (sizes[i] <= 0) {
				throw new RuntimeException();
			}
			while (!tmpPq.isEmpty()) {
				Elem elem = tmpPq.poll();
				elem.divBy--;
				elem.total -= elem.divBy * sizes[i];
				elem.divBy = 1;
				if (elem.total > 0) {
					pq.add(elem);
				}
			}
			if (pq.isEmpty()) break;
		}
		out.println(ans);
		for (int i = 0; i < m; i++) {
			if (i > 0) out.print(" ");
			out.print(sizes[i]);
		}
		out.println();
		for (int i = 0; i < ans; i++) {
			for (int j = 0; j < m; j++) {
				if (j > 0) out.print(" ");
				out.print(ret[j][i] + 1);
			}
			out.println();
		}
		out.flush();
	}
	
	static class Elem implements Comparable<Elem> {
		private int total, index, divBy;
		
		public Elem(int total, int index, int divBy) {
			this.total = total;
			this.index = index;
			this.divBy = divBy;
		}
		
		@Override
		public int compareTo(Elem o) {
			return Integer.compare(o.total * divBy, total * o.divBy);
		}
		
		@Override
		public String toString() {
			return "Elem{" +
					"total=" + total +
					", index=" + index +
					", divBy=" + divBy +
					'}';
		}
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}