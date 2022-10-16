import java.io.*;
import java.util.*;
public class HamiltonianTree {
  private static InputReader in;
  private static PrintWriter out;
  public static ArrayList<Integer>[] graph;
  
  public static void main (String[] args) {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt();
    long x = in.nextInt(), y = in.nextInt();
    
    if (x > y) {
      int[] deg = new int[n];
      for (int i = 0; i < n-1; i++) {
        int a = in.nextInt()-1, b = in.nextInt()-1;
        deg[a]++;
        deg[b]++;
      }
      int max = 0;
      for (int i = 0; i < n; i++) {
        max = Math.max(max, deg[i]);
      }
      out.println(y * (n - 2) + (max == n-1 ? x : y));
    } else {
      graph = new ArrayList[n];
      for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
      for (int i = 0; i < n-1; i++) {
        int a = in.nextInt()-1, b = in.nextInt()-1;
        graph[a].add(b);
        graph[b].add(a);
      }
      ans = 0;
      dfs(0, -1);
      out.println((n-1-ans)*y + ans*x);
    }
    out.close();
    System.exit(0);
  }
  
  public static long ans;
  public static int dfs(int node, int par) {
    int left = 2;
    for (int next : graph[node]) {
      if (next == par) continue;
      int x = dfs(next, node);
      if (left > 0 && x == 1) {
        ans++;
        left--;
      }
    }
    return left > 0 ? 1 : 0;
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