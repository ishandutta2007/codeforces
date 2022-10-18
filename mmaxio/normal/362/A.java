import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        char[][] s = new char[8][];
        for (int i = 0; i < 8; i++) {
            s[i] = nextToken().toCharArray();
        }
        
        int x1 = -1;
        int y1 = -1;
        int x2 = -1;
        int y2 = -1;
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (s[i][j] == 'K') {
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        
        boolean res = Math.abs(x1 - x2) % 4 == 0 && Math.abs(y1 - y2) % 4 == 0;
        out.println(res ? "YES" : "NO");
    }

    A() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A();
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