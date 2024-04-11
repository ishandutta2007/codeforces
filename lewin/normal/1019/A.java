import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        AElections solver = new AElections();
        solver.solve(1, in, out);
        out.close();
    }

    static class AElections {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] p = new int[n], c = new int[n];
            List<Integer>[] ch = LUtils.genArrayList(m);
            List<Long>[] psum = LUtils.genArrayList(m);
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt() - 1;
                c[i] = in.nextInt();

                ch[p[i]].add(c[i]);
            }
            for (int i = 1; i < m; i++) {
                Collections.sort(ch[i]);
                psum[i].add(0L);
                for (int j = 1; j <= ch[i].size(); j++) {
                    long x = ch[i].get(j - 1) + psum[i].get(j - 1);
                    psum[i].add(x);
                }
            }
            long ans = Long.MAX_VALUE;
            for (int ss = 1; ss <= n; ss++) {
                int have = ch[0].size();
                long ccost = 0;
                ArrayList<Integer> rr = new ArrayList<>();
                for (int i = 1; i < m; i++) {
                    if (ch[i].size() >= ss) {
                        int take = ch[i].size() - ss + 1;
                        ccost += psum[i].get(take);
                        have += take;
                        for (int k = take; k < ch[i].size(); k++) {
                            rr.add(ch[i].get(k));
                        }
                    } else {
                        rr.addAll(ch[i]);
                    }
                }
                Collections.sort(rr);
                int id = 0;
                while (id < rr.size() && have < ss) {
                    ccost += rr.get(id++);
                    have++;
                }
                if (have >= ss) {
                    ans = Math.min(ans, ccost);
                }
            }
            out.println(ans);
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}