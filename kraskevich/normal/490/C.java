import java.io.*;
import java.lang.reflect.Array;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;


public class Task {

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        char[] number = in.next().toCharArray();
        int a = in.nextInt();
        int b = in.nextInt();
        int n = number.length;
        long[] modA = new long[n];
        long[] modB = new long[n];
        for (int i = 0; i < n; i++) {
            modA[i] = (number[i] - '0') % a;
            if (i != 0)
                modA[i] = (modA[i] + modA[i - 1] * 10) % a;
        }
        long pow10 = 1;
        for (int i = n - 1; i >= 0; i--) {
            modB[i] = pow10 * (number[i] - '0') % b;
            if (i != n - 1)
                modB[i] = (modB[i] + modB[i + 1]) % b;
            pow10 = pow10 * 10 % b;
        }
        for (int i = 0; i < n - 1; i++)
            if (modA[i] == 0 && modB[i + 1] == 0 && number[i + 1] != '0') {
                out.println("YES");
                for (int j = 0; j <= i; j++)
                    out.print(number[j]);
                out.println();
                for (int j = i + 1; j < n; j++)
                    out.print(number[j]);
                out.println();
                return;
            }
        out.println("NO");
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