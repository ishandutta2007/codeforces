import java.io.*;
import java.util.*;

public class vanyatriangles {
  private static InputReader in;
  private static PrintWriter out;
  
  public static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  static class Fraction {
    public int x, y;
    public Fraction (int x, int y) {
      if (x < 0 || (x == 0 && y < 0)) {
        x = -x;
        y = -y;
      }
      int g = gcd(x, Math.abs(y));
      x /= g;
      y /= g;
      this.x = x;
      this.y = y;
    }
    
    @Override
    public int hashCode() {
      return x*1000+y;
    }
    
    @Override
    public boolean equals(Object other) {
      if (!(other instanceof Fraction)) return false;
      return ((Fraction)other).x == x && ((Fraction)other).y == y;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int[] x = new int[N], y = new int[N];
    for (int i = 0; i < N; i++) {
      x[i] = in.nextInt();
      y[i] = in.nextInt();
    }
    
    long res = (long)N*(long)(N-1)*(long)(N-2);
    for (int i = 0; i < N; i++) {
      HashMap<Fraction, Integer> hm = new HashMap<>();
      
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        Fraction f = new Fraction(x[j]-x[i],y[j]-y[i]);
        if (!hm.containsKey(f)) hm.put(f, 1);
        else {
          int a = hm.get(f);
          res -= 2*a;
          hm.put(f,a+1);
        }
      }
    }
    
    out.println(res/6);
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