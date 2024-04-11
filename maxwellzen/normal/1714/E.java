import java.util.*;
import java.io.*;

public class E {
    public static long mod = 1000000007;

    public static void main(String[] args) {
        PrintWriter pr = new PrintWriter(System.out);
        FastScanner input = new FastScanner();
        int num = input.nextInt();

        for (int i = 0; i < num; i ++) {
            int n = input.nextInt();
            boolean[] b = new boolean[2];
            ArrayList<Integer> c = new ArrayList<Integer>();

            for (int k = 0; k < n; k ++) {
                int next = input.nextInt();
                if (next % 2 == 1) next += next % 10;

                if (next % 10 == 0) c.add(next);
                else {
                    next = next % 20;
                    if (next == 2 || next == 4 || next == 8 || next == 16) b[0] = true;
                    else b[1] = true;
                }
            }

            int hold = 0;
            for (int k = 0; k < 2; k ++) {
                if (b[k]) hold += 1;
            }

            if (hold == 1 && c.size() == 0) System.out.println("YES");
            else if (hold == 0 && same(c)) System.out.println("YES");
            else System.out.println("NO");
        }
    }

    public static boolean same(ArrayList<Integer> c) {
        for (int h = 0; h < c.size() - 1; h ++) {
            if (c.get(h).intValue() != c.get(h + 1).intValue()) return false;
        }
        return true;
    }

    public static class point implements Comparable<point> {
      public int x, y;
      public point(int x, int y) {
        this.x = x;
        this.y = y;
      }

      @Override public int compareTo(point a) {
        if (this.x > a.x) return 1;
        else if (this.x == a.x) return 0;
        else return -1;
      }
    }

    public static long modexp(long a, long b) { return modexp(a, b, mod); }
  	public static long modexp(long a, long b, long m) {
  		long res = 1;
  		while (b > 0) {
  			if (b % 2 != 0) res = (res * a) % m;
  			a = (a * a) % m;
  			b /= 2;
  		}
  		return res;
  	}

    public static long gcd(long a, long b) {
      if (a == 0) return b;
      else return gcd(b % a, a);
    }

    static class FastScanner {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer("");
      String next() {
        while (!st.hasMoreTokens())
            try { st = new StringTokenizer(br.readLine()); } catch (IOException e) { e.printStackTrace(); }
        return st.nextToken();
      }
      int nextInt() { return Integer.parseInt(next()); }
      int[] readArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i]=nextInt();
        return a;
      }
      long nextLong() { return Long.parseLong(next()); }
    }

}

  class Graph {
  	public int V;
  	public LinkedList<Integer> adj[];

  	@SuppressWarnings("unchecked") Graph(int v) {
  		V = v;
  		adj = new LinkedList[v];
  		for (int i = 0; i < v; i ++) adj[i] = new LinkedList();
  	}

  	void addEdge(int v, int w) { adj[v].add(w); }

  	void DFS(int v, boolean visited[]) {
  		visited[v] = true;
  		System.out.print(v + " ");

  		Iterator<Integer> i = adj[v].listIterator();
  		while (i.hasNext()) {
  			int n = i.next();
  			if (!visited[n]) DFS(n, visited);
  		}
  	}
  }