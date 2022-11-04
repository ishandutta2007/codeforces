import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.Queue;

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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] degrees = new int[n];
            int[] xorSum = new int[n];
            Queue<Integer> queue = new LinkedList<Integer>();
            int edges = 0;
            for (int i = 0; i < n; ++i) {
                degrees[i] = in.nextInt();
                xorSum[i] = in.nextInt();
                edges += degrees[i];
                if (degrees[i] == 1) {
                    queue.add(i);
                }
            }

            out.println(edges / 2);
            while (!queue.isEmpty()) {
                int now = queue.poll();
                if (degrees[now] == 0) {
                    continue;
                }
                --degrees[xorSum[now]];
                xorSum[xorSum[now]] ^= now;
                out.println(now + " " + xorSum[now]);
                if (degrees[xorSum[now]] == 1) {
                    queue.add(xorSum[now]);
                }
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

    }
}