import java.io.*;
import java.util.*;

public class drazilfact {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    String s = in.next();
    ArrayList<Integer> dig = new ArrayList<Integer>();
    for (int i = 0; i < N; i++) {
      char c = s.charAt(i);
      if (c == '0' || c == '1') continue;
      if (c == '2') {
        dig.add(2);
      } else if (c == '3') {
        dig.add(3);
      } else if (c == '4') {
        dig.add(3);
        dig.add(2);
        dig.add(2);
      } else if (c == '5') {
        dig.add(5);
      } else if (c == '6') {
        dig.add(5);
        dig.add(3);
      } else if (c == '7') {
        dig.add(7);
      } else if (c == '8') {
        dig.add(7);
        dig.add(2);
        dig.add(2);
        dig.add(2);
      } else if (c == '9') {
        dig.add(7);
        dig.add(3);
        dig.add(3);
        dig.add(2);
      }
    }
    Collections.sort(dig);
    for (int i = dig.size()-1; i >= 0; i--)
      out.print(dig.get(i));
    out.println();
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