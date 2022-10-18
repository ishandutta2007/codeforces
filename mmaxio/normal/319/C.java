import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class cf189Cwa3 {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static class Line {
        long y0, k;

        public Line(long y0, long k) {
            this.y0 = y0;
            this.k = k;
        }

        @Override
        public String toString() {
            return y0 + "+" + k + "x";
        }

        long det(Line o) {
            return y0 * o.k - k * o.y0;
        }

        BigInteger bigDet(Line o) {
            return BigInteger
                    .valueOf(y0)
                    .multiply(BigInteger.valueOf(o.k))
                    .subtract(
                            BigInteger.valueOf(k).multiply(
                                    BigInteger.valueOf(o.y0)));
        }

        Rational inter(Line o) {
            return new Rational(y0 - o.y0, o.k - k);
        }

    }

    static boolean badTurn(Line a, Line b, Line c) {
//      long d = a.det(b) + b.det(c) + c.det(a);
        BigInteger bigD = a.bigDet(b).add(b.bigDet(c)).add(c.bigDet(a));
//      if (bigD.compareTo(BigInteger.valueOf(d)) != 0)
//              System.err.println("!");
        return bigD.signum() <= 0;
    }

    static long solveFast(int[] h, int[] c) throws IOException {
        int n = h.length;

        List<Line> best = new ArrayList<>();
        List<Rational> inter = new ArrayList<>();

        best.add(new Line(0, c[0]));

        // System.err.println(best.get(0));

        long[] dp = new long[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = Long.MAX_VALUE;

            Rational curH = new Rational(h[i], 1);
            int pos = Collections.binarySearch(inter, curH);

            int j = (pos < 0) ? (~pos) : pos;
            Line from = best.get(j);
            dp[i + 1] = from.y0 + from.k * h[i];

            // System.err.println(j + " " + bestJ);

            if (i != n - 1) {
                Line add = new Line(dp[i + 1], c[i + 1]);
                while (best.size() > 1
                        && badTurn(best.get(best.size() - 2),
                                best.get(best.size() - 1), add)) {
                    best.remove(best.size() - 1);
                    inter.remove(inter.size() - 1);
                }
                inter.add(best.get(best.size() - 1).inter(add));
                best.add(add);

            }
            // System.err.println(best);
            // System.err.println(inter);
        }
        return dp[n];
    }

    static long solveSlow(int[] h, int[] c) throws IOException {
        int n = h.length;

        long[] dp = new long[n + 1];
        for (int i = 0; i < n; i++) {

            // DEBUG
            int bestJ = -1;
            long minVal = Long.MAX_VALUE;
            for (int j = 0; j <= i; j++) {
                long val = dp[j] + (long) c[j] * h[i];
                if (val < minVal) {
                    minVal = val;
                    bestJ = j;
                }
                dp[i + 1] = minVal;
            }

        }
        return dp[n];
    }

    static public class Rational implements Comparable<Rational> {
        long a, b;

        public Rational(long a, long b) {
            // b > 0!
            if (b < 0) {
                b = -b;
                a = -a;
            }
            long gcd = gcd(Math.abs(a), b);
            this.a = a / gcd;
            this.b = b / gcd;
        }

        public Rational negate() {
            return new Rational(-a, b);
        }

        @Override
        public int compareTo(Rational o) {
            long val1 = a * o.b;
            long val2 = b * o.a;
            if (val1 != val2)
                return val1 < val2 ? -1 : 1;
            return 0;
        }

        @Override
        public String toString() {
            return a + "/" + b;
        }

        @Override
        public boolean equals(Object obj) {
            Rational other = (Rational) obj;
            return a == other.a && b == other.b;
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static final boolean RANDOM_INPUT = false;
    static final Random rng = new Random();

    cf189Cwa3() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        int n;
        int[] h, c;

        if (RANDOM_INPUT) {
            int maxN = 5000;// 50;
            int maxVal = 1_000_000_000;// 1_000_000_000;
            n = rng.nextInt(maxN);
            h = new int[n];
            genH: do {
                for (int i = 0; i < n; i++) {
                    h[i] = rng.nextInt(maxVal + 1 - 2) + 2;
                }
                Arrays.sort(h);
                for (int i = 0; i < n - 1; i++)
                    if (h[i] == h[i + 1])
                        continue genH;
            } while (false);

            c = new int[n];
            genC: do {
                for (int i = 0; i < n; i++) {
                    c[i] = rng.nextInt(maxVal + 1 - 1) + 1;
                }
                Arrays.sort(c);
                for (int l = 0, r = n - 1; l < r; l++, r--) {
                    int tmp = c[l];
                    c[l] = c[r];
                    c[r] = tmp;
                }
                for (int i = 0; i < n - 1; i++)
                    if (c[i] == c[i + 1])
                        continue genC;
            } while (false);
        } else {
            n = nextInt() - 1;
            nextInt();
            h = new int[n];
            for (int i = 0; i < n; i++) {
                h[i] = nextInt();
            }

            c = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = nextInt();
            }
            nextInt();
        }

//      long ansFast = solveFast(h, c);
//      long ansSlow = solveSlow(h, c);
//      if (ansFast != ansSlow) {
//          // System.err.println(ansFast + " vs " + ansSlow);
//          // System.err.println(n);
//          // System.err.println(Arrays.toString(h));
//          // System.err.println(Arrays.toString(c));
//      } else {
//          out.println(ansFast);
//      }
        
        out.println(solveFast(h, c));
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new cf189Cwa3();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}