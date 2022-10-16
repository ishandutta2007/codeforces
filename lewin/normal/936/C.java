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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        List<Integer> moves;

        char[] move(int idx, char[] c) {
            if (idx <= 0) {
                return c;
            }
            moves.add(idx);
            char[] nxt = new char[c.length];
            for (int i = 0; i < idx; i++) {
                nxt[i] = c[c.length - i - 1];
            }
            for (int i = idx; i < c.length; i++) {
                nxt[i] = c[i - idx];
            }
            return nxt;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] s1 = in.next().toCharArray();
            char[] s2 = in.next().toCharArray();
            int[] f = new int[26];
            for (int i = 0; i < n; i++) {
                f[s1[i] - 'a']++;
                f[s2[i] - 'a']--;
            }
            for (int i = 0; i < 26; i++) {
                if (f[i] != 0) {
                    out.println(-1);
                    return;
                }
            }

            moves = new ArrayList<>();
            boolean back = true;
            int h = n / 2;

            for (int i = 0; i < n; i++) {
                int want;
                if (i % 2 == 0) {
                    want = h - (i / 2) - (1 - (n % 2));
                } else {
                    want = h + (i / 2) + (n % 2);
                }
                for (int j = i; j < n; j++) {
                    if (s1[j] == s2[want]) {
                        s1 = move(n - j, s1);
                        s1 = move(n - i - (n - j), s1);
                        s1 = move(n, s1);
                        break;
                    }
                }

                Debug.print(moves, i, want, s1, s2);
            }
            if (n % 2 == 1) s1 = move(n, s1);
//        for (int suffix = n-1; suffix >= 0; suffix--) {
//            if (back) {
//                if (s1[suffix] == s2[suffix]) continue;
//                for (int j = 0; j < suffix; j++) {
//                    if (s1[j] == s2[suffix]) {
//                        s1 = move(n-j-1, s1);
//                        s1 = move(j+1, s1);
//                        s1 = move(n-suffix-1, s1);
//                        break;
//                    }
//                }
//                back = !back;
//            } else {
//                if (s1[n-suffix-1] == s2[suffix]) continue;
//                for (int j = 0; j < suffix; j++) {
//                    if (s1[n-j-1] == s2[suffix]) {
//                        s1 = move(j, s1);
//                        s1 = move(n-j, s1);
//                        s1 = move(j, s1);
//                        break;
//                    }
//                }
//                back = !back;
//            }
//        }


            out.println(moves.size());
            boolean first = true;
            for (int j : moves) {
                if (!first) out.print(" ");
                first = false;
                out.print(j);
            }
            out.println();
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
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