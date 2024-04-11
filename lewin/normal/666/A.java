import java.io.*;
import java.util.*;

public class reberlandlinguistics {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    char[] c = (in.next()+"****").toCharArray();
    int n = c.length-4;
    boolean[][] canEnd = new boolean[n+2][4];
    canEnd[n][2] = canEnd[n][3] = true;
    HashSet<String> s = new HashSet<>();
    for (int i = n-1; i >= 0; i--) {
      if (i+2 <= n) {
        if (!(c[i] == c[i+2] && c[i+1] == c[i+3])) {
          canEnd[i][2] |= canEnd[i+2][2];
        }
        canEnd[i][2] |= canEnd[i+2][3];
      }
      if (i+3 <= n) {
        if (!(c[i] == c[i+3] && c[i+1] == c[i+4] && c[i+2] == c[i+5])) {
          canEnd[i][3] |= canEnd[i+3][3];
        }
        canEnd[i][3] |= canEnd[i+3][2];
      }
    }
    
    for (int i = 5; i < n; i++) {
      if (canEnd[i][2]) {
        s.add(""+c[i]+c[i+1]);
      }
      if (canEnd[i][3]) {
        s.add(""+c[i]+c[i+1]+c[i+2]);
      }
    }
    out.println(s.size());
    ArrayList<String> arr = new ArrayList<String>(s);
    Collections.sort(arr);
    for (String m : arr) out.println(m);
    
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