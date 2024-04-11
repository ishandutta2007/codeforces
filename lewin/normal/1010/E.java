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
import java.util.TreeMap;
import java.util.Map;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        EStore solver = new EStore();
        solver.solve(1, in, out);
        out.close();
    }

    static class EStore {
        TreeMap<Integer, Integer>[] tmp;
        List<EStore.Point>[] pt;

        boolean contains(int lo, int hi, int m) {
            return lo <= m && m <= hi;
        }

        void insert(int idx, int x, int y) {
            int fx = (idx & 2) == 0 ? 1 : -1, fy = (idx & 1) == 0 ? 1 : -1;
            x *= fx;
            y *= fy;
            Map.Entry<Integer, Integer> kk = tmp[idx].floorEntry(x);
            if (kk.getValue() <= y) return;

            while (true) {
                Map.Entry<Integer, Integer> ck = tmp[idx].ceilingEntry(x);
                if (ck != null && ck.getValue() >= y) tmp[idx].remove(ck.getKey());
                else break;
            }
            tmp[idx].put(x, y);
        }

        String query(int idx, int x, int y) {
            int fx = (idx & 2) == 0 ? 1 : -1, fy = (idx & 1) == 0 ? 1 : -1;
            x *= fx;
            y *= fy;

            Map.Entry<Integer, Integer> kk = tmp[idx].floorEntry(x);
            if (kk.getValue() <= y) return "CLOSED";
            else return "UNKNOWN";
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int x = in.nextInt(), y = in.nextInt(), z = in.nextInt(), n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            int minx = x, maxx = 0, miny = y, maxy = 0, minz = z, maxz = 0;
            for (int i = 0; i < n; i++) {
                int xi = in.nextInt(), yi = in.nextInt(), zi = in.nextInt();
                minx = Math.min(minx, xi);
                maxx = Math.max(maxx, xi);
                miny = Math.min(miny, yi);
                maxy = Math.max(maxy, yi);
                minz = Math.min(minz, zi);
                maxz = Math.max(maxz, zi);
            }

            List<EStore.Point>[] pts = LUtils.genArrayList(z + 1);
            for (int i = 0; i < m; i++) {
                int xi = in.nextInt(), yi = in.nextInt(), zi = in.nextInt();
                if (contains(minx, maxx, xi) && contains(miny, maxy, yi) && contains(minz, maxz, zi)) {
                    out.println("INCORRECT");
                    return;
                }
                pts[zi].add(new EStore.Point(xi, yi));
            }
            List<EStore.Query>[] qs = LUtils.genArrayList(z + 1);
            String[] ans = new String[k];
            for (int i = 0; i < k; i++) {
                int xi = in.nextInt(), yi = in.nextInt(), zi = in.nextInt();
                if (contains(minx, maxx, xi) && contains(miny, maxy, yi) && contains(minz, maxz, zi)) {
                    ans[i] = "OPEN";
                } else {
                    if (m > 0) qs[zi].add(new EStore.Query(xi, yi, i));
                    else ans[i] = "UNKNOWN";
                }
            }

            {
                pt = LUtils.genArrayList(4);
                tmp = new TreeMap[4];
                for (int i = 0; i < 4; i++) tmp[i] = new TreeMap<>();
                for (int i = 0; i < 4; i++) tmp[i].put(-100000000, 100000000);
                int x1 = x, x2 = 0, y1 = y, y2 = 0;
                for (int zi = minz; zi <= maxz; zi++) {
                    for (EStore.Point p : pts[zi]) {
                        if (contains(minx, maxx, p.x)) {
                            if (p.y > maxy) y1 = Math.min(y1, p.y - 1);
                            if (p.y < miny) y2 = Math.max(y2, p.y + 1);
                        }
                        if (contains(miny, maxy, p.y)) {
                            if (p.x > maxx) x1 = Math.min(x1, p.x - 1);
                            if (p.x < minx) x2 = Math.max(x2, p.x + 1);
                        }
                        if (p.x > maxx && p.y > maxy) {
                            insert(0b00, p.x, p.y);
                        }
                        if (p.x > maxx && p.y < miny) {
                            insert(0b01, p.x, p.y);
                        }
                        if (p.x < minx && p.y > maxy) {
                            insert(0b10, p.x, p.y);
                        }
                        if (p.x < minx && p.y < miny) {
                            insert(0b11, p.x, p.y);
                        }
                    }
                }
                boolean badz = false;
                for (int zi = minz; zi <= z; zi++) {
                    for (EStore.Point p : pts[zi]) {
                        if (contains(minx, maxx, p.x) && contains(miny, maxy, p.y)) {
                            badz = true;
                            continue;
                        }
                        if (contains(minx, maxx, p.x)) {
                            if (p.y > maxy) y1 = Math.min(y1, p.y - 1);
                            if (p.y < miny) y2 = Math.max(y2, p.y + 1);
                            continue;
                        }
                        if (contains(miny, maxy, p.y)) {
                            if (p.x > maxx) x1 = Math.min(x1, p.x - 1);
                            if (p.x < minx) x2 = Math.max(x2, p.x + 1);
                            continue;
                        }
                        if (p.x > maxx && p.y > maxy) {
                            insert(0b00, p.x, p.y);
                        }
                        if (p.x > maxx && p.y < miny) {
                            insert(0b01, p.x, p.y);
                        }
                        if (p.x < minx && p.y > maxy) {
                            insert(0b10, p.x, p.y);
                        }
                        if (p.x < minx && p.y < miny) {
                            insert(0b11, p.x, p.y);
                        }
                    }

                    for (EStore.Query q : qs[zi]) {
                        if (badz || !contains(y2, y1, q.y) || !contains(x2, x1, q.x)) {
                            ans[q.idx] = "CLOSED";
                            continue;
                        }
                        if (contains(minx, maxx, q.x) && contains(miny, maxy, q.y)) {
                            ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (contains(minx, maxx, q.x)) {
                            ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (contains(miny, maxy, q.y)) {
                            ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (q.x >= maxx && q.y >= maxy) {
                            ans[q.idx] = query(0b00, q.x, q.y);
                            continue;
                        }
                        if (q.x >= maxx && q.y <= miny) {
                            ans[q.idx] = query(0b01, q.x, q.y);
                            continue;
                        }
                        if (q.x <= minx && q.y >= maxy) {
                            ans[q.idx] = query(0b10, q.x, q.y);
                            continue;
                        }
                        if (q.x <= minx && q.y <= miny) {
                            ans[q.idx] = query(0b11, q.x, q.y);
                            continue;
                        }
                    }
                }
            }
            {
                pt = LUtils.genArrayList(4);
                tmp = new TreeMap[4];
                for (int i = 0; i < 4; i++) tmp[i] = new TreeMap<>();
                for (int i = 0; i < 4; i++) tmp[i].put(-100000000, 100000000);
                int x1 = x, x2 = 0, y1 = y, y2 = 0;
                for (int zi = minz; zi <= maxz; zi++) {
                    for (EStore.Point p : pts[zi]) {
                        if (contains(minx, maxx, p.x)) {
                            if (p.y > maxy) y1 = Math.min(y1, p.y - 1);
                            if (p.y < miny) y2 = Math.max(y2, p.y + 1);
                        }
                        if (contains(miny, maxy, p.y)) {
                            if (p.x > maxx) x1 = Math.min(x1, p.x - 1);
                            if (p.x < minx) x2 = Math.max(x2, p.x + 1);
                        }
                        if (p.x >= maxx && p.y >= maxy) {
                            insert(0b00, p.x, p.y);
                        }
                        if (p.x >= maxx && p.y <= miny) {
                            insert(0b01, p.x, p.y);
                        }
                        if (p.x <= minx && p.y >= maxy) {
                            insert(0b10, p.x, p.y);
                        }
                        if (p.x <= minx && p.y <= miny) {
                            insert(0b11, p.x, p.y);
                        }
                    }
                }
                boolean badz = false;
                for (int zi = minz - 1; zi >= 1; zi--) {
                    for (EStore.Point p : pts[zi]) {
                        if (contains(minx, maxx, p.x) && contains(miny, maxy, p.y)) {
                            badz = true;
                            continue;
                        }
                        if (contains(minx, maxx, p.x)) {
                            if (p.y > maxy) y1 = Math.min(y1, p.y - 1);
                            if (p.y < miny) y2 = Math.max(y2, p.y + 1);
                            continue;
                        }
                        if (contains(miny, maxy, p.y)) {
                            if (p.x > maxx) x1 = Math.min(x1, p.x - 1);
                            if (p.x < minx) x2 = Math.max(x2, p.x + 1);
                            continue;
                        }
                        if (p.x >= maxx && p.y >= maxy) {
                            insert(0b00, p.x, p.y);
                        }
                        if (p.x >= maxx && p.y <= miny) {
                            insert(0b01, p.x, p.y);
                        }
                        if (p.x <= minx && p.y >= maxy) {
                            insert(0b10, p.x, p.y);
                        }
                        if (p.x <= minx && p.y <= miny) {
                            insert(0b11, p.x, p.y);
                        }
                    }

                    for (EStore.Query q : qs[zi]) {
                        if (badz || !contains(y2, y1, q.y) || !contains(x2, x1, q.x)) {
                            ans[q.idx] = "CLOSED";
                            continue;
                        }
                        if (contains(minx, maxx, q.x) && contains(miny, maxy, q.y)) {
                            if (badz) ans[q.idx] = "CLOSED";
                            else ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (contains(minx, maxx, q.x)) {
                            ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (contains(miny, maxy, q.y)) {
                            ans[q.idx] = "UNKNOWN";
                            continue;
                        }
                        if (q.x >= maxx && q.y >= maxy) {
                            ans[q.idx] = query(0b00, q.x, q.y);
                            continue;
                        }
                        if (q.x >= maxx && q.y <= miny) {
                            ans[q.idx] = query(0b01, q.x, q.y);
                            continue;
                        }
                        if (q.x <= minx && q.y >= maxy) {
                            ans[q.idx] = query(0b10, q.x, q.y);
                            continue;
                        }
                        if (q.x <= minx && q.y <= miny) {
                            ans[q.idx] = query(0b11, q.x, q.y);
                            continue;
                        }
                    }
                }
            }

            out.println("CORRECT");
            for (int i = 0; i < k; i++) {
                out.println(ans[i]);
            }
        }

        static class Point {
            public int x;
            public int y;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

        }

        static class Query {
            public int x;
            public int y;
            public int idx;

            public Query(int x, int y, int idx) {
                this.x = x;
                this.y = y;
                this.idx = idx;
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
}