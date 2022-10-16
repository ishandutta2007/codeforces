import java.io.*;
import java.util.*;

public class childzoo {
  private static InputReader in;
  private static PrintWriter out;
  public static int N, M;
  public static int[] val;
  public static ArrayList<Integer>[] graph;
  
  public static int[] par;
  public static int[] size;
  
  public static int find (int x) {
    return x == par[x] ? x : (par[x] = find(par[x]));
  }
  
  public static void join (int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (size[x] > size[y]) {
      int t = x; x = y; y = t;
    }
    size[y] += size[x];
    par[x] = y;
  }
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    M = in.nextInt();
    val = new int[N];
    for (int i = 0; i < N; i++) val[i] = in.nextInt();
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      int a = in.nextInt() - 1, b = in.nextInt() - 1;
      graph[a].add(b);
      graph[b].add(a);
    }
    
    Integer[] s = new Integer[N];
    for (int i = 0; i < N; i++) s[i] = i;
    Arrays.sort(s, new Comparator<Integer>() {
      public int compare(Integer a, Integer b) {
        if (val[b] == val[a]) return b - a;
        return val[b] - val[a];
      }
    });
    size = new int[N];
    par = new int[N];
    for (int i = 0; i < N; i++) {
      par[i] = i;
      size[i] = 1;
    }
    
    long res = 0;
    for (int i = 0; i < N; i++) {
      int node = s[i];
      
      HashSet<Integer> seen = new HashSet<Integer>();
      long sum = 0;
      for (int neighbor : graph[node]) {
        if (val[neighbor] < val[node] || (val[neighbor] == val[node] && neighbor < node)) continue;
        int root = find(neighbor);
        if (seen.contains(root)) continue;
        seen.add(root);
        res += (long)sum * (long)size[root] * (long)val[node];
        sum += size[root];
      }
      res += (long)sum * (long)val[node];
      
      for (int neighbor : graph[node]) {
        if (val[neighbor] < val[node] || (val[neighbor] == val[node] && neighbor < node)) continue;
        join(neighbor, node);
      }
    }
    
    out.printf("%.10f\n", 2 * res / (double)N / (double)(N - 1));
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