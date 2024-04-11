import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Igor Kraskevich
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();
            Map<Character, Integer> cnt = new HashMap<>();
            for (int i = 0; i < s.length(); i++)
                cnt.put(s.charAt(i), cnt.getOrDefault(s.charAt(i), 0) + 1);
            char[] t = "Blbsr".toCharArray();
            char[] t2 = "ua".toCharArray();
            int res = s.length();
            for (char c : t)
                res = Math.min(res, cnt.getOrDefault(c, 0));
            for (char c : t2)
                res = Math.min(res, cnt.getOrDefault(c, 0) / 2);
            out.println(res);
        }

    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = null;
                try {
                    line = reader.readLine();
                } catch (IOException e) {
                    // ignore
                }
                if (line == null)
                    return null;
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

    }
}