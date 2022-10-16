import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt(), n = in.nextInt();
            int[] seq = new int[m];
            for (int i = 0; i < n; i++) {
                seq[i] = in.nextInt();
            }
            int cursum = m * (m - 1);
            for (int i = 0; i < n; i++) {
                cursum -= seq[i];
                if (cursum < (m - i - 1) * (m - i - 2)) {
                    out.println("no");
                    return;
                }
            }
            for (int i = n; i < m; i++) {
                int prev = (i == 0 ? 2 * m - 2 : seq[i - 1]);
                int cantake = cursum - (m - i - 1) * (m - i - 2);
                if (cantake < 0) {
                    out.println("no");
                    return;
                }
                seq[i] = Math.min(prev, cantake);
                cursum -= seq[i];
            }
            if (cursum != 0) {
                out.println("no");
                return;
            }

            ArrayList<TaskE.Number> numbers = new ArrayList<>();
            for (int i = 0; i < m; i++) numbers.add(new TaskE.Number(seq[i], i));
            char[][] mat = new char[m][m];
            for (int i = 0; i < m; i++) mat[i][i] = 'X';
            for (int i = 0; i < m; i++) {
                Collections.sort(numbers);
                TaskE.Number largest = numbers.get(0);
                int rem = m - 1 - i;
                int reduce = 2 * rem - largest.value;
                ArrayList<TaskE.Number> next = new ArrayList<>();
                int idx = 1;
                for (int j = 0; j < reduce; j++) {
                    TaskE.Number cur = numbers.get(idx++);
                    next.add(new TaskE.Number(cur.value - 1, cur.pos));
                    mat[cur.pos][largest.pos] = 'D';
                    mat[largest.pos][cur.pos] = 'D';
                }
                while (idx < numbers.size()) {
                    TaskE.Number c = numbers.get(idx++);
                    next.add(new TaskE.Number(c.value, c.pos));
                    mat[c.pos][largest.pos] = 'L';
                    mat[largest.pos][c.pos] = 'W';
                }
                numbers = next;
            }
            out.println("yes");
            for (int i = 0; i < m; i++) {
                out.println(new String(mat[i]));
            }

        }

        static class Number implements Comparable<TaskE.Number> {
            public int value;
            public int pos;

            public Number(int value, int pos) {
                this.value = value;
                this.pos = pos;
            }

            public int compareTo(TaskE.Number other) {
                return other.value - value;
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}