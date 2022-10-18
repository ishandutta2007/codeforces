import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int[] solve(int n) {
        if (n == 1) {
            return new int[] { 1 };
        }
        if (n == 2) {
            return new int[] { 1, 2 };
        }
        if (n == 4) {
            return new int[] { 1, 3, 2, 4 };
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return null;
            }
        }

        int p = -1;
        outer: for (int x = 2; x < n; x++) {
            int cur = 1;
            for (int i = 1; i < n - 1; i++) {
                cur = (int) ((long) cur * x % n);
                if (cur == 1) {
                    continue outer;
                }
            }
            p = x;
            break;
        }

        int[] pows = new int[n - 1];
        pows[0] = 1;
        for (int i = 1; i < pows.length; i++) {
            pows[i] = (int) ((long) pows[i - 1] * p % n);
        }

        int[] ans = new int[n];
        ans[0] = 1;
        ans[n - 1] = n;
        for (int i = 0; i < n / 2 - 1; i++) {
            ans[2 * i + 1] = pows[n - 2 - 2 * i];
            ans[2 * i + 2] = pows[2 * i + 2];
        }
        ans[n - 2] = pows[1];
        return ans;

        // List<Integer> ans = new ArrayList<>();
        // for (int i = 2; i < n; i++) {
        // ans.add(i);
        // }
        // HashSet<Integer> set = new HashSet<>();
        // outer: while (true) {
        // Collections.shuffle(ans);
        // int cur = 1;
        // set.clear();
        // set.add(1);
        // // System.err.println(ans);
        // for (int i = 0; i < ans.size(); i++) {
        // cur = (int) ((long) cur * ans.get(i) % n);
        // if (set.contains(cur)) {
        // continue outer;
        // }
        // set.add(cur);
        // }
        // out.println(ans);
        // break;
        // }
        // return null;
    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int n = nextInt();
        int[] ret = solve(n);
        if (ret == null) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.println(ret[i]);
            }
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}