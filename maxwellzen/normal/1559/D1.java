import java.util.*;
import java.io.*;

public class D1 {

	static FastScanner fs;

	public static void main(String[] args) {
		fs=new FastScanner();
		int T = 1;
		// T = fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			solve();
		}
	}

	public static void solve() {
		int n=fs.nextInt(), m1=fs.nextInt(), m2=fs.nextInt(), u, v;
		DSU d1 = new DSU(n), d2 = new DSU(n);
		for (int i = 0; i < m1; i++) {
			u = fs.nextInt()-1; v = fs.nextInt()-1;
			d1.unite(u, v);
		}
		for (int i = 0; i < m2; i++) {
			u = fs.nextInt()-1; v = fs.nextInt()-1;
			d2.unite(u, v);
		}
		ArrayList<int[]> ans = new ArrayList();
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < j; i++) {
				if (d1.same_set(i, j) || d2.same_set(i, j)) continue;
				ans.add(new int[]{i+1, j+1});
				d1.unite(i, j); d2.unite(i, j);
			}
		}
		System.out.println(ans.size());
		for (int[] p : ans) System.out.println("" + p[0] + " " + p[1]);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static class DSU {
		int[] e;
		DSU(int N) {
			e = new int[N];
			for (int i = 0; i < N; i++) e[i]=-1;
		}
		int rep(int a) {
			if (e[a]<0) return a;
			return e[a] = rep(e[a]);
		}
		int size(int a) { return -e[rep(a)]; }
		boolean same_set(int a, int b) { return rep(a)==rep(b); }
		boolean unite(int a, int b) {
			a = rep(a); b = rep(b);
			if (a==b) return false;
			if (e[a]<e[b]) {
				e[a] += e[b];
				e[b] = a;
			} else {
				e[b] += e[a];
				e[a] = b;
			}
			return true;
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}


}