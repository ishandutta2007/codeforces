import java.io.*;
import java.util.*;

public class destroyingroads {
  private static InputReader in;
  private static PrintWriter out;
  public static ArrayList<Integer>[] graph;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int M = in.nextInt();
    int[][] dist = new int[N][N];
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++) {
      graph[i] = new ArrayList<>();
    }
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
    }
    
    int s1 = in.nextInt()-1, t1 = in.nextInt()-1, l1 = in.nextInt();
    int s2 = in.nextInt()-1, t2 = in.nextInt()-1, l2 = in.nextInt();

    int[] queue = new int[N];
    int[] vis = new int[N];
    for (int i = 0; i < N; i++) {
      int front = 0, back = 0;
      queue[back++] = i;
      vis[i] = i+1;
      dist[i][i] = 0;
      while (front < back) {
        int cur = queue[front++];
        for (int x : graph[cur]) {
          if (vis[x] == i+1) continue;
          vis[x] = i+1;
          queue[back++] = x;
          dist[i][x] = 1 + dist[i][cur];
        }
      }
    }
    
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
      out.println("-1");
      out.close();
      System.exit(0);
    }
    
    int min = dist[s1][t1] + dist[s2][t2];
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 && dist[s2][i] + dist[i][j] + dist[j][t2] <= l2)
          min = Math.min(min, dist[s1][i] + dist[j][t1] + dist[s2][i] + dist[j][t2] + dist[i][j]);
        if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 && dist[s2][j] + dist[i][j] + dist[i][t2] <= l2)
          min = Math.min(min, dist[s1][i] + dist[j][t1] + dist[s2][j] + dist[i][t2] + dist[i][j]);
      }
    }
    
    out.println(M - min);
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