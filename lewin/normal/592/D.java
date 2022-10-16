import java.io.*;
import java.util.*;

public class superm {
  private static InputReader in;
  private static PrintWriter out;
  public static int n,m;
  public static ArrayList<Integer>[] graph;
  public static boolean[] cover;
  public static boolean[] deleted;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    n = in.nextInt();
    m = in.nextInt();
    
    graph = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      graph[i] = new ArrayList<>();
    }
    int[] deg = new int[n];
    for (int i = 0; i < n-1; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
      deg[a]++;
      deg[b]++;
    }
    
    cover = new boolean[n];
    for (int i = 0; i < m; i++) cover[in.nextInt()-1] = true;
    deleted = new boolean[n];
    int[] queue = new int[n];
    int front = 0, back = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 1 && !cover[i]) {
        deleted[i] = true;
        queue[back++] = i;
      }
    }
    while(front < back) {
      int cur = queue[front++];
      for (int x : graph[cur]) {
        if (deleted[x]) continue;
        if (--deg[x] == 1 && !cover[x]) {
          deleted[x] = true;
          queue[back++] = x;
        }
      }
    }
    int nodes = n;
    for (int i = 0; i < n; i++) if (deleted[i]) nodes--;
    
    int cost = (nodes-1)*2;
    
    int root = 0;
    while (deleted[root]) root++;
    down = new int[n];
    d2 = new int[n];
    from = new int[n];
    dfs(root, -1);
    up = new int[n];
    dfs2(root, -1);
    
    int max = -100000, bid = -1;
    for (int i = 0; i < n; i++) {
      if (deleted[i]) continue;
      int t = Math.max(down[i], up[i]);
      if (t > max) {
        max = t;
        bid = i+1;
      }
    }
    
    out.println(bid);
    out.println(cost - max);
    out.close();
    System.exit(0);
  }
  
  public static int[] down;
  public static int[] d2;
  public static int[] from;
  public static int[] up;
  public static void dfs(int node, int par) {
    int b1 = 0, b2 = 0, f = -1;
    for (int next : graph[node]) {
      if (next == par || deleted[next]) continue;
      dfs(next, node);
      int t = down[next]+1;
      if (t > b1) {
        b2 = b1;
        b1 = t;
        f = next;
      } else if (t > b2) {
        b2 = t;
      }
    }
    down[node] = b1;
    d2[node] = b2;
    from[node] = f;
  }
  
  public static void dfs2(int node, int par) {
    for (int next : graph[node]) {
      if (next == par || deleted[next]) continue;
      up[next] = Math.max(up[node], next == from[node] ? d2[node] : down[node]) + 1;
      dfs2(next, node);
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