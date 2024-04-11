import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		List<Integer>[] votes = new List[m];
		for (int i = 0; i < m; i++) {
			votes[i] = new ArrayList<>();
		}
		int tmp, val;
		for (int i = 0; i < n; i++) {
			tmp = sc.nextInt() - 1;
			val = sc.nextInt();
			votes[tmp].add(val);
			
		}
		for (int i = 1; i < m; i++) {
			Collections.sort(votes[i]);
		}
		long ans = Long.MAX_VALUE;
		
		int[] index = new int[m];
		PriorityQueue<Integer> queue = new PriorityQueue<>((pos1, pos2) -> {
			return votes[pos1].get(index[pos1]).compareTo(votes[pos2].get(index[pos2]));
		});
		for (int i = 1; i <= (n + 1) / 2; i++) {
			queue.clear();
			int got = votes[0].size();
			long cost = 0;
			for (int j = 1; j < m; j++) {
				index[j] = Math.max(0, votes[j].size() - (i - 1));
				for (int k = 0; k < index[j]; k++) {
					cost += votes[j].get(k);
					got++;
				}
				if (index[j] < votes[j].size()) {
					queue.add(j);
				}
			}
			while (got < i) {
				int cur = queue.poll();
				got++;
				cost += votes[cur].get(index[cur]++);
				if (index[cur] < votes[cur].size()) {
					queue.add(cur);
				}
			}
			ans = Math.min(ans, cost);
		}
		
		out.println(ans);
		
		out.flush();
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