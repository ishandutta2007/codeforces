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
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FChoosingTwoPaths solver = new FChoosingTwoPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class FChoosingTwoPaths {
        int n;
        List<Integer>[] graph;
        boolean[] safe;
        boolean[] removed;
        int[][] bts;
        int[] down;
        int[] up;
        int[] fup;
        int[] fdown;
        int[] fupid;
        int[] fdownid;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            safe = new boolean[n];
            for (int i = 0; i < n; i++) {
                safe[i] = graph[i].size() >= 3;
            }

            Debug.print(safe);
            removed = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (graph[i].size() == 1) {
                    int prev = -1;
                    int cur = i;
                    while (true) {
                        removed[cur] = true;
                        int x = -1;
                        for (int nxt : graph[cur]) {
                            if (nxt != prev) {
                                x = nxt;
                                break;
                            }
                        }
                        if (x == -1 || safe[x]) break;
                        prev = cur;
                        cur = x;
                    }
                }
            }

            bts = new int[n][];
            for (int i = 0; i < n; i++) {
                if (!removed[i]) {
                    bts[i] = dfs3(i, -1);
                }
            }
            down = new int[n];
            up = new int[n];
            fup = new int[n];
            fdown = new int[n];
            fupid = new int[n];
            fdown = new int[n];
            fdownid = new int[n];
            for (int i = 0; i < n; i++) {
                if (!removed[i]) {
                    dfs(i, -1);
                    dfs2(i, -1, 0, -1, -1);
                    break;
                }
            }
            int[] ret = new int[n];
            int[] f = new int[n];
            int[] fid = new int[n];
            for (int i = 0; i < n; i++) {
                if (up[i] > down[i] || (up[i] == down[i] && fup[i] > fdown[i])) {
                    ret[i] = up[i];
                    f[i] = fup[i];
                    fid[i] = fupid[i];
                } else {
                    ret[i] = down[i];
                    f[i] = fdown[i];
                    fid[i] = fdownid[i];
                }
                Debug.print(i, bts[i], ret[i], f[i], fid[i]);
            }
            int mx = AUtils.max(ret);
            int bestsum = 1, id1 = -1, id2 = -1;
            for (int i = 0; i < n; i++) {
                if (ret[i] == mx) {
                    if (f[i] + bts[i][1] + bts[i][3] > bestsum) {
                        bestsum = f[i] + bts[i][1] + bts[i][3];
                        id1 = i;
                        id2 = fid[i];
                    }
                }
            }

            Debug.print(mx, bestsum, id1, id2);
            out.println((bts[id1][0] + 1) + " " + (bts[id2][0] + 1));
            out.println((bts[id1][2] + 1) + " " + (bts[id2][2] + 1));
        }

        int[] dfs3(int node, int par) {
            int x1 = node, x2 = -1, d1 = 0, d2 = 0;
            if (graph[node].size() > 1) x1 = -1;
            for (int next : graph[node]) {
                if (next == par || !removed[next]) continue;
                int[] q = dfs3(next, node);
                for (int i = 0; i < 2; i++) {
                    int cx = q[0 + 2 * i], cd = q[1 + 2 * i];
                    if (cx == -1) continue;
                    if (cd + 1 > d1) {
                        x2 = x1;
                        d2 = d1;
                        x1 = cx;
                        d1 = cd + 1;
                    } else if (cd + 1 > d2) {
                        x2 = cx;
                        d2 = cd + 1;
                    }
                }
            }
            return new int[]{x1, d1, x2, d2};
        }

        public void dfs(int node, int par) {
            fdown[node] = bts[node][1] + bts[node][3];
            fdownid[node] = node;
            for (int next : graph[node]) {
                if (next == par || removed[next]) continue;
                dfs(next, node);
                if (down[next] + 1 > down[node]) {
                    fdown[node] = fdown[next];
                    fdownid[node] = fdownid[next];
                    down[node] = down[next] + 1;
                } else if (down[next] + 1 == down[node] && fdown[node] < fdown[next]) {
                    fdown[node] = fdown[next];
                    fdownid[node] = fdownid[next];
                    down[node] = down[next] + 1;
                }
            }
        }

        public void dfs2(int node, int par, int frompar, int fromparf, int fromparid) {
            up[node] = frompar;
            fup[node] = fromparf;
            fupid[node] = fromparid;

            int mx1 = 0, id1 = -1, mx2 = 0;
            int fmx1 = 0, fmx1id = -1, fmx2 = 0, fmx2id = -1;
            for (int next : graph[node]) {
                if (next == par || removed[next]) continue;
                if (down[next] + 1 > mx1) {
                    mx2 = mx1;
                    fmx2id = fmx1id;
                    fmx2 = fmx1;
                    mx1 = down[next] + 1;
                    id1 = next;
                    fmx1 = fdown[next];
                    fmx1id = fdownid[next];
                } else if (down[next] + 1 == mx1 && fdown[next] > fmx1) {
                    mx2 = mx1;
                    fmx2id = fmx1id;
                    fmx2 = fmx1;
                    mx1 = down[next] + 1;
                    id1 = next;
                    fmx1 = fdown[next];
                    fmx1id = fdownid[next];
                } else if (down[next] + 1 > mx2) {
                    mx2 = down[next] + 1;
                    fmx2 = fdown[next];
                    fmx2id = fdownid[next];
                } else if (down[next] + 1 == mx2 && fdown[next] > fmx2) {
                    fmx2 = fdown[next];
                    fmx2id = fdownid[next];
                }
            }

            for (int next : graph[node]) {
                if (next == par || removed[next]) continue;
                int dmx, fmx, fmxid;
                if (next != id1) {
                    dmx = mx1;
                    fmx = fmx1;
                    fmxid = fmx1id;
                } else {
                    dmx = mx2;
                    fmx = fmx2;
                    fmxid = fmx2id;
                }
                if (up[node] > dmx) {
                    dmx = up[node];
                    fmx = fromparf;
                    fmxid = fromparid;
                } else if (dmx == up[node] && fromparf > fmx) {
                    dmx = up[node];
                    fmx = fromparf;
                    fmxid = fromparid;
                }
                dfs2(next, node, dmx + 1, fmx, fmxid);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
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

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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
            StackTraceElement[] t = Thread.currentThread().getStackTrace();
            StackTraceElement up = t[3];

            ArrayList<String> ret = new ArrayList<>();
            String qqq = up.toString();
            ret.add("." + up.getMethodName() + qqq.substring(qqq.indexOf("("), qqq.length()));
            try {
                BufferedReader br = new BufferedReader(new FileReader(
                        new File("src/" + up.getClassName().replaceAll("\\.", "/") + ".java")));
                int g = up.getLineNumber();
                while (--g > 0) br.readLine();
                String q = br.readLine();
                String[] ss = q.split("Debug\\.print\\(");
                String[] qq = ss[1].substring(0, ss[1].lastIndexOf(")")).split(",");
                for (int i = 0; i < qq.length; i++) {
                    ret.add(qq[i].trim());
                }
            } catch (Exception e) {
            }
            for (int i = 0; i < 100; i++) ret.add("???");
            return ret;
        }

        private static String toString(Object o) {
            if (o == null) {
                return "null";
            } else if (o instanceof Object[]) {
                return Arrays.toString((Object[]) o);
            } else if (o instanceof char[]) {
                return new String((char[]) o);
            } else if (o instanceof int[]) {
                return Arrays.toString((int[]) o);
            } else if (o instanceof long[]) {
                return Arrays.toString((long[]) o);
            } else if (o instanceof double[]) {
                return Arrays.toString((double[]) o);
            } else if (o instanceof boolean[]) {
                return Arrays.toString((boolean[]) o);
            } else {
                return o.toString();
            }
        }

        public static void print(Object x) {
            if (!DEBUG) return;
            ArrayList<String> s = getParams();
            System.out.println(s.get(0) + ": " + s.get(1) + " = " + toString(x));
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

    static class AUtils {
        public static int max(int[] arr) {
            int res = arr[0];
            for (int x : arr) if (x > res) res = x;
            return res;
        }

    }
}