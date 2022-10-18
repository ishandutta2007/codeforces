import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    
    
    int getType(String s) {
        if (s.endsWith("lios"))
            return 0;
        if (s.endsWith("liala"))
            return 1;
        if (s.endsWith("etr"))
            return 2;
        if (s.endsWith("etra"))
            return 3;
        if (s.endsWith("initis"))
            return 4;
        if (s.endsWith("inites"))
            return 5;
        return -1;
    }

    void solve() throws IOException {
        String[] text = nextString().split(" ");
        
        int[] type = new int[text.length];
        
        int gender = 0;
        
        for (int i = 0; i < text.length; i++) {
            type[i] = getType(text[i]);
            if (type[i] == -1) {
                out.println("NO");
                return;
            }
            if (type[i] % 2 == 0)
                gender |= 1;
            else
                gender |= 2;
        }
        
        if (gender == 0)
            throw new AssertionError();
        
        if (text.length == 1) {
            out.println("YES");
            return;
        }
        
        if (gender == 3) {
            out.println("NO");
            return;
        }
        
        int uk = 0;
        while (uk < text.length && type[uk] / 2 == 0)
            uk++;
        if (!(uk < text.length && type[uk] / 2 == 1)) {
            out.println("NO");
            return;
        } else
            uk++;
        while (uk < text.length && type[uk] / 2 == 2)
            uk++;
        
        out.print(uk == text.length ? "YES" : "NO");
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