import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 881917 + 10;
	
	HashMap<Integer, Integer> reach;
	
	void reachAdd(int x) {
		Integer prev = reach.get(x);
		if (prev == null)
			prev = 0;
		reach.put(x, prev + 1);
	}
	
	void reachRemove(int x) {
		Integer prev = reach.get(x);
		if (prev == 1)
			reach.remove(x);
		else
			reach.put(x, prev - 1);
	}

	void solve() throws IOException {
		int n = nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();

		Random rng = new Random();

		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			long tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);

		int[] gr = new int[N];
		long ceil4 = 2;
		long floor2 = 2;
		long curLow = 4;

		reach = new HashMap<>();
		reachAdd(gr[2]);
		int curMex = 1;

		int ptr = 0;
		int xor = 0;
		while (ptr < n && a[ptr] < 4)
			ptr++;

		while (ptr < n) {
			long ceil4Change = ceil4 * ceil4 * ceil4 * ceil4 + 1;
			long floor2Change = (floor2 + 1) * (floor2 + 1);
			long curHigh = Math.min(ceil4Change, floor2Change) - 1;
			
			if (curLow < N) {
				for (int i = (int) curLow; i <= curHigh && i < N; i++)
					gr[i] = curMex;
			}
			
//			System.err.println(curLow + " " + curHigh);
//			System.err.println(ceil4 + " " + floor2);
//			System.err.println();
			
			while (ptr < n && a[ptr] <= curHigh) {
				xor ^= curMex;
				ptr++;
			}
			if (ceil4Change <= floor2Change) {
				reachRemove(gr[(int) ceil4]);
				ceil4++;
			}
			if (floor2Change <= ceil4Change) {
				reachAdd(gr[(int)floor2 + 1]);
				floor2++;
			}
			curLow = curHigh + 1;
			curMex = 0;
			while (reach.containsKey(curMex))
				curMex++;
		}
		
		out.println(xor != 0 ? "Furlo" : "Rublo");
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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