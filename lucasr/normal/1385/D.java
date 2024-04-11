import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DAGoodString solver = new DAGoodString();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DAGoodString {
        static char[] vals;
        static int[][][] table;

        public void solve(int testNumber, MyScanner sc, PrintWriter out) {
            int n = sc.nextInt();
            int base = Integer.numberOfTrailingZeros(n);
            vals = sc.next().toCharArray();
            table = new int[base][base][n];
            for (int i = 0; i < table.length; i++) {
                for (int j = 0; j < table[i].length; j++) {
                    Arrays.fill(table[i][j], -1);
                }
            }
            out.println(calc(0, base - 1, 'a'));
        }

        static int calc(int from, int pot, char min) {
            if (pot < 0) {
                return vals[from] == min ? 0 : 1;
            }
            int ret = table[pot][min - 'a'][from];
            if (ret != -1) return ret;

            int from2 = from + (1 << pot);
            int changes = 0;
            for (int i = 0; i < 1 << pot; i++) {
                if (vals[from + i] != min) changes++;
            }
            ret = changes + calc(from2, pot - 1, (char) (min + 1));

            changes = 0;
            for (int i = 0; i < 1 << pot; i++) {
                if (vals[from2 + i] != min) changes++;
            }
            ret = Math.min(ret, changes + calc(from, pot - 1, (char) (min + 1)));

            return table[pot][min - 'a'][from] = ret;
        }

    }

    static class MyScanner {
        private BufferedReader br;
        private StringTokenizer tokenizer;

        public MyScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(br.readLine());
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