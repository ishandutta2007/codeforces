import java.io.*;
import java.util.*;

public class couplecover {
  private static InputReader in;
  private static PrintWriter out;

  public static int MAXP = 3000010;
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    long[] freq = new long[MAXP];
    for (int i = 0; i < n; i++) {
      freq[in.nextInt()]++;
    }
    
    long[] b = new long[MAXP];
    for (int i = 1; i < MAXP; i++) {
      if (freq[i] > 0) {
        long q = freq[i];
        freq[i]--;
        for (int j = 1; j*i < MAXP; j++)
          b[j*i] += freq[j]*q;
        freq[i]++;
      }
    }
    for (int i = 1; i < MAXP; i++) {
      b[i] += b[i-1];
    }
    
    int q = in.nextInt();
    long all = n*(long)(n-1);
    StringBuffer w = new StringBuffer();
    while(q-->0) {
      w.append((all-b[in.nextInt()-1])+"\n");
    }
    
    out.print(w);
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