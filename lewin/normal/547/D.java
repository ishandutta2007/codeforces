import java.io.*;
import java.util.*;

public class mikefish {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Point {
    public int x,y,id;
    public char color;
    public boolean used;
    
    public Point(int x, int y, int id) {
      this.x = x;
      this.y = y;
      this.id = id;
      this.used = false;
      this.color = ' ';
    }
  }

  public static int N;
  public static Point[] p;
  public static HashMap<Integer, LinkedList<Point>> xmp, ymp;
  
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    p = new Point[N];
    xmp = new HashMap<>();
    ymp = new HashMap<>();
    for (int i = 0; i < N; i++) {
      p[i] = new Point(in.nextInt(), in.nextInt(), i);
      
      if (!xmp.containsKey(p[i].x)) xmp.put(p[i].x, new LinkedList<>());
      xmp.get(p[i].x).add(p[i]);
      
      if (!ymp.containsKey(p[i].y)) ymp.put(p[i].y, new LinkedList<>());
      ymp.get(p[i].y).add(p[i]);
    }
    
    for (int i = 0; i < N; i++) {
      if (!p[i].used) {
        dfs(i, true, 'r');
        dfs(i, false, 'r');
      }
    }
    char[] res = new char[N];
    for (int i = 0; i < N; i++) res[i] = p[i].color;
    out.println(new String(res));
    out.close();
    System.exit(0);
  }
  
  public static void dfs(int i, boolean x, char c) {
    p[i].used = true;
    p[i].color = c;
    char nc = c == 'r' ? 'b' : 'r';
    if (x) {
      while (xmp.get(p[i].x).size() > 0) {
        Point q = xmp.get(p[i].x).removeFirst();
        if (q.used) continue;
        dfs(q.id, false, nc);
        return;
      }
    } else {
      while (ymp.get(p[i].y).size() > 0) {
        Point q = ymp.get(p[i].y).removeFirst();
        if (q.used) continue;
        dfs(q.id, true, nc);
        return;
      }
    }
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