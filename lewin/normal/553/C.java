import java.io.*;
import java.util.*;

public class OddGraphs {
  public static int mod = 1000000007;
  static class Edge {
    public int from, to;
    public Edge(int from, int to) {
      this.from = from;
      this.to = to;
    }
  }
  
  public static ArrayList<Integer>[] graph;
  public static ArrayList<Edge> zeros, ones;
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
  
  public static void main (String[] args) {
    InputReader in = new InputReader (System.in);
    PrintWriter out = new PrintWriter (System.out, true);
    
    int N = in.nextInt(), M = in.nextInt();
    zeros = new ArrayList<>();
    ones = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1, c = in.nextInt();
      if (c == 0) {
        zeros.add(new Edge(a,b));
      } else {
        ones.add(new Edge(a,b));
      }
    }
    
    par = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
      par[i] = i;
      size[i] = 1;
    }
    
    for (Edge e : ones) {
      join(e.from, e.to);
    }
    
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();
    
    for (Edge e : zeros) {
      graph[find(e.from)].add(find(e.to));
      graph[find(e.to)].add(find(e.from));
    }
    
    vis = new boolean[N];
    color = new boolean[N];
    int comp = 0;
    for (int i = 0; i < N; i++) {
      if (find(i) == i && !vis[i]) {
        if (!dfs(i, false)) {
          out.println(0);
          out.close();
          System.exit(0);
        } else {
          comp++;
        }
      }
    }
    int res = 1;
    for (int i = 0; i < comp-1; i++) res = (res * 2) % mod;
    
    out.println(res);
    out.close();
    System.exit(0);
  }
  
  public static boolean[] vis, color;
  public static boolean dfs(int node, boolean c) {
    if (vis[node]) return c == color[node];
    vis[node] = true;
    color[node] = c;
    for (int neighbor : graph[node]) {
      if (!dfs(neighbor, !c))
        return false;
    }
    return true;
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