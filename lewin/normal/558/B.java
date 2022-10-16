import java.io.*;
import java.util.*;

public class amrarray {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = in.nextInt();
    int[] count = new int[1000001];
    for (int i = 0; i < N; i++) count[a[i]]++;
    int max = 0;
    for (int i = 0; i < count.length; i++) max = Math.max(max, count[i]);
    
    int r = 0;
    int cmax = 0;
    int[] s1 = new int[N+1];
    int[] s2 = new int[1000001];
    int bestl = 0, bestr = N-1;
    for (int l = 0; l < N; l++) {
      if (r < l) {
        r = l;
        Arrays.fill(s1, 0);
        Arrays.fill(s2, 0);
        cmax = 0;
      }
      while (r < N && cmax != max) {
        s1[s2[a[r]]]--;
        s2[a[r]]++;
        s1[s2[a[r]]]++;
        if (s2[a[r]] > cmax) cmax = s2[a[r]];
        r++;
      }
      
      if (cmax == max && r-1-l < bestr-bestl) {
        bestr = r-1;
        bestl = l;
      }
      if (--s1[s2[a[l]]] == 0 && s2[a[l]] == cmax) {
        cmax--;
      }
      s2[a[l]]--;
      s1[s2[a[l]]]++;
    }
    
    out.println((bestl+1)+" "+(bestr+1));
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