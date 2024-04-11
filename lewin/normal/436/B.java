import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {
  public static void main (String[] args) throws IOException {
    BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
    PrintWriter out = new PrintWriter (System.out, true);
    
    StringTokenizer st = new StringTokenizer (in.readLine());
    int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
    char[][] grid = new char[N][M];
    for (int i = 0; i < N; i++) grid[i] = in.readLine().toCharArray();
    
    int[] ans = new int[M];
    int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    char[] exp = {'D', 'R', 'U', 'L'};
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k] * i, ny = j + dy[k] * i;
          if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
          if (grid[nx][ny] == exp[k]) ans[j]++;
        }
      }
    }
    
    out.print(ans[0]);
    for (int i = 1; i < M; i++) {
      out.print(" " + ans[i]);
    }
    out.println();
    out.close();
    System.exit(0);
  }
}