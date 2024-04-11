import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public ArrayList<Integer>[] graph;
        public boolean bad;
        public int ans;
        public int special;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }

            special = (int) (Math.random() * n);
            bad = false;
            dfs2(special, -1);
            if (bad) {
                bad = false;
                dfs2(special, -1);
            }
            if (bad) {
                out.println(-1);
                return;
            }
            while (ans % 2 == 0) ans /= 2;
            out.println(ans);
        }

        public int dfs2(int node, int par) {
            int s = 0;
            HashSet<Integer> seen = new HashSet<>();
            for (int next : graph[node]) {
                if (next == par) continue;
                seen.add(s = (dfs2(next, node) + 1));
                if (bad) return 0;
            }
            if (par != -1) {
                if (seen.size() > 1) {
                    bad = true;
                    special = node;
                    return 0;
                }
                return s;
            } else {
                if (seen.size() > 2) {
                    bad = true;
                    special = node;
                    return 0;
                }
                ans = 0;
                for (int k : seen) ans += k;
                return ans;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}