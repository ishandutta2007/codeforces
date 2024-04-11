import java.io.*;
import java.util.*;

public class mediansmooth {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    int max = 0;
    boolean[] adj = new boolean[n];
    adj[0] = adj[n-1] = true;
    for (int i = 1; i < n-1; i++) {
      if (arr[i] == arr[i-1] || arr[i] == arr[i+1]) adj[i] = true;
    }
    
    
    
    for (int i = 1; i < n-1; i++) {
      if (adj[i]) continue;
      int j = i;
      while (!adj[j+1]) j++;
      
      int len = j-i+1;
      max = Math.max(max, (len+1)/2);
      
      if (len % 2 == 1) {
        int val = 1-arr[i];
        for (int k = i; k <= j; k++) arr[k] = val;
      } else {
        int val1 = 1-arr[i];
        for (int k = i; k < i+len/2; k++) {
          arr[k] = val1;
        }
        for (int k = i+len/2; k <= j; k++) {
          arr[k] = 1-val1;
        }
      }
      
      i = j;
    }
    out.println(max);
    for (int i = 0; i < n; i++) {
      if (i != 0) out.print(" ");
      out.print(arr[i]);
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