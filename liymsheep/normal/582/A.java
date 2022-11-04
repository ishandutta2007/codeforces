import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;
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
        private void put(int x, TreeMap<Integer, Integer> map) {
            if (map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }

        private void remove(int x, TreeMap<Integer, Integer> map) {
            if (map.get(x).equals(1)) {
                map.remove(x);
            } else {
                map.put(x, map.get(x) - 1);
            }
        }

        private int gcd(int a, int b) {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
            int n = in.nextInt();
            for (int i = 0; i < n * n; ++i) {
                int a = in.nextInt();
                put(a, map);
            }

            int[] answer = new int[n];
            for (int i = 0; i < n; ++i) {
                int val = map.lastKey();
                answer[i] = val;
                remove(val, map);
                for (int j = 0; j < i; ++j) {
                    remove(gcd(answer[i], answer[j]), map);
                    remove(gcd(answer[i], answer[j]), map);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(answer[i]);
            }
            out.println();
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