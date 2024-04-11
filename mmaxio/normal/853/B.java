import java.io.*;
import java.util.*;

public class B {

	static class Flight {
		int day, cost;

		public Flight(int day, int cost) {
			this.day = day;
			this.cost = cost;
		}
	}
	
	void submit() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		
		ArrayList<Flight>[] fst = new ArrayList[n];
		ArrayList<Flight>[] snd = new ArrayList[n];
		
		for (int i = 0; i < n; i++) {
			fst[i] = new ArrayList<>();
			snd[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < m; i++) {
			int day = nextInt();
			int from = nextInt();
			int to = nextInt();
			int cost = nextInt();
			if (to == 0) {
				fst[from - 1].add(new Flight(day, cost));
			} else {
				snd[to - 1].add(new Flight(day, cost));
			}
		}
		
		Comparator<Flight> byDayIncr = new Comparator<Flight>() {
			
			@Override
			public int compare(Flight o1, Flight o2) {
				if (o1.day != o2.day) {
					return Integer.compare(o1.day, o2.day);
				}
				return Integer.compare(o1.cost, o2.cost);
			}
		};
		
		int startDay = Integer.MIN_VALUE;
		
		long[] deltaFst = new long[N];
		
		for (ArrayList<Flight> lst : fst) {
			if (lst.isEmpty()) {
				out.println(-1);
				return;
			}
			Collections.sort(lst, byDayIncr);
			
			int prevDay = -1, prevCost = Integer.MAX_VALUE;
			for (Flight f : lst) {
				if (f.cost >= prevCost) {
					continue;
				}
				if (prevDay == -1) {
					startDay = Math.max(startDay, f.day);
					deltaFst[f.day] += f.cost;
				} else {
					deltaFst[f.day] += f.cost - prevCost;
				}
				
				prevDay = f.day;
				prevCost = f.cost;
			}
		}
		
		
		Comparator<Flight> byDayDecr = new Comparator<Flight>() {
			
			@Override
			public int compare(Flight o1, Flight o2) {
				if (o1.day != o2.day) {
					return -Integer.compare(o1.day, o2.day);
				}
				return Integer.compare(o1.cost, o2.cost);
			}
		};
		
		int endDay = Integer.MAX_VALUE;
		
		long[] deltaSnd = new long[N];
		
		for (ArrayList<Flight> lst : snd) {
			if (lst.isEmpty()) {
				out.println(-1);
				return;
			}
			Collections.sort(lst, byDayDecr);
			
			int prevDay = -1, prevCost = Integer.MAX_VALUE;
			for (Flight f : lst) {
				if (f.cost >= prevCost) {
					continue;
				}
				if (prevDay == -1) {
					endDay = Math.min(endDay, f.day);
					deltaSnd[f.day] += f.cost;
				} else {
					deltaSnd[f.day] += f.cost - prevCost;
				}
				
				prevDay = f.day;
				prevCost = f.cost;
			}
		}
		
		for (int i = 1; i < N; i++) {
			deltaFst[i] += deltaFst[i - 1];
		}
		
		for (int i = N - 2; i >= 0; i--) {
			deltaSnd[i] += deltaSnd[i + 1];
		}
		
		long ans = Long.MAX_VALUE;
		
		for (int arrive = 0; arrive < N; arrive++) {
			int depart = arrive + k + 1;
			if (arrive < startDay || depart > endDay) {
				continue;
			}
//			System.err.println(arrive + " " + depart);
			
			ans = Math.min(ans, deltaFst[arrive] + deltaSnd[depart]);
		}
		
		out.println(ans == Long.MAX_VALUE ? -1 : ans);
		
	}
	
	static final int N = 1_001_000;

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
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
		new B();
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