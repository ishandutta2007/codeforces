import java.util.*;
import java.io.*;

public class Main {

        static FastScanner scanner;
        static PrintWriter writer;

        public static void main(String[] args) throws IOException {
                scanner = new FastScanner(System.in);
                writer = new PrintWriter(System.out);

                int n = scanner.nextInt();
                int m = scanner.nextInt();
                int[][] a = new int[n][m];
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                                 a[i][j] = scanner.nextInt();
                int answer = new D(a, n, m).solve();
                writer.println(answer);

                writer.close();
        }
}


class D {

        int[][] a;
        boolean[][] was;
        int n, m;

        D(int[][] a, int n, int m) {
                this.a = a;
                this.n = n;
                this.m = m;
                was = new boolean[m][m];
        }

        boolean check(int value) {
                for (int i = 0; i < m; i++)
                        for (int j = 0; j < m; j++)
                                        was[i][j] = false;
                for (int row = 0; row < n; row++) {
                        ArrayList<Integer> greater = new ArrayList<Integer>();
                        for (int i = 0; i < m; i++)
                                if (a[row][i] >= value)
                                        greater.add(i);
                        for (int i : greater)
                                for (int j : greater)
                                        if (i != j) {
                                                if (was[i][j])
                                                        return true;
                                                was[i][j] = true;
                                        }
                }
                return false;
        }

        public int solve() {
                int low = 0;
                int high = 1000 * 1000 * 1000;
                while (low < high) {
                        int mid = (low + high + 1) / 2;
                        if (check(mid))
                                low = mid;
                        else
                                high = mid - 1;
                }
                return low;
        }
}

class FastScanner {

        BufferedReader bf;
        StringTokenizer st;

        FastScanner(InputStream input) {
                bf = new BufferedReader(new InputStreamReader(input));
        }

        String nextToken() throws IOException {
                if (st == null || !st.hasMoreTokens()) {
                        String line = bf.readLine();
                        if (line == null)
                                return null;
                        st = new StringTokenizer(line);
                }
                return st.nextToken();
        }

        int nextInt() throws IOException {
                return Integer.parseInt(nextToken());
        }
}