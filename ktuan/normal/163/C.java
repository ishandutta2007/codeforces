import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiC implements Runnable {

  final double eps = 1e-9;

  class Event implements Comparable<Event> {
    double time;
    boolean in;
    boolean out;
    public Event(double time, boolean in, boolean out) {
      this.time = time;
      this.in = in;
      this.out = out;
    }

    public int compareTo(Event e) {
      if (time < e.time) return -1;
      if (time > e.time) return 1;
      return 0;
    }
  }

  int n, L;
  double[] a;
  double d;

  public void run() {
    n = nextInt();
    L = nextInt();
    double v1 = nextDouble();
    double v2 = nextDouble();
    d = L * v2 / (v1 + v2);
    a = new double[2 * n];
    for (int i = 0; i < n; ++i) {
      a[i] = nextInt();
      a[i + n] = a[i] + 2 * L;
    }
    ArrayList<Event> list = new ArrayList<Event>();
    for (int i = 0; i < 2 * n; ++i) {
      list.add(new Event(a[i] - d, true, false));
      list.add(new Event(a[i], false, true));
    }
    list.add(new Event(0, false, false));
    Collections.sort(list);
    int count = 0;
    double last = -2 * L;
    double[] len = new double[n + 1];
    for (int i = 0; i < list.size(); ++i) {
      Event e = list.get(i);
      if (e.in) ++count;
      if (e.out) --count;
      double end = 2 * L;
      if (i + 1 < list.size()) end = Math.min(end, list.get(i + 1).time);
      double start = Math.max(0, e.time);
      len[count] += Math.max(0, end - start);
    }
    for (int i = 0; i <= n; ++i) {
      double p = len[i] / 2 / L;
      out.printf("%.10f\n", p);
    }
  }

    int[] ar(int st, int en) { int[] res = new int[Math.max(en - st, 0)]; for (int i = st; i < en; ++i) res[i - st] = i; return res; }
    int[] ar(int n) { return ar(0, n); }
    void viet(Object...os) { System.err.println(Arrays.deepToString(os)); }
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;

    String nextStr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }

    int nextInt() {
        return Integer.parseInt(nextStr());
    }

    long nextLong() {
        return Long.parseLong(nextStr());
    }

    double nextDouble() {
        return Double.parseDouble(nextStr());
    }

    public static void main(String[] args) {
        new BaiC().run();
    }
}