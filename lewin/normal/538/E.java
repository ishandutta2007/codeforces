import java.io.*;
import java.util.*;

public class demigures {
  private static InputReader in;
  private static PrintWriter out;
  public static ArrayList<Integer>[] graph;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++) graph[i] = new ArrayList<Integer>();
    for (int i = 0; i < N-1; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
    }
    
    boolean[] p = new boolean[N];
    int[] queue = new int[N];
    int front = 0, back = 0;
    queue[back++] = 0;
    p[0] = true;
    while (front < back) {
      int cur = queue[front++];
      for (int x : graph[cur]) {
        queue[back++] = x;
        p[x] = !p[cur];
      }
    }
    
    int[] leaves = new int[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      if (graph[node].size() == 0) leaves[node] = 1;
      else {
        for (int x : graph[node]) {
          leaves[node] += leaves[x];
        }
      }
    }
    
    
    int[] max = new int[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      if (graph[node].size() == 0) max[node] = 1;
      else {
        if (p[node]) {
          int diff = 1 << 29;
          int sum = 0;
          for (int x : graph[node]) {
            sum += leaves[x];
            diff = Math.min(diff, leaves[x] - max[x]);
          }
          max[node] = sum - diff;
        } else {
          int sum = 0;
          for (int x : graph[node]) {
            sum += max[x] - 1;
          }
          max[node] = sum + 1;
        }
      }
    }
    
    int[] min = new int[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      if (graph[node].size() == 0) min[node] = 1;
      else {
        if (!p[node]) {
          int diff = 1 << 29;
          int sum = 0;
          for (int x : graph[node]) {
            sum += leaves[x];
            diff = Math.min(diff, leaves[x] - min[x]);
          }
          min[node] = sum - diff;
        } else {
          int sum = 0;
          for (int x : graph[node]) {
            sum += min[x] - 1;
          }
          min[node] = sum + 1;
        }
      }
    }
    
    
    out.println(max[0]+" "+(leaves[0] - min[0] + 1));
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