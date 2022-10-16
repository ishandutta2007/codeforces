import java.io.*;
import java.util.*;

public class lastfight {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt()+1;
    int k = in.nextInt();
    int[] arr = new int[n];
    boolean[] fixed = new boolean[n];
    int q = 0;
    for (int i = 0; i < n; i++) {
      String s = in.next();
      if (s.equals("?")) q++;
      else {fixed[i] = true; arr[i] = Integer.parseInt(s);}
    }
    if (q == 0) {
      // is k a root?
      for (int iter = 0; iter < 100; iter++) {
        int mod = (int)(Math.random()*1000000000);
        long cur = 0;
        for (int i = n-1; i >= 0; i--) {
          cur = (cur * k + arr[i]) % mod;
          if (cur < 0) cur += mod;
        }
        if (cur != 0) {
          out.println("No");
          out.close();
          System.exit(0);
        }
      }
      out.println("Yes");
      out.close();
      System.exit(0);
    } else {
      if (k == 0) {
       if (fixed[0]) out.println(arr[0] == 0 ? "Yes" : "No");
       else out.println((n-q) % 2 == 0 ? "No" : "Yes");
      } else {
        out.println(n % 2 == 0 ? "Yes" : "No");
      }
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