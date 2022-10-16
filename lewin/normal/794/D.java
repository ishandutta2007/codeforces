import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public List<Integer>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList(n);
            long[] xor1 = new long[n];
            long[] xor2 = new long[n];
            long[] r1 = new long[n];
            long[] r2 = new long[n];
            Random r = new Random(1231);
            for (int i = 0; i < n; i++) {
                r1[i] = r.nextLong();
                r2[i] = r.nextLong();
            }
            for (int i = 0; i < n; i++) {
                xor1[i] = r1[i];
                xor2[i] = r2[i];
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
                xor1[a] ^= r1[b];
                xor1[b] ^= r1[a];
                xor2[a] ^= r2[b];
                xor2[b] ^= r2[a];
            }
            Pair<Long, Long>[] p = new Pair[n];
            for (int i = 0; i < n; i++) {
                p[i] = new Pair<>(xor1[i], xor2[i]);
            }
            HashMap<Pair<Long, Long>, ArrayList<Integer>> mp = new HashMap<>();
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> x = mp.get(p[i]);
                if (x == null) mp.put(p[i], x = new ArrayList<>());
                x.add(i);
            }

            HashMap<Pair<Long, Long>, HashMap<Pair<Long, Long>, Integer>> g2 = new HashMap<>();
            boolean[] done = new boolean[1];
            done[0] = false;
            Pair<Long, Long>[] end = new Pair[1];
            mp.forEach((ck, v) -> {
                HashMap<Pair<Long, Long>, Integer> a;
                g2.put(ck, a = new HashMap<>());
                a.put(ck, 0);
                for (int ww : v) {
                    for (int x : graph[ww]) {
                        a.merge(p[x], 1, Integer::sum);
                    }
                }
                long w = v.size();
                if (w * (w - 1) != a.get(ck)) {
                    done[0] = true;
                    return;
                }
                if (a.size() > 3) {
                    done[0] = true;
                    return;
                }
                if (a.size() <= 2) {
                    end[0] = ck;
                }

                for (Map.Entry<Pair<Long, Long>, Integer> e : a.entrySet()) {
                    if (e.getKey().equals(ck)) continue;
                    int sz1 = mp.get(e.getKey()).size();
                    if (1L * sz1 * v.size() != e.getValue()) {
                        done[0] = true;
                        return;
                    }
                }

            });
            if (done[0] || end[0] == null) {
                out.println("NO");
                return;
            }

            int[] res = new int[n];
            out.println("YES");
            HashSet<Pair<Long, Long>> seen = new HashSet<>();
            int cptr = 0;
            while (end[0] != null) {
                cptr++;
                seen.add(end[0]);
                for (int x : mp.get(end[0])) {
                    res[x] = cptr;
                }
                Pair[] nxt = new Pair[1];
                g2.get(end[0]).forEach((k, v) -> {
                    if (!seen.contains(k)) {
                        nxt[0] = k;
                        return;
                    }
                });
                end[0] = nxt[0];
            }
            out.println(res);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}