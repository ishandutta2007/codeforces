import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		List<Long> str = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			str.add(sc.nextLong());
		}
		Collections.sort(str);
		List<Long> delta = new ArrayList<>();
		long last = -1;
		for (long val : str) {
			if (last != -1 && last != val) {
				delta.add(val - last);
			}
			last = val;
		}
		delta.add(1000000001L * 1000000001L);
		Collections.sort(delta);
		long[] dd = new long[delta.size()];
		for (int i = 0; i < dd.length; i++) {
			dd[i] = delta.get(i);
		}
		int q = sc.nextInt();
		long[] queries = new long[q];
		List<Long> qList = new ArrayList<>(q);
		for (int i = 0; i < queries.length; i++) {
			long tmp1 = sc.nextLong();
			long tmp2 = sc.nextLong();
			queries[i] = tmp2 - tmp1 + 1;
			qList.add(queries[i]);
		}
		Collections.sort(qList);
		Map<Long, Long> solutions = new HashMap<>();
		int idx = 0;
		long size = dd.length;
		long sum = 0;
		for (long qq : qList) {
			while (qq > dd[idx]) {
				sum += dd[idx++];
			}
			solutions.put(qq, sum + qq * (size - idx));
		}
		for (int i = 0; i < queries.length; i++) {
			out.println(solutions.get(queries[i]));
		}
		
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