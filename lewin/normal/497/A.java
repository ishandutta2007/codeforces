import java.io.*;
import java.util.*;

public class removingcolumns {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    StringTokenizer st = new StringTokenizer(in.readLine());
    int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
    char[][] grid = new char[N][];
    for (int i = 0; i < N; i++) {
      grid[i] = in.readLine().toCharArray();
    }
    int count = 0;
    boolean[] sat = new boolean[N];
    for (int j = 0; j < M; j++) {
      boolean[] nsat = new boolean[N];
      boolean remove = false;
      for (int i = 0; i < N-1; i++) {
        if (sat[i]) continue;
        if (grid[i][j] > grid[i+1][j]) {
          count++;
          remove = true;
          break;
        } else if (grid[i][j] < grid[i+1][j]) {
          nsat[i] = true;
        }
      }
      if (!remove)
        for (int i = 0; i < N-1; i++) sat[i] |= nsat[i];
    }
    out.println(count);
    out.close();
    System.exit(0);
  }
}