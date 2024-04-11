import java.io.*;
import java.util.*;

public class hiddenword {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    char[] c = in.next().toCharArray();
    int[] last = new int[26];
    Arrays.fill(last, -1);
    int repeat = -1;
    int opos = -1;
    for (int i = 0; i < 27; i++) {
      if (last[c[i]-'A'] != -1) {
        repeat = c[i]-'A';
        opos = i;
      } else {
        last[c[i]-'A'] = i;
      }
    }
    
    if (opos == last[repeat]+1) {
      out.println("Impossible");
    } else {
      char[][] ans = new char[2][13];
      int side = (opos - last[repeat] - 1);
      int off = side/2;
      ans[0][off] = (char)(repeat+'A');
      int cx = 0, cy = off-1;
      if (cy < 0) {
        cx = 1;
        cy = 0;
      }
      for (int i = last[repeat]+1; i < opos; i++) {
        ans[cx][cy] = c[i];
        if (cx == 0) cy--;
        else cy++;
        if (cy < 0) {
          cx = 1;
          cy = 0;
        }
      }
      int ax = 0, ay = off+1;
      if (ay >= 13) {
        ax = 1;
        ay = 12;
      }
      for (int i = last[repeat]-1; i >= 0; i--) {
        ans[ax][ay] = c[i];
        if (ax == 0) ay++;
        else ay--;
        if (ay >= 13) {
          ax = 1;
          ay = 12;
        }
      }
      for (int i = opos+1; i < 27; i++) {
        ans[cx][cy] = c[i];
        if (cx == 0) cy--;
        else cy++;
        if (cy < 0) {
          cx = 1;
          cy = 0;
        }
        if (cy >= 13) {
          cx = 0;
          cy = 12;
        }
      }
      out.println(new String(ans[0]));
      out.println(new String(ans[1]));
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