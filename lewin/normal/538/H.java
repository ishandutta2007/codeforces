import java.io.*;
import java.util.*;

public class summerdichotomy {
  private static InputReader in;
  private static PrintWriter out;
  public static int t, T, N, M;
  public static ArrayList<Integer>[] graph;
  
  public static boolean[] vis;
  public static int[] color;
  public static Interval[] tt;
  
  public static void dfs (int node, int c) {
    if (vis[node]) {
      if (c != color[node]) {
        out.println("IMPOSSIBLE");
        out.close();
        System.exit(0);
      }
      return;
    }
    vis[node] = true;
    color[node] = c;
    for (int x : graph[node]) dfs(x, 1 - c);
  }
  
  static class Interval {
    public int low, high;
    public Interval(int low, int high) {
      this.low = low;
      this.high = high;
    }
    
    public boolean intersect(int x) {
      return x >= low && x <= high;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    t = in.nextInt();
    T = in.nextInt();
    N = in.nextInt();
    M = in.nextInt();
    tt = new Interval[N];
    graph = new ArrayList[N];
    int mx = 0, mn = 1 << 29;
    for (int i = 0; i < N; i++) {
      tt[i] = new Interval(in.nextInt(), in.nextInt());
      mx = Math.max(mx, tt[i].low);
      mn = Math.min(mn, tt[i].high);
      graph[i] = new ArrayList<>();
    }
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
    }
    
    if (mx + mn < t) {
      mx = t - mn;
    } else if (mx + mn > T) {
      mn = T - mx;
    }
    
    if (mx < 0 || mn < 0) {
      out.println("IMPOSSIBLE");
      out.close();
      System.exit(0);
    }
    
    vis = new boolean[N];
    color = new int[N];
    for (int i = 0; i < N; i++) {
      if (!tt[i].intersect(mn) && !tt[i].intersect(mx)) {
        out.println("IMPOSSIBLE");
        out.close();
        System.exit(0);
      }
      
      if (!tt[i].intersect(mn)) dfs(i, 1);
      if (!tt[i].intersect(mx)) dfs(i, 0);
    }
    for (int i = 0; i < N; i++) {
      if (!vis[i])
        dfs(i, 0);
    }
    
    out.println("POSSIBLE");
    out.println(mn+" "+mx);
    for (int i = 0; i < N; i++) {
      out.print((color[i]+1));
    }
    out.println();
    out.close();
    System.exit(0);
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