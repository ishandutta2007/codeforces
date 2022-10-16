import java.io.*;
import java.util.*;

public class sortrailwaycars {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
    }
    int[] brr = Arrays.copyOf(arr,n);
    for (int i = 0; i < n; i++) {
      int j = (int)(Math.random()*(i+1));
      if (i != j) {
        int t = brr[i];
        brr[i] = brr[j];
        brr[j] = t;
      }
    }
    Arrays.sort(brr);
    for (int i = 0; i < n; i++) {
      arr[i] = Arrays.binarySearch(brr, arr[i]);
    }
    
    int[] pos = new int[n];
    for (int i = 0; i < n; i++) {
      pos[arr[i]] = i;
    }
    int longest_inc = 1;
    int cur = 1;
    for (int i = 1; i < n; i++) {
      if (pos[i] > pos[i-1]) {
        cur++;
      } else {
        cur = 1;
      }
      if (cur > longest_inc) {
        longest_inc = cur;
      }
    }
    
    out.println(n-longest_inc);
    
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