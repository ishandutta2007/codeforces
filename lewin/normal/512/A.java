import java.io.*;
import java.util.*;

public class foxnames {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    char[][] s = new char[N][];
    int[][] graph = new int[26][26];
    int[] indeg = new int[26];
    for (int i = 0; i < N; i++)
      s[i] = in.next().toCharArray();
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        int k = 0;
        for (; k < Math.min(s[i].length, s[j].length); k++) {
          if (s[i][k] != s[j][k]) {
            graph[s[i][k]-'a'][s[j][k]-'a']++;
            indeg[s[j][k]-'a']++;
            break;
          }
        }
        if (k == Math.min(s[i].length, s[j].length) && s[i].length > s[j].length) {
          out.println("Impossible");
          out.close();
          System.exit(0);
        }
      }
    }
    
    int[] queue = new int[26];
    int front = 0, back = 0;
    for (int i = 0; i < 26; i++)
      if (indeg[i] == 0)
        queue[back++] = i;
    while (front < back) {
      int n = queue[front++];
      for (int i = 0; i < 26; i++) {
        if (graph[n][i] > 0) {
          indeg[i] -= graph[n][i];
          graph[n][i] = 0;
          if (indeg[i] == 0) {
            queue[back++] = i;
          }
        }
      }
    }
    if (front != 26) {out.println("Impossible");}
    else {
      for (int i = 0; i < 26; i++)
        out.print((char)(queue[i]+'a'));
      out.println();
    }
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