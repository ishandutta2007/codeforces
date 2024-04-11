import java.io.*;
import java.util.*;


public class Task {
    public void solve(FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        char[][] s = new char[n][];
        char[][] res = new char[n][];
        for (int i = 0; i < n; i++)
            s[i] = in.next().toCharArray();
        for (int i = 0; i < n; i++) {
            res[i] = new char[s[i].length];
            for (int j = 0; j < s[i].length; j++)
                if (s[i][j] == '?') {
                    char minDigit = 0;
                    for (char c = '0'; c <= '9'; c++) {
                        s[i][j] = c;
                        if (isValid(s[i]) && (i == 0 || isLess(res[i - 1], s[i]))) {
                            minDigit = c;
                            break;
                        }
                    }
                    if (minDigit == 0) {
                        out.println("NO");
                        return;
                    }
                    res[i][j] = minDigit;
                } else {
                    res[i][j] = s[i][j];
                }
        }
        for (int i = 1; i < n; i++)
            if (!isLess(res[i - 1], res[i])) {
                out.println("NO");
                return;
            }
        out.println("YES");
        for (int i = 0; i < n; i++)
            out.println(res[i]);
    }

    private boolean isValid(char[] s) {
        return s[0] != '0';
    }

    private boolean isLess(char[] left, char[] right) {
        if (left.length != right.length)
            return left.length < right.length;
        for (int i = 0; i < Math.max(left.length, right.length); i++) {
            if (i >= left.length)
                return true;
            if (i >= right.length)
                return false;
            char c1 = left[i];
            char c2 = right[i] == '?' ? '9' : right[i];
            if (c1 < c2)
                return true;
            if (c1 > c2)
                return false;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        for (int i = 0; i < t; i++)
            new Task().solve(in, out);
        out.flush();
    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = reader.readLine();
                if (line == null)
                    throw new IOException();
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public void close() {
            try {
                reader.close();
            } catch (IOException e) {
                // ignore
            }
        }
    }
}