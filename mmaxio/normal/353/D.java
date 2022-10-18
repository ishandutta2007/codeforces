import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        String s = nextToken();
        int prev = Integer.MIN_VALUE;
        int ind = 0;
        while (ind < s.length() && s.charAt(ind) == 'F') {
            ind++;
        }
        
        s = s.substring(ind);

        for (int i = 0, j = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'F') {
                prev = Math.max(prev + 1, i - j);
                j++;
            }
        }

        if (prev == Integer.MIN_VALUE)
            prev = 0;

        out.println(prev);
    }

    D() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D();
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