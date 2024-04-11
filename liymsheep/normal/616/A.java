import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String a = in.next();
            String b = in.next();
            if (a.length() > b.length()) {
                StringBuilder fb = new StringBuilder();
                for (int i = 0; i < a.length() - b.length(); ++i) {
                    fb.append('0');
                }
                fb.append(b);
                b = fb.toString();
            } else {
                StringBuilder fa = new StringBuilder();
                for (int i = 0; i < b.length() - a.length(); ++i) {
                    fa.append('0');
                }
                fa.append(a);
                a = fa.toString();

            }
            for (int i = 0; i < a.length(); ++i) {
                if (a.charAt(i) != b.charAt(i)) {
                    out.println(a.charAt(i) < b.charAt(i) ? '<' : '>');
                    return;
                }
            }

            out.println('=');
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