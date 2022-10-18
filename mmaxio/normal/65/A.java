import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int[] val = new int[6];
        for (int i = 0; i < 6; i++)
            val[i] = nextInt();
        
        if (val[3] == 0) {
            out.print("Hermione");
            return;
        }
        
        if (val[2] == 0) {
            out.print("Ron");
            return;
        }
        
        if (val[1] == 0) {
            out.print("Hermione");
            return;
        }
        
        if (val[0] == 0) {
            out.print("Ron");
            return;
        }
        
        if (val[5] == 0) {
            out.print("Hermione");
            return;
        }
        
        if (val[4] == 0) {
            out.print("Ron");
            return;
        }

        int p1 = val[0] * val[2] * val[4];
        int p2 = val[1] * val[3] * val[5];

        out.print(p2 > p1 ? "Ron" : "Hermione");

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
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
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