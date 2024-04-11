import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DForeigner solver = new DForeigner();
        solver.solve(1, in, out);
        out.close();
    }

    static class DForeigner {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            int n = s.length;

            long count = 0;
            int[] reach = new int[11];
            Arrays.fill(reach, n);
            for (int j = s.length - 1; j >= 0; j--) {
                int[] nreach = new int[11];
                for (int pnum = 0; pnum < 11; pnum++) {
                    if (s[j] - '0' >= pnum) {
                        nreach[pnum] = j;
                    } else {
                        int nnum = 10 + s[j] - '0';
                        for (int k = 0; k < pnum; k++) {
                            nnum += k;
                        }
                        nnum %= 11;
                        nreach[pnum] = reach[nnum];
                    }
                }
                if (s[j] != '0') count += reach[s[j] - '0'] - j;
                reach = nreach;
            }
            out.println(count);
//        for (int i = 0; i < s.length; i++) {
//            if (s[i] == '0') continue;
//
//            int cdig = s[i]-'0';
//            int num = cdig;
//            count++;
//            for (int j = i+1; j < s.length; j++) {
//                if (s[j]-'0' >= num) {
//                    break;
//                }
//                count++;
//                int nnum = 10 + s[j]-'0';
//                for (int k = 0; k < num; k++) {
//                    nnum += k;
//                }
//                nnum %= 11;
//                num = nnum;
//            }
//        }
//        out.println(count);
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