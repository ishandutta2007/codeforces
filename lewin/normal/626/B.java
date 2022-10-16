import java.io.*;
import java.util.*;

public class cards {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    
    int n = in.nextInt();
    char[] s = in.next().toCharArray();
    String gg = "RBG";
    int[] count = new int[3];
    for (int i = 0; i < n; i++) {
      count[gg.indexOf(s[i])]++;
    }
    vis = new boolean[n+1][n+1][n+1];
    reach = new boolean[3];
    dfs(count[0], count[1], count[2]);
    if (reach[0]) out.print("B");
    if (reach[1]) out.print("G");
    if (reach[2]) out.print("R");
    out.println();
    out.close();
    System.exit(0);
  }
  
  public static boolean[] reach;
  public static boolean[][][] vis;
  public static void dfs(int red, int blue, int green) {
    if (vis[red][blue][green]) return;
    if (red+blue+green==1) {
      if (blue == 1) reach[0] = true;
      if (green == 1) reach[1] = true;
      if (red == 1) reach[2] = true;
      return;
    }
    
    vis[red][blue][green] = true;
    if (red >= 2) dfs(red-1, blue, green);
    if (blue >= 2) dfs(red, blue-1, green);
    if (green >= 2) dfs(red, blue, green-1);
    if (red >= 1 && blue >= 1) dfs(red-1, blue-1, green+1);
    if (green >= 1 && blue >= 1) dfs(red+1, blue-1, green-1);
    if (red >= 1 && green >= 1) dfs(red-1, blue+1, green-1);
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