import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    String check(int len, int ac, char first, char last) {
        if (len == 1) {
            if (first != last)
                return null;
            else
                return "" + first;
        }
        if (len == 2) {
            int haveAc = (first == 'A' && last == 'C') ? 1 : 0;
            if (haveAc == ac) {
                return "" + first + last;
            } else {
                return null;
            }
        }
        
        char[] buff = new char[len];
        int st;
        buff[0] = first;
        if (first == 'A')
            st = 0;
        else {
            st = 1;
        }
        if (st + 2 * ac > len) {
            return null;
        }
        if (st + 2 * ac - 1 == len - 1 && last != 'C')
            return null;
        for (int i = 0; i < ac; i++) {
            buff[st + 2 * i] = 'A';
            buff[st + 2 * i + 1] = 'C';
        }
        for (int i = st + 2 * ac; i < len - 1; i++) {
            buff[i] = 'B';
        }
        buff[len - 1] = last;
        return new String(buff);
        
    }

    boolean check(int len0, int ac0, char first0, char last0, int len1, int ac1,
            char first1, char last1) {
        String ans0 = check(len0, ac0, first0, last0);
        String ans1 = check(len1, ac1, first1, last1);
        if (ans0 != null && ans1 != null) {
            out.println(ans0);
            out.println(ans1);
            return true;
        }
        return false;
    }

    void solve() throws IOException {
        int k = nextInt();
        int x = nextInt();
        int len0 = nextInt();
        int len1 = nextInt();

        int[] ac = new int[k];
        char[] first = new char[k];
        char[] last = new char[k];

        for (int ac0 = 0; ac0 <= len0 / 2; ac0++)
            for (int ac1 = 0; ac1 <= len1 / 2; ac1++) {
                for (char first0 = 'A'; first0 <= 'C'; first0++)
                    for (char last0 = 'A'; last0 <= 'C'; last0++)
                        for (char first1 = 'A'; first1 <= 'C'; first1++)
                            for (char last1 = 'A'; last1 <= 'C'; last1++) {
                                ac[0] = ac0;
                                ac[1] = ac1;
                                first[0] = first0;
                                first[1] = first1;
                                last[0] = last0;
                                last[1] = last1;

                                for (int i = 2; i < k; i++) {
                                    ac[i] = Math.min(ac[i - 1] + ac[i - 2],
                                            x + 1);
                                    if (last[i - 2] == 'A'
                                            && first[i - 1] == 'C') {
                                        ac[i] = Math.min(ac[i] + 1, x + 1);
                                    }
                                    first[i] = first[i - 2];
                                    last[i] = last[i - 1];
                                }

                                if (ac[k - 1] == x) {
                                    if (check(len0, ac0, first0, last0, len1,
                                            ac1, first1, last1)) {
                                        return;
                                    }
                                }
                            }
            }
        out.println("Happy new year!");
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