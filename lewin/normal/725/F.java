import java.io.*;
import java.util.*;

public class familyphoto {
  private static InputReader in;
  private static PrintWriter out;
  static class Photo {
    public int a,b,i,p;
    public Photo(int a, int b) {
      this.a = a;
      this.b = b;
    }
    public Photo(int a, int b, int i, int p) {
      this.a = a;
      this.b = b;
      this.i = i;
      this.p = p;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    
    Photo[][] ps = new Photo[n][2];
    long ascore = 0, bscore = 0;
    PriorityQueue<Photo> pq = new PriorityQueue<>(new Comparator<Photo>() {
      public int compare(Photo a, Photo b) {
        return (b.a+b.b) - (a.a+a.b);
      }
    });
    for (int i = 0; i < n; i++) {
      ps[i][0] = new Photo(in.nextInt(), in.nextInt(), i, 0);
      ps[i][1] = new Photo(in.nextInt(), in.nextInt(), i, 1);
      if (ps[i][0].a <= ps[i][1].b && ps[i][0].b <= ps[i][1].a) {
        continue;
      }
      if (ps[i][0].a + ps[i][0].b < ps[i][1].a + ps[i][1].b) {
        if (ps[i][0].a >= ps[i][1].b) {
          ascore += ps[i][0].a - ps[i][1].b;
        } else if (ps[i][0].b >= ps[i][1].a) {
          bscore += ps[i][0].b - ps[i][1].a;
        }
      } else {
        pq.add(ps[i][0]);
      }
    }
    boolean turn = true;
    while (pq.size() > 0) {
      Photo gg = pq.poll();
      if (gg.p == 0) {
        pq.add(ps[gg.i][1]);
        gg.a = ps[gg.i][0].a;
        gg.b = ps[gg.i][0].b;
      }
      if (turn) ascore += gg.a;
      else bscore += gg.b;
      turn = !turn;
    }
    out.println(ascore-bscore);
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