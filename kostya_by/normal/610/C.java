import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kanstantsin Sokal
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            int[][] answer = new int[1 << k][1 << k];

            answer[0][0] = 0;
            for (int p = 0; p < k; p++) {
                int n = 1 << p;
                for (int i = 0; i < n + n; i++) {
                    for (int j = 0; j < n + n; j++) {
                        if (i >= n && j >= n) {
                            answer[i][j] = answer[i - n][j - n] ^ 1;
                        } else if (i >= n) {
                            answer[i][j] = answer[i - n][j];
                        } else if (j >= n) {
                            answer[i][j] = answer[i][j - n];
                        }
                    }
                }
            }

            for (int i = 0; i < (1 << k); i++) {
                StringBuilder builder = new StringBuilder();
                for (int j = 0; j < (1 << k); j++) {
                    builder.append(answer[i][j] == 0 ? '+' : '*');
                }
                out.println(builder);
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

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