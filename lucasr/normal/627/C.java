import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class B {
	
	static class Pair implements Comparable<Pair> {
		long from, to;

		public Pair(long from, long to) {
			this.from = from;
			this.to = to;
		}

		@Override
		public int compareTo(Pair o) {
			if (from != o.from) {
				return from < o.from ? -1 : 1;
			}
			if (to != o.to) {
				return to < o.to ? -1 : 1;
			}
			return 0;
		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long d = sc.nextLong();
		long n = sc.nextLong();
		int m = sc.nextInt();
		Pair[] stations = new Pair[m+1];
		stations[m] = new Pair(0, 0);
		for (int i = 0; i < m; i++) {
			int pos = sc.nextInt();
			stations[i] = new Pair(sc.nextLong(), pos);
		}
		Arrays.sort(stations);
		TreeSet<Pair> intervals = new TreeSet<Pair>();
		long ans = 0;
		for (int i = 0; i < stations.length; i++) {
			long f = stations[i].to;
			long t = Math.min(stations[i].to + n, d);
			long toPutf = f, toPutt = t;
			Pair prev = intervals.floor(new Pair(f, Long.MAX_VALUE));
			if (prev != null && prev.to >= f) {
				f = prev.to;
				toPutf = prev.from;
				toPutt = Math.max(toPutt, prev.to);
				intervals.remove(prev);
			}
			Pair next = intervals.floor(new Pair(t, Long.MAX_VALUE));
			if (next != null && next.from >= f) {
				t = next.from;
				toPutt = Math.max(toPutt, next.to);
				intervals.remove(next);
			}
			if (f < t) ans += stations[i].from * (t-f);
			intervals.add(new Pair(toPutf, toPutt));
		}
		if (intervals.size() == 1 && intervals.first().from == 0 && intervals.first().to == d) {
			System.out.println(ans);
		} else {
			System.out.println(-1);
		}
	}
}