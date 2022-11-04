import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Set;

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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Set<Integer> set = new HashSet<Integer>();
            ArrayList<int[]> answer = new ArrayList<int[]>();
            int last = 0;
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                if (set.contains(a)) {
                    answer.add(new int[]{last, i});
                    last = i + 1;
                    set.clear();
                } else {
                    set.add(a);
                }
            }
            if (last != n) {
                if (answer.isEmpty()) {
                    out.print(-1);
                    return;
                }
            }
            answer.get(answer.size() - 1)[1] = n - 1;
            out.println(answer.size());
            for (int i = 0; i < answer.size(); ++i) {
                out.println((answer.get(i)[0] + 1) + " " + (answer.get(i)[1] + 1));
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