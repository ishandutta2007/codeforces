import java.io.*;
import java.util.*;

public class aoc {
  private static InputReader in;
  private static PrintWriter out;
  public static ArrayList<Integer>[] graph;
  public static long[] count;
  public static long[] rr;
  public static char[] c;
  public static int[][] tr;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    long[] arr = new long[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    c = in.next().toCharArray();
    graph = new ArrayList[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new ArrayList<>();
    }
    for (int i = 0; i < n-1; i++) {
        int a = in.nextInt()-1, b = in.nextInt()-1;
        graph[a].add(b);
        graph[b].add(a);
    }
    tr = new int[n][26];
    count = new long[n];
    rr = new long[n];
    for (int i = 0; i < n; i++) Arrays.fill(tr[i], -1);
    dfs(0, -1);
    
    long mx = 0;
    for (int i = 0; i < n; i++) {
        if (rr[i] + arr[i] > mx) {
            mx = rr[i] + arr[i];
        }
    }
    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (rr[i] + arr[i] == mx) {
            ct++;
        }
    }
    out.println(mx);
    out.println(ct);
    
    out.close();
    System.exit(0);
  }
  
  public static void dfs(int node, int par) {
      for (int next : graph[node]) {
          if (next == par) continue;
          dfs(next, node);
          
          int label = c[next]-'a';
          if (tr[node][label] == -1) {
              tr[node][label] = next;
          } else {
              merge(tr[node][label], next);
          }
      }
      ensureCount(node);
      rr[node] = count[node];
  }
  
  public static void merge(int a, int b) {
      for (int j = 0; j < 26; j++) if (tr[b][j] != -1) {
          if (tr[a][j] == -1) {
              tr[a][j] = tr[b][j];
          } else {
              merge(tr[a][j], tr[b][j]);
          }
      }
      ensureCount(a);
  }
  
  public static void ensureCount(int node) {
      count[node] = 1;
      for (int j = 0; j < 26; j++) {
          if (tr[node][j] != -1) {
              count[node] += count[tr[node][j]];
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