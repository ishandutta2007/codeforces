import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class F {
	
	static PrintWriter out;
	
	static class State {
		
		Pile[] piles = new Pile[3];
		int forb, rem;
		
		public State(Pile[] piles, int forb, int rem) {
			Arrays.sort(piles);
			long min = piles[0].value;
			for (int i = 0; i < 3; i++) {
				piles[i] = piles[i].inc(-min);
			}
			this.piles = piles;
			this.forb = forb;
			this.rem = rem;
		}
		
		State next(long y, int chosen) {
			if (!mayChose(chosen)) throw new RuntimeException();
			Pile[] next = new Pile[3];
			for (int i = 0; i < 3; i++) {
				next[i] = piles[i].inc(piles[i].id == chosen ? y : 0);
			}
			return new State(next, chosen, rem - 1);
		}
		
		boolean isEquals() {
			return piles[0].value == piles[1].value || piles[1].value == piles[2].value;
		}
		
		boolean mayChose(int pos) {
			return pos != forb;
		}
		
		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			
			State state = (State) o;
			
			if (forb != state.forb) return false;
			if (rem != state.rem) return false;
			return Arrays.equals(piles, state.piles);
		}
		
		@Override
		public int hashCode() {
			int result = Arrays.hashCode(piles);
			result = 31 * result + forb;
			result = 31 * result + rem;
			return result;
		}
		
		@Override
		public String toString() {
			return "State{" +
					"piles=" + Arrays.toString(piles) +
					", forb=" + forb +
					", rem=" + rem +
					'}';
		}
	}
	
	static Map<State, Integer> wins = new HashMap<>();
	static Map<State, List<Integer>> yy = new HashMap<>();
	
	static int calc(State st) {
		Integer ret = wins.get(st);
		if (ret != null) return ret;
		if (st.isEquals()) {
			return 0;
		}
		if (st.rem <= 0) {
			return 1000000;
		}
		
		java.util.List<Integer> bbb = new ArrayList<>();
		int min = Integer.MAX_VALUE;
		for (int y = 1; y < 20; y++) {
			//winsFirst = true;
			int max = -1;
			for (int pos = 1; pos <= 3; pos++) {
				if (st.mayChose(pos)){
					int val = calc(st.next(y, pos));
					max = Math.max(max, val);
				}
			}
			if (max <= min) {
				if (max < min) {
					bbb = new ArrayList<>();
				}
				min = max;
				bbb.add(y);
			}
		}
		yy.put(st, bbb);
		ret = min + 1;
//		ret = winsFirst ? 1 : 2;
//		if (!winsFirst) {
//			//System.err.println(st + " ==> second ");
//		}
		wins.put(st, ret);
		return ret;
	}
	
	static class Pile implements Comparable<Pile> {
		int id;
		long value;
		
		public Pile(int id, long value) {
			this.id = id;
			this.value = value;
		}
		
		Pile inc(long v) {
			return new Pile(id, value + v);
		}
		
		@Override
		public int compareTo(Pile o) {
			return Long.compare(value, o.value);
		}
		
		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			
			Pile pile = (Pile) o;
			
			if (id != pile.id) return false;
			return value == pile.value;
		}
		
		@Override
		public int hashCode() {
			int result = id;
			result = 31 * result + (int) (value ^ (value >>> 32));
			return result;
		}
		
		@Override
		public String toString() {
			return "Pile{" +
					"id=" + id +
					", value=" + value +
					'}';
		}
	}
	
	
	
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(System.out);
		Pile[] piles = new Pile[3];
		for (int i = 0; i < 3; i++) {
			long tmp = sc.nextLong();
			piles[i] = new Pile(i + 1, tmp);
		}
		State st = new State(piles, 0, 1000);
		print("First");
		
		long next = st.piles[1].value + st.piles[2].value;
		print(next + "");
		int pos = sc.nextInt();
		if (pos == 0) return;
		st = st.next(next, pos);
		
		next = -st.piles[1].value + 2 * st.piles[2].value;
		print(next + "");
		pos = sc.nextInt();
		if (pos == 0) return;
		st = st.next(next, pos);
		
		next = st.piles[1].value;
		print(next + "");
		pos = sc.nextInt();
		if (pos == 0) return;
		
	}
	
	static void print(String a) {
		out.println(a);
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