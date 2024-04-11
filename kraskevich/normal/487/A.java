import java.io.*;
import java.util.*;


public class Task {
    final int INF = (int)1e9;

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        int hpY = in.nextInt();
        int atkY = in.nextInt();
        int defY = in.nextInt();
        int hpM = in.nextInt();
        int atkM = in.nextInt();
        int defM = in.nextInt();
        int h = in.nextInt();
        int a = in.nextInt();
        int d = in.nextInt();
        int res = INF;
        for (int da = 0; da <= 300; da++)
            for (int dd = 0; dd <= 300; dd++) {
                if (da + atkY <= defM)
                    continue;
                int low = -1;
                int high = 1_000_000;
                while (high - low > 1) {
                    int mid = (low + high) / 2;
                    if (canBeat(hpY + mid, atkY + da, defY + dd, hpM, atkM, defM))
                        high = mid;
                    else
                        low = mid;
                }
                res = Math.min(res, h * high + a * da + d * dd);
            }
        out.println(res);
    }

    private boolean canBeat(long hp1, long a1, long d1, long hp2, long a2, long d2) {
        if (a2 <= d1)
            return true;
        long cnt1 = (hp1 + a2 - d1 - 1) / (a2 - d1);
        long cnt2 = (hp2 + a1 - d2 - 1) / (a1 - d2);
        return cnt1 > cnt2;
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