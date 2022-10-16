import java.io.*;
import java.util.*;

public class ablecture {
  private static InputReader in;
  private static PrintWriter out;
  public static int N;
  public static ArrayList<Integer>[] graph;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++)
      graph[i] = new ArrayList<>();
    for (int i = 0; i < N-1; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
    }
    
    size = new int[N];
    depth = new int[N];
    anc = new int[20][N];
    anc[0][0] = -1;
    bfs();
    for (int k = 1; k < anc.length; k++)
      for (int i = 0; i < N; i++)
        anc[k][i] = anc[k-1][i] == -1 ? -1 : anc[k-1][anc[k-1][i]];
    
    int Q = in.nextInt();
    while (Q-- > 0) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      out.println(query(a,b));
    }
    out.close();
    System.exit(0);
  }
  
  public static int query(int a, int b) {
    if (a == b) return N;
    int k = lca(a, b);
    int dist = depth[a] + depth[b] - 2 * depth[k];
    if (dist % 2 == 1) return 0;
    int up = dist/2 - 1;
    for (int i = 0; i < 20; i++)
      if ((up & (1 << i)) > 0) {
        if (a != -1) a = anc[i][a];
        if (b != -1) b = anc[i][b];
      }
    int node = 0;
    if (a == -1) node = anc[0][b];
    else if (b == -1) node = anc[0][a];
    else if (depth[a] < depth[b]) node = anc[0][b];
    else node = anc[0][a];
    int res = size[node];
    boolean sub = true;
    if (a != -1 && depth[a] == depth[node] + 1) res -= size[a]; else sub = false;
    if (b != -1 && depth[b] == depth[node] + 1) res -= size[b]; else sub = false;
    if (sub) res += N - size[node];
    return res;
  }
  
  private static int lca(int a, int b) {
    if (depth[a] < depth[b]) {
      int t = a; a = b; b = t;
    }

    int diff = depth[a] - depth[b];
    for (int i = 0; 1 << i <= diff; i++)
      if ((diff & (1 << i)) != 0)
        a = anc[i][a];

    if (a == b)
      return a;
    
    for (int i = 19; i >= 0; i--)
      if (anc[i][a] != anc[i][b]) {
        a = anc[i][a];
        b = anc[i][b];
      }

    return anc[0][a];
  }
  
  public static int[] size, depth;
  public static int[][] anc;
  
  public static void bfs() {
    int[] queue = new int[N];
    int front = 0, back = 0;
    depth[0] = 0;
    queue[back++] = 0;
    anc[0][0] = -1;

    while (front != back) {
      int node = queue[front++];
      for (int next : graph[node]) {
        if (next == anc[0][node]) continue;
        depth[next] = depth[node] + 1;
        anc[0][next] = node;
        queue[back++] = next;
      }
    }
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      size[node]++;
      for (int next : graph[node]) {
        if (anc[0][node] == next) continue;
        size[node] += size[next];
      }
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