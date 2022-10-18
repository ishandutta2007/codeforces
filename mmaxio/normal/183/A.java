import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int ul = 0;
        int ur = 0;
        int dl = 0;
        int dr = 0;
        int any = 0;
        for (int i = 0; i < n; i++) {
            String s = nextToken();
            if (s.equals("UL"))
                ul++;
            else if (s.equals("UR"))
                ur++;
            else if (s.equals("DL"))
                dl++;
            else if (s.equals("DR"))
                dr++;
            else
                any++;
        }
        
        int dim1 = 1 + ur + dl + any;
        int dim2 = 1 + ul + dr + any;
        out.println((long)dim1 * dim2);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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