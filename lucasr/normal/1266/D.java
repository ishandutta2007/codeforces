import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		long[] debt = new long[N];
		for (int i = 0; i < M; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			long tmp = sc.nextLong();
			debt[a] += tmp;
			debt[b] -= tmp;
		}
		List<Debt> positive = new ArrayList<>();
		List<Debt> negative = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			if (debt[i] > 0) {
				positive.add(new Debt(i, debt[i]));
			}
			if (debt[i] < 0) {
				negative.add(new Debt(i, -debt[i]));
			}
		}
		int idxPos = 0, idxNeg = 0;
		List<Debt> ret = new ArrayList<>();
		List<Integer> who = new ArrayList<>();
		while (idxPos < positive.size()) {
			Debt pos = positive.get(idxPos);
			Debt neg = negative.get(idxNeg);
			long val = Math.min(pos.amount, neg.amount);
			if (val > 0) {
				ret.add(new Debt(pos.id, val));
				who.add(neg.id);
			}
			pos.amount -= val;
			neg.amount -= val;
			if (pos.amount == 0) {
				idxPos++;
			}
			if (neg.amount == 0) {
				idxNeg++;
			}
		}
		out.println(ret.size());
		for (int i = 0; i < ret.size(); i++) {
			Debt dd = ret.get(i);
			out.println((1 + dd.id) + " " + (1 + who.get(i)) + " " + dd.amount);
		}
		
		out.flush();
	}
	
	public static class Debt {
		int id;
		long amount;
		
		public Debt(int id, long amount) {
			this.id = id;
			this.amount = amount;
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