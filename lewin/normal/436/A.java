import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
  static class Candy {
    public int height, mass;
    public Candy (int height, int mass) {
      this.height = height;
      this.mass = mass;
    }
  }
  public static void main (String[] args) {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out, true);
    
    int N = in.nextInt(), x = in.nextInt();
    ArrayList<Candy> a = new ArrayList<Candy> (), b = new ArrayList<Candy> ();
    for (int i = 0; i < N; i++) {
      int t = in.nextInt();
      Candy c = new Candy (in.nextInt(), in.nextInt());
      if (t == 0) a.add(c);
      else b.add(c);
    }
    ArrayList<Candy> ca = new ArrayList<Candy>(a), cb = new ArrayList<Candy>(b);
    int max1 = 0, curheight = x;
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0) {
        int bestval = -1;
        Candy ac = null;
        for (int j = 0; j < ca.size(); j++) {
          if (ca.get(j).height <= curheight) {
            if (ca.get(j).mass > bestval) {
              bestval = ca.get(j).mass;
              ac = ca.get(j);
            }
          }
        }
        if (ac == null) break;
        curheight += ac.mass;
        ca.remove(ac);
        max1++;
      } else {
        int bestval = -1;
        Candy ac = null;
        for (int j = 0; j < cb.size(); j++) {
          if (cb.get(j).height <= curheight) {
            if (cb.get(j).mass > bestval) {
              bestval = cb.get(j).mass;
              ac = cb.get(j);
            }
          }
        }
        if (ac == null) break;
        cb.remove(ac);
        curheight += ac.mass;
        max1++;
      }
    }
    ca = new ArrayList<Candy>(a);
    cb = new ArrayList<Candy>(b);
    curheight = x; int max2 = 0;
    for (int i = 0; i < N; i++) {
      if (i % 2 == 1) {
        int bestval = -1;
        Candy ac = null;
        for (int j = 0; j < ca.size(); j++) {
          if (ca.get(j).height <= curheight) {
            if (ca.get(j).mass > bestval) {
              bestval = ca.get(j).mass;
              ac = ca.get(j);
            }
          }
        }
        if (ac == null) break;
        curheight += ac.mass;
        ca.remove(ac);
        max2++;
      } else {
        int bestval = -1;
        Candy ac = null;
        for (int j = 0; j < cb.size(); j++) {
          if (cb.get(j).height <= curheight) {
            if (cb.get(j).mass > bestval) {
              bestval = cb.get(j).mass;
              ac = cb.get(j);
            }
          }
        }
        if (ac == null) break;
        cb.remove(ac);
        curheight += ac.mass;
        max2++;
      }
    }
    
    out.println (Math.max(max1, max2));
  }
}