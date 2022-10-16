import java.io.*;
import java.util.*;

public class graphcoloring {
  private static InputReader in;
  private static PrintWriter out;
  
  public static ArrayList<Integer>[] rg, bg;
  public static int n;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    n = in.nextInt();
    int m = in.nextInt();
    rg = new ArrayList[n];
    bg = new ArrayList[n];
    ArrayList<Edge> f1 = new ArrayList<>();
    ArrayList<Edge> f2 = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      rg[i] = new ArrayList<>();
      bg[i] = new ArrayList<>();
    }
    for (int i = 0; i < m; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      char c = in.next().charAt(0);
      if (c == 'R') {
        rg[a].add(b);
        rg[b].add(a);
        f1.add(new Edge(a,b));
      } else {
        bg[a].add(b);
        bg[b].add(a);
        f2.add(new Edge(a,b));
      }
    }
    a1 = f1; a2 = f2;
    ArrayList<Integer> s = solve();
    a1 = f2; a2 = f1;
    ArrayList<Integer> t = solve();
    if (s == null && t == null) {
      out.println(-1);
    } else {
      ArrayList<Integer> ret = (s == null || (t != null && s.size() > t.size())) ? t : s;
      
      out.println(ret.size());
      for (int i = 0; i < ret.size(); i++) {
        if (i != 0) out.print(" ");
        out.print(ret.get(i));
      }
      out.println();
    }
    out.close();
    System.exit(0);
  }

  static class Edge {
    public int from, to;
    public Edge(int from, int to) {
      this.from = from;
      this.to = to;
    }
  }
  public static ArrayList<Edge> a1, a2;
  public static int[] par, size;
  public static int find(int x) {
    return x == par[x] ? x : (par[x] = find(par[x]));
  }
  public static void join(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (size[x] < size[y]) {int t = x; x = y; y = t;}
    par[y] = x;
    size[x] += size[y];
  }
  
  public static ArrayList<Integer> solve() {
      par = new int[n];
      size = new int[n];
      for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 1;
      }
      
      for (Edge e : a1) {
        join(e.from, e.to);
      }
      
      graph = new ArrayList[n];
      for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
      
      for (Edge e : a2) {
        graph[find(e.from)].add(find(e.to));
        graph[find(e.to)].add(find(e.from));
      }
      color = new int[n];
      Arrays.fill(color, -1);
      HashSet<Integer> res = new HashSet<>();
      for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
          x1 = new ArrayList<>();
          x2 = new ArrayList<>();
          t1 = 0; t2 = 0; flag = false;
          dfs(i, 0);
          if (flag) return null;
          if (t2 < t1-t2) {
            res.addAll(x1);
          } else {
            res.addAll(x2);
          }
        }
      }
      ArrayList<Integer> x = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        if (res.contains(find(i))) {
          x.add(i+1);
        }
      }
      return x;
  }
  
  public static ArrayList<Integer>[] graph;
  
  public static ArrayList<Integer> reconstruct() {
    color = new int[n];
    Arrays.fill(color, -1);
    ArrayList<Integer> res = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        t1 = 0; t2 = 0;
        x1 = new ArrayList<>();
        x2 = new ArrayList<>();
        dfs(i, 0);
        if (t2 < t1-t2) {
          res.addAll(x1);
        } else {
          res.addAll(x2);
        }
      }
    }
    return res;
  }
  
  public static int[] color;
  public static int t1, t2;
  public static ArrayList<Integer> x1, x2;
  public static boolean flag;
  public static void dfs(int node, int col) {
    if (color[node] != -1 && color[node] != col) {flag = true; return;}
    if (color[node] == col) return;
    color[node] = col;
    t1 += size[node];
    if (col == 0) t2 += size[node];
    if (col == 0) x1.add(node); else x2.add(node);
    for (int next : graph[node]) {
      dfs(next, 1-col);
    }
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}