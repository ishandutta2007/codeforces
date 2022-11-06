import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.io.InputStreamReader;

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
        private static final int MODULO = 1000000007;
        private static final String PATTERN = "ATCG";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] count = new int[4];
            int len = in.nextInt();
            for (char c : in.next().toCharArray()) {
                ++count[PATTERN.indexOf(c)];
            }
            Arrays.sort(count);
            int num = 0;
            for (int i = 0; i < 4; ++i) {
                if (count[i] == count[3]) {
                    ++num;
                }
            }

            long answer = 1;
            for (int i = 0; i < len; ++i) {
                answer = answer * num % MODULO;
            }

            out.println(answer);
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