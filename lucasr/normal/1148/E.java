import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		List<Stone> from = new ArrayList<>(n), to = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			from.add(new Stone(i + 1, tmp));
		}
		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			to.add(new Stone(i + 1, tmp));
		}
		Collections.sort(from, Comparator.comparingInt(s -> s.pos));
		Collections.sort(to, Comparator.comparingInt(s -> s.pos));
		List<Ans> ret = new ArrayList<>();
		int posI = -1, negI = -1;
		int remPos = 0, remNeg = 0;
		boolean can = true;
		while (can) {
			while (posI + 1 < n && remPos == 0) {
				posI++;
				if (from.get(posI).pos < to.get(posI).pos) {
					remPos = to.get(posI).pos - from.get(posI).pos;
				}
			}
			while (negI + 1 < n && remNeg == 0) {
				negI++;
				if (from.get(negI).pos > to.get(negI).pos) {
					remNeg = from.get(negI).pos - to.get(negI).pos;
				}
			}
			if (remPos > 0 && remNeg > 0) {
				if (posI < negI) {
					int move = Math.min(remPos, remNeg);
					ret.add(new Ans(from.get(posI).id, from.get(negI).id, move));
					remPos -= move;
					remNeg -= move;
				} else {
					can = false;
				}
			} else if (remPos == 0 && remNeg == 0) {
				break;
			} else {
				can = false;
			}
		}
		if (can) {
			out.println("YES");
			out.println(ret.size());
			for (Ans ans : ret) {
				out.println(ans.i + " " + ans.j + " " + ans.d);
			}
		} else {
			out.println("NO");
		}
		
		out.flush();
	}
	
	static class Stone {
		int id, pos;
		
		public Stone(int id, int pos) {
			this.id = id;
			this.pos = pos;
		}
		
		@Override
		public String toString() {
			return pos + "";
		}
	}
	
	static class Ans {
		int i, j, d;
		
		public Ans(int i, int j, int d) {
			this.i = i;
			this.j = j;
			this.d = d;
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