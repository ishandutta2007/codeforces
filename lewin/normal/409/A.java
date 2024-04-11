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
            char[] s1 = in.next().toCharArray();
            char[] s2 = in.next().toCharArray();
            int count = 0;
            for (int i = 0; i < s1.length; i += 2) {
                if (s1[i] == '[' && s2[i] == '(') count++;
                if (s1[i] == '(' && s2[i] == '[') count--;
                if (s1[i] == '[' && s2[i] == '8') count--;
                if (s1[i] == '8' && s2[i] == '[') count++;
                if (s1[i] == '(' && s2[i] == '8') count++;
                if (s1[i] == '8' && s2[i] == '(') count--;
            }
            if (count == 0) out.println("TIE");
            else out.printf("TEAM %d WINS\n", count > 0 ? 1 : 2);
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