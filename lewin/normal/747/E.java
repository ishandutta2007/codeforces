import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public ArrayList<String>[] comments;
        public int maxdepth;
        public String[] s;

        public int parse(int depth, int idx) {
            if (comments[depth] == null) {
                comments[depth] = new ArrayList<>();
                maxdepth = depth;
            }
            comments[depth].add(s[idx]);
            int numcomments = Integer.parseInt(s[idx + 1]);
            int curidx = idx + 2;
            while (numcomments-- > 0) {
                curidx = parse(depth + 1, curidx);
            }
            return curidx;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            s = in.next().split(",");
            comments = new ArrayList[1000000];
            int idx = 0;
            while (idx < s.length) {
                idx = parse(1, idx);
            }

            out.println(maxdepth);
            for (int i = 1; i <= maxdepth; i++) {
                boolean first = true;
                for (String w : comments[i]) {
                    if (!first) out.print(" ");
                    out.print(w);
                    first = false;
                }
                out.println();
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

    }
}