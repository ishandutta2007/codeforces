import java.io.*;
import java.util.*;

public class internationalolympiad {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int[] first = new int[]
        {0, 1989, 1999, 2099, 3099, 13099, 113099, 1113099, 11113099, 111113099, 1111113099};
    while(n-->0) {
      String s = in.next().substring(4);
      int atleast = first[s.length()];
      int clen = (""+atleast).length();
      String suff = (""+atleast).substring(clen-s.length());
      String front = (""+atleast).substring(0, clen-s.length());
      boolean add = Integer.parseInt(s) < Integer.parseInt(suff);
      if (add) {
        if (front.length() == 0) front = "1";
        else front = ""+(Integer.parseInt(front)+1);
      }
      System.out.println(front+""+s);
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