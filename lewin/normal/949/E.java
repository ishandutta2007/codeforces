import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        HashMap<Integer, ArrayList<Integer>> mp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            HashSet<Integer> get = new HashSet<>();
            for (int x : arr) get.add(x);
            mp = new HashMap<>();
            ArrayList<Integer> ans = solve(get);

            out.println(ans.size());
            boolean first = true;
            for (int k : ans) {
                if (!first) out.print(" ");
                out.print(k);
                first = false;
            }
            out.println();
        }

        int getHash(HashSet<Integer> tt) {
            ArrayList<Integer> r = new ArrayList<>(tt);
            Collections.sort(r);
            int hs = 0;
            for (int x : r) {
                hs = hs * 34112131 + x;
            }
            return hs;
        }

        ArrayList<Integer> solve(HashSet<Integer> tt) {
            int key = getHash(tt);
            ArrayList<Integer> res = mp.get(key);
            if (res != null) return res;

            ArrayList<Integer> r = new ArrayList<>(tt);
            if (tt.size() == 1) {
                if (r.get(0) == 0) {
                    return new ArrayList<>();
                }
            }


            boolean hasodd = false;
            for (int x : r) {
                if (x % 2 != 0) {
                    hasodd = true;
                }
            }
            if (hasodd) {
                ArrayList<Integer> best = null;
                // add 1
                {
                    HashSet<Integer> nxt = new HashSet<>();
                    for (int x : r) {
                        if (x % 2 != 0) {
                            nxt.add((x - 1) / 2);
                        } else {
                            nxt.add(x / 2);
                        }
                    }

                    int q = getHash(nxt);
                    if (q != key) {
                        ArrayList<Integer> ans = new ArrayList<>(solve(nxt));
                        for (int i = 0; i < ans.size(); i++) {
                            ans.set(i, ans.get(i) * 2);
                        }
                        ans.add(1);
                        best = ans;
                    }
                }
                // add -1
                {
                    HashSet<Integer> nxt = new HashSet<>();
                    for (int x : r) {
                        if (x % 2 != 0) {
                            nxt.add((x + 1) / 2);
                        } else {
                            nxt.add(x / 2);
                        }
                    }

                    int q = getHash(nxt);
                    if (q != key) {
                        ArrayList<Integer> ans = new ArrayList<>(solve(nxt));
                        for (int i = 0; i < ans.size(); i++) {
                            ans.set(i, ans.get(i) * 2);
                        }
                        ans.add(-1);
                        if (best == null || ans.size() < best.size()) best = ans;
                    }
                }
                mp.put(key, best);
                return best;
            } else {
                HashSet<Integer> nxt = new HashSet<>();
                for (int x : r) {
                    nxt.add(x / 2);
                }
                ArrayList<Integer> ans = new ArrayList<>(solve(nxt));
                for (int i = 0; i < ans.size(); i++) {
                    ans.set(i, ans.get(i) * 2);
                }
                mp.put(key, ans);
                return ans;
            }
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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
}