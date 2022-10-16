import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public ArrayList<Integer>[] graph;
        public int[] color;
        public int ans = -1;
        public boolean[] same;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            color = in.readIntArray(n);
            ans = -1;
            same = new boolean[n];
            dfs1(0, -1);
            dfs2(0, -1);
            if (ans == -1) {
                out.println("NO");
            } else {
                out.println("YES");
                out.println(ans + 1);
            }
        }

        public void dfs1(int node, int par) {
            same[node] = true;
            int lastc = color[node];
            for (int next : graph[node]) {
                if (next == par) continue;
                dfs1(next, node);
                same[node] &= same[next];
                if (lastc != -1 && lastc != color[next]) same[node] = false;
                lastc = color[next];
            }
        }

        public void dfs2(int node, int par) {
            if (ans != -1) return;
            boolean ok = true;
            int count = 0;
            for (int next : graph[node]) {
                if (next == par) continue;
                if (!same[next]) {
                    ok = false;
                    count++;
                }
            }
            if (ok) {
                ans = node;
                return;
            }

            if (par != -1 && color[node] != color[par]) {
                return;
            }
            if (count > 1) {
                return;
            }
            for (int next : graph[node]) {
                if (next == par) continue;
                if (same[next]) {
                    if (color[next] != color[node]) {
                        return;
                    }
                }
            }
            for (int next : graph[node]) {
                if (next == par) continue;
                if (!same[next]) {
                    dfs2(next, node);
                }
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

        public void println(int i) {
            writer.println(i);
        }

    }
}