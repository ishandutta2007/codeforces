import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private int[] match(char[] s, char[] t) {
            int[] next = new int[t.length];
            next[0] = -1;
            for (int i = 1; i < t.length; ++i) {
                int p = next[i - 1];
                while (p >= 0 && t[p + 1] != t[i]) {
                    p = next[p];
                }
                next[i] = p;
                if (t[next[i] + 1] == t[i]) {
                    ++next[i];
                }
            }

            int pos = -1;
            int bestLen = 0, bestPos = 0, bestStage = 0;
            for (int i = 0; i < s.length; ++i) {
                while (pos >= 0 && s[i] != t[pos + 1]) {
                    pos = next[pos];
                }

                if (s[i] == t[pos + 1]) {
                    ++pos;
                }

                if (pos + 1 == t.length) {
                    return new int[]{i - t.length + 1, i};
                }

                if (pos + 1 >= bestLen) {
                    bestLen = pos + 1;
                    bestPos = i;
                    bestStage = 0;
                }
            }

            s = s.clone();
            for (int i = 0; i < s.length - 1 - i; ++i) {
                char c = s[i];
                s[i] = s[s.length - 1 - i];
                s[s.length - 1 - i] = c;
            }

            pos = -1;
            for (int i = 0; i < s.length; ++i) {
                while (pos >= 0 && s[i] != t[pos + 1]) {
                    pos = next[pos];
                }

                if (s[i] == t[pos + 1]) {
                    ++pos;
                }

                if (pos + 1 == t.length) {
                    return new int[]{s.length - 1 - (i - t.length + 1), s.length - 1 - i};
                }

                if (pos + 1 >= bestLen) {
                    bestLen = pos + 1;
                    bestPos = i;
                    bestStage = 1;
                }
            }

            if (bestLen == 0) {
                return null;
            }

            int start = bestPos - bestLen + 1, end = bestPos;

            if (bestStage == 1) {
                start = s.length - 1 - start;
                end = s.length - 1 - end;
            }

            return new int[]{start, end};

        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();
            ArrayList<int[]> steps = new ArrayList<int[]>();
            while (t.length > 0) {
                int[] pos = match(s, t);
                if (pos == null) {
                    out.println("-1");
                    return;
                }

                steps.add(pos);
                t = new String(t).substring(Math.abs(pos[1] - pos[0]) + 1).toCharArray();
            }

            out.println(steps.size());
            for (int[] pos : steps) {
                out.println((pos[0] + 1) + " " + (pos[1] + 1));
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

    }
}