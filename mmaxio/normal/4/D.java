import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Envelope implements Comparable<Envelope> {
		int width;
		int height;
		int ind;

		public Envelope(int width, int height, int ind) {
			this.width = width;
			this.height = height;
			this.ind = ind;
		}

		@Override
		public int compareTo(Envelope o) {
			if (width != o.width)
				return width < o.width ? -1 : 1;
			if (height != o.height)
				return height > o.height ? -1 : 1;
			return Integer.compare(ind, o.ind);
		}
	}

	void solve() throws IOException {
		int n = nextInt();

		int w0 = nextInt();
		int h0 = nextInt();
		ArrayList<Envelope> a = new ArrayList<Envelope>();
		for (int i = 1; i <= n; i++) {
			Envelope cur = new Envelope(nextInt(), nextInt(), i);
			if (cur.width > w0 && cur.height > h0)
				a.add(cur);
		}
		Collections.sort(a);

		ArrayList<Integer> dp = new ArrayList<Integer>();
		ArrayList<Integer> aux = new ArrayList<Integer>();
		int[] prev = new int[a.size()];
		
		dp.add(0);
		aux.add(-1);
		
		for (int i = 0; i < a.size(); i++) {
			Envelope cur = a.get(i);
			int pos = Collections.binarySearch(dp, cur.height);
			if (pos >= 0)
				continue;
			pos = ~pos;
			if (pos == dp.size()) {
				dp.add(cur.height);
				aux.add(i);
			} else {
				dp.set(pos, cur.height);
				aux.set(pos, i);
			}
			
			prev[i] = aux.get(pos - 1);
		}
		
		out.println(dp.size() - 1);
		if (dp.size() != 0) {
			int[] ans = new int[dp.size() - 1];
			for (int i = ans.length - 1, cur = aux.get(aux.size() - 1); i >= 0; i--, cur = prev[cur])
				ans[i] = a.get(cur).ind;
			for (int i = 0 ; i < ans.length; i++)
				out.print(ans[i] + " ");
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
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