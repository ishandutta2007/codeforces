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
            int[] perm1 = in.readIntArray(n);
            int[] perm2 = in.readIntArray(n);
            int[] invperm1 = new int[n];
            int[] invperm2 = new int[n];
            for (int i = 0; i < n; i++) {
                invperm1[perm1[i]] = i;
                invperm2[perm2[i]] = i;
            }

            int cur = 1;
            for (int i = 0; i < n - 2; i++) {
                int pos1 = invperm1[cur];
                int pos2 = invperm2[cur];
                int next1 = (pos1 + 1) % n;
                int next2 = (pos2 + 1) % n;
                if (perm1[next1] == 0) {
                    next1 = (next1 + 1) % n;
                }
                if (perm2[next2] == 0) {
                    next2 = (next2 + 1) % n;
                }
                if (perm1[next1] != perm2[next2]) {
                    out.println("NO");
                    return;
                }
                cur = perm1[next1];
            }
            out.println("YES");
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++)
                ret[i] = nextInt();
            return ret;
        }

    }
}