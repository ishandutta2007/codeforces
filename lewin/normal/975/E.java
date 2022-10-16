import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        double[][] getrot(double angle) {
            double c = Math.cos(angle), s = Math.sin(angle);
            double[][] x = {
                    {c, -s, 0},
                    {s, c, 0},
                    {0, 0, 1}
            };
            return x;
        }

        double[][] getshift(double dx, double dy) {
            double[][] x = {
                    {1, 0, dx},
                    {0, 1, dy},
                    {0, 0, 1}
            };
            return x;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            double[] x = new double[n + 1];
            double[] y = new double[n + 1];
            double[][] pp = new double[n + 1][3];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            double x1 = x[0], x2 = x[0], y1 = y[0], y2 = y[0];
            for (int i = 0; i < n; i++) {
                x1 = Math.min(x1, x[i]);
                x2 = Math.max(x2, x[i]);
                y1 = Math.min(y1, y[1]);
                y2 = Math.max(y2, y[i]);
            }
            double ax = (x1 + x2) / 2.0, ay = (y1 + y2) / 2.0;
            for (int i = 0; i < n; i++) {
                x[i] -= ax;
                y[i] -= ay;
                pp[i] = new double[]{x[i], y[i], 1};
            }
            x[n] = x[0];
            y[n] = y[0];
            double cx = 0, cy = 0;
            double a = 0;
            for (int i = 0; i < n; i++) {
                double r = x[i] * y[i + 1] - x[i + 1] * y[i];
                a += r;
            }
            a /= 2.0;
            for (int i = 0; i < n; i++) {
                double r = (x[i] * y[i + 1] - x[i + 1] * y[i]) / 6.0 / a;
                cx += (x[i] + x[i + 1]) * r;
                cy += (y[i] + y[i + 1]) * r;
            }

            double[] cc = new double[]{0, 0, 1};
            for (int i = 0; i < n; i++) {
                pp[i][0] -= cx;
                pp[i][1] -= cy;
            }

            ax += cx;
            ay += cy;

            double[][] mat = {
                    {1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}
            };

            int p1 = 0, p2 = 1;
            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int f = in.nextInt() - 1, t = in.nextInt() - 1;
                    int fx = f == p1 ? p2 : p1;
                    if (f == p1) p1 = t;
                    else p2 = t;
                    double[] nc = MatrixOperations.vec_mult(mat, cc);
                    double[] nt = MatrixOperations.vec_mult(mat, pp[fx]);

                    double gx = nc[0] - nt[0], gy = nc[1] - nt[1];
                    double ang = -Math.atan2(gx, -gy);
                    mat = MatrixOperations.matrix_mult(getshift(-nt[0], -nt[1]), mat);
                    mat = MatrixOperations.matrix_mult(getrot(ang), mat);
                    mat = MatrixOperations.matrix_mult(getshift(nt[0], nt[1]), mat);
                } else {
                    int v = in.nextInt() - 1;
                    double[] pt = MatrixOperations.vec_mult(mat, pp[v]);
                    out.printf("%.15f %.15f\n", pt[0] + ax, pt[1] + ay);
                }
                if (q % 100 == 0) {
                    for (int j = 0; j < n; j++) {
                        pp[j] = MatrixOperations.vec_mult(mat, pp[j]);
                    }
                    cc = MatrixOperations.vec_mult(mat, cc);
                    for (int i = 0; i < n; i++) {
                        pp[i][0] -= cc[0];
                        pp[i][1] -= cc[1];
                    }

                    ax += cc[0];
                    ay += cc[1];

                    cc[0] = 0; cc[1] = 0;
                    mat = new double[][]{
                            {1, 0, 0},
                            {0, 1, 0},
                            {0, 0, 1}
                    };
                }
            }
        }

    }

    static class MatrixOperations {
        public static double[][] matrix_mult(double[][] A, double[][] B) {
            double[][] C = new double[A.length][A.length];
            for (int i = 0; i < A.length; i++)
                for (int j = 0; j < A.length; j++)
                    for (int k = 0; k < A.length; k++)
                        C[i][k] = (C[i][k] + A[i][j] * B[j][k]);
            return C;
        }

        public static double[] vec_mult(double[][] A, double[] B) {
            double[] C = new double[A.length];
            for (int i = 0; i < A.length; i++) {
                for (int j = 0; j < B.length; j++) {
                    C[i] = (C[i] + A[i][j] * B[j]);
                }
            }
            return C;
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }
}