import java.io.*;
import java.util.*;

public class G {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	HashMap<String, Integer> memo;
	ArrayList<String> names;
	ArrayList<ArrayList<Integer>> g;
	
	int getV(String s) {
		Integer res = memo.get(s);
		if (res != null)
			return res;
		res = names.size();
		memo.put(s, res);
		names.add(s);
		g.add(new ArrayList<Integer>());
		return res;
	}

	void solve() throws IOException {
		int m = nextInt();
		memo = new HashMap<>();
		names = new ArrayList<>();
		g = new ArrayList<>();
		
		for (int i = 0; i < m; i++) {
			String name1 = nextToken();
			String name2 = nextToken();
			int v1 = getV(name1);
			int v2 = getV(name2);
			g.get(v1).add(v2);
			g.get(v2).add(v1);
		}
		
		int n = names.size();
		int[] cnt = new int[n];
		
		out.println(n);
		for (int i = 0; i < n; i++) {
			out.print(names.get(i) + " ");
			
			Arrays.fill(cnt, 0);
			cnt[i] = -1;
			for (int j = 0; j < g.get(i).size(); j++) {

				
				int v = g.get(i).get(j);
				
				//System.err.println(i + " " + v);
				cnt[v] = -1;
				
				for (int k = 0; k < g.get(v).size(); k++) {
					int v2 = g.get(v).get(k);
					if (v2 != i && cnt[v2] != -1)
						cnt[v2]++;
				}
				
			}
			
			int max = 0;
			int cntMax = 0;
			for (int j = 0; j < n; j++) {
				if (cnt[j] > max) {
					max = cnt[j];
					cntMax = 0;
				}
				if (cnt[j] == max)
					cntMax++;
			}
			out.println(cntMax);
		}
		
		
	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new G();
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