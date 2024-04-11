import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        if (n == 1) {
            out.print("a\na\nb\nb\n");
            return;
        } else if (n == 2) {
            out.print("aa\nbb\naa\nbb\n");
            return;
        }
        
        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("aa");
                else
                    out.print("bb");
            out.println();
            
            out.print("c");
            for (int i = 0; i < n / 2 - 1; i++)
                if (i % 2 == 0)
                    out.print("dd");
                else
                    out.print("ee");
            out.println("c");
            
            out.print("c");
            for (int i = 0; i < n / 2 - 1; i++)
                if (i % 2 == 0)
                    out.print("ff");
                else
                    out.print("gg");
            out.println("c");
            
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("aa");
                else
                    out.print("bb");
            out.println();
        } else {
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("aa");
                else
                    out.print("bb");
            out.println("c");
            
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("dd");
                else
                    out.print("ee");
            out.println("c");
            
            out.print("x");
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("zz");
                else
                    out.print("yy");
            out.println();
            
            out.print("x");
            for (int i = 0; i < n / 2; i++)
                if (i % 2 == 0)
                    out.print("yy");
                else
                    out.print("zz");
            out.println();
        }
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