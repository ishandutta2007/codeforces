import java.io.*;
import java.util.*;

public class interestingsubstr {
  private static InputReader in;
  private static PrintWriter out;
  public static int[] val;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    val = new int[26];
    for (int i = 0; i < 26; i++) val[i] = in.nextInt();
    char[] c = in.next().toCharArray();
    int N = c.length;
    long[] psum = new long[N];
    psum[0] = val[c[0]-'a'];
    for (int i = 1; i < N; i++) {
      psum[i] = psum[i-1] + val[c[i]-'a'];
    }
    mp = new HashMap[26];
    for (int i = 0; i < 26; i++) mp[i] = new HashMap<>();
    
    long total = 0;
    for (int i = 0; i < N; i++) {
      long key = i==0?0:psum[i-1];
      if (mp[c[i]-'a'].containsKey(key)) total += mp[c[i]-'a'].get(key);
      if (!mp[c[i]-'a'].containsKey(psum[i])) mp[c[i]-'a'].put(psum[i], 0);
      mp[c[i]-'a'].put(psum[i], mp[c[i]-'a'].get(psum[i]) + 1);
    }
    out.println(total);
    out.close();
    System.exit(0);
  }
  
  public static HashMap<Long, Integer>[] mp;

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