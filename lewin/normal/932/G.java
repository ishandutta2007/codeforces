import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.File;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public int mod = 1_000_000_007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.next();
            int n = s.length();
            String s1 = s.substring(0, n / 2), s2 = s.substring(n / 2);
            char[] ns = new char[n];
            for (int i = 0; i < n; i += 2) {
                ns[i] = s1.charAt(i / 2);
                ns[i + 1] = s2.charAt(n / 2 - i / 2 - 1);
            }
//        boolean[][] pal = new boolean[n][n];
//        for (int len = 1; len <= n; len++) {
//            for (int start = 0; start + len - 1 < n; start++) {
//                int end = start + len - 1;
//                if (len == 1) pal[start][end] = true;
//                else if (len == 2) pal[start][end] = ns[start] == ns[end];
//                else pal[start][end] = pal[start+1][end-1] && ns[start] == ns[end];
//
//            }
//        }
//        long[] dp = new long[n+1];
//        dp[0] = 1;
//        for (int i = 1; i <= n; i++) {
//            for (int j = i-1; j >= 1; j -= 2) {
//                if (pal[j-1][i-1]) {
//                    dp[i] += dp[j-1];
//                    dp[i] %= mod;
//                }
//            }
//        }
//        out.println(dp[n]);
            out.println(go(ns));
        }

        int go(char[] s) {
            PalindromicTreeByArray pt = new PalindromicTreeByArray(s);

            int n = s.length;
            int[] sl = pt.slinks();
            int[] dp = new int[n + 1];
            int[] adp = new int[pt.gen];

            int cur = 1;
            dp[0] = 1;

            for (int i = 0; i < n; i++) {
                char x = s[i];
                while (i - pt.lens[cur] - 1 < 0 || s[i - pt.lens[cur] - 1] != x) cur = pt.links[cur]; // find xAx
                int xax = pt.next(x, cur); // already exists

                for (int j = xax; j > 1; j = sl[j]) {
                    int lenSeriesFirst = pt.lens[sl[j]] + (pt.lens[j] - pt.lens[pt.links[j]]);
                    adp[j] = dp[i + 1 - lenSeriesFirst];

                    if (sl[j] != pt.links[j]) {
                        adp[j] += adp[pt.links[j]];
                        adp[j] %= mod;
                    }

                    if (i % 2 == 1) {
                        dp[i + 1] += adp[j];
                        dp[i + 1] %= mod;
                    }
                }
                cur = xax;
                Debug.print(i, dp[i + 1]);
            }
            return dp[n];
        }

        public class PalindromicTreeByArray {
            int[] firsts;
            int[] lens;
            int[] freqs;
            int[] firstChilds;
            int[] nexts;
            int[] links;
            char[] cs;
            int gen;

            int[] slinks() {
                int[] slinks = new int[gen];
                Arrays.fill(slinks, 1);
                for (int i = 2; i < gen; i++) {
                    if (lens[i] - lens[links[i]] == lens[links[i]] - lens[links[links[i]]]) {
                        slinks[i] = slinks[links[i]];
                    } else {
                        slinks[i] = links[i];
                    }
                }
                return slinks;
            }

            public PalindromicTreeByArray(char[] s) {
                build(s);
            }

            public int newNode(int first, int len, char c) {
                firsts[gen] = first;
                lens[gen] = len;
                cs[gen] = c;
                freqs[gen] = 0;
                firstChilds[gen] = -1;
                links[gen] = -1;
                nexts[gen] = -1;
                return gen++;
            }

            public int next(char x, int id) {
                for (int ch = firstChilds[id]; ch != -1; ch = nexts[ch]) {
                    if (cs[ch] == x) return ch;
                }
                return -1;
            }

            public void add(int x, int id) {
                int ch = firstChilds[id];
                firstChilds[id] = x;
                nexts[x] = ch;
            }

            public void build(char[] s) {
                assert gen == 0;
                int n = s.length;

                firsts = new int[n + 2];
                lens = new int[n + 2];
                freqs = new int[n + 2];
                firstChilds = new int[n + 2];
                nexts = new int[n + 2];
                links = new int[n + 2];
                cs = new char[n + 2];

                int hell = newNode(-1, -1, (char) 0);
                int zero = newNode(-1, 0, (char) 0);
                assert hell == 0;
                assert zero == 1;
                links[zero] = hell;
                links[hell] = hell;
                add(zero, hell);

                int cur = zero; // current suffix palindrome
                for (int i = 0; i < n; i++) {
                    char x = s[i];
                    while (i - lens[cur] - 1 < 0 || s[i - lens[cur] - 1] != x) cur = links[cur]; // find xAx
                    int xax = next(x, cur); // already exists
                    if (xax == -1) {
                        // new subpalindrome
                        xax = newNode(i - lens[cur] - 1, lens[cur] + 2, x);
                        add(xax, cur);

                        // make suffix link
                        if (lens[xax] == 1) {
                            links[xax] = zero;
                        } else {
                            int b = links[cur];
                            while (true) {
                                while (i - lens[b] - 1 < 0 || s[i - lens[b] - 1] != x) b = links[b]; // find xBx
                                int xbx = next(x, b);
                                if (xbx != -1) {
                                    links[xax] = xbx;
                                    break;
                                }
                            }
                        }
                    }

                    // [i-cur.len-1, i]
                    freqs[xax]++; // increment regardless new or not

                    cur = xax;
                }

                for (int i = gen - 1; i >= 2; i--) {
                    freqs[links[i]] += freqs[i];
                }
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class Debug {
        public static boolean DEBUG;

        static {
            try {
                DEBUG = System.getProperty("user.dir").contains("Dropbox");
            } catch (Exception e) {
                DEBUG = false;
            }
        }

        private static ArrayList<String> getParams() {
            StackTraceElement[] t = new Exception().getStackTrace();
            StackTraceElement up = t[2];

            ArrayList<String> ret = new ArrayList<>();
            ret.add(up.getFileName() + "/" + up.getMethodName());
            try {
                BufferedReader br = new BufferedReader(new FileReader(
                        new File("src/" + up.getClassName().replaceAll("\\.", "/") + ".java")));
                int g = up.getLineNumber();
                while (--g > 0) br.readLine();
                String q = br.readLine();
                String[] ss = q.split("Debug\\.print\\(");
                String[] qq = ss[1].substring(0, ss[1].indexOf(")")).split(",");
                for (int i = 0; i < qq.length; i++) {
                    ret.add(qq[i].trim());
                }
            } catch (Exception e) {
            }
            for (int i = 0; i < 100; i++) ret.add("???");
            return ret;
        }

        private static String toString(Object o) {
            if (o instanceof Object[]) {
                return Arrays.toString((Object[]) o);
            } else if (o instanceof char[]) {
                return new String((char[]) o);
            } else if (o instanceof int[]) {
                return Arrays.toString((int[]) o);
            } else if (o instanceof long[]) {
                return Arrays.toString((long[]) o);
            } else if (o instanceof double[]) {
                return Arrays.toString((double[]) o);
            } else {
                return o.toString();
            }
        }

        public static void print(Object... x) {
            if (!DEBUG) return;
            ArrayList<String> s = getParams();
            System.out.print(s.get(0) + ": ");
            for (int i = 0; i < x.length; i++) {
                System.out.print(s.get(i + 1) + " = " + toString(x[i]));
                if (i != x.length - 1) System.out.print(", ");
            }
            System.out.println();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}