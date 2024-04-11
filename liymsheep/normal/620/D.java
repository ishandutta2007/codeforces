import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int m = in.nextInt();
            int[] b = in.nextIntArray(m);

            long sa = 0, sb = 0;
            for (int i = 0; i < n; ++i) {
                sa += a[i];
            }
            for (int i = 0; i < m; ++i) {
                sb += b[i];
            }

            long bestAnswer = Math.abs(sa - sb);
            int[][] ways = new int[0][];

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    long newSa = sa - a[i] + b[j];
                    long newSb = sb + a[i] - b[j];
                    if (Math.abs(newSa - newSb) < bestAnswer) {
                        bestAnswer = Math.abs(newSa - newSb);
                        ways = new int[][]{new int[]{i, j}};
                    }
                }
            }

            Record[] index = new Record[m * (m - 1) / 2];
            int last = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    index[last++] = new Record(b[i] + b[j], i, j);
                }
            }
            Arrays.sort(index);
            for (int i = 0; i < n && m >= 2; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    long newSa = sa - a[i] - a[j];
                    long newSb = sb + a[i] + a[j];

                    long delta = newSb - newSa;
                    // <= >
                    if (delta > 0) {
                        delta /= 2;
                    } else {
                        delta = -((-delta + 1) / 2);
                    }

                    {
                        int low = 0, high = index.length - 1;
                        while (low < high) {
                            int mid = ((low + high) >> 1) + 1;
                            if (index[mid].sum <= delta) {
                                low = mid;
                            } else {
                                high = mid - 1;
                            }
                        }
                        {
                            newSa += index[low].sum;
                            newSb -= index[low].sum;
                            if (Math.abs(newSa - newSb) < bestAnswer) {
                                bestAnswer = Math.abs(newSa - newSb);
                                ways = new int[][]{new int[]{i, index[low].i},
                                        new int[]{j, index[low].j}};
                            }
                            newSa -= index[low].sum;
                            newSb += index[low].sum;
                        }
                    }


                    {
                        int low = 0, high = index.length - 1;
                        while (low < high) {
                            int mid = (low + high) >> 1;
                            if (index[mid].sum > delta) {
                                high = mid;
                            } else {
                                low = mid + 1;
                            }
                        }
                        {
                            newSa += index[low].sum;
                            newSb -= index[low].sum;
                            if (Math.abs(newSa - newSb) < bestAnswer) {
                                bestAnswer = Math.abs(newSa - newSb);
                                ways = new int[][]{new int[]{i, index[low].i},
                                        new int[]{j, index[low].j}};
                            }
                            newSa -= index[low].sum;
                            newSb += index[low].sum;
                        }
                    }
                }
            }

            out.println(bestAnswer);
            out.println(ways.length);
            for (int[] way : ways) {
                out.println((way[0] + 1) + " " + (way[1] + 1));
            }
        }

        private class Record implements Comparable<Record> {
            long sum;
            int i;
            int j;

            Record(long sum, int i, int j) {
                this.sum = sum;
                this.i = i;
                this.j = j;
            }


            public int compareTo(Record o) {
                return Long.compare(sum, o.sum);
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray(int size) {
            int[] result = new int[size];
            for (int i = 0; i < size; ++i) {
                result[i] = nextInt();
            }
            return result;
        }

    }
}