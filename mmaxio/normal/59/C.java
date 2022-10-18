import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int k = nextInt();
        char[] s = nextToken().toCharArray();
        int n = s.length;
        TreeSet<Character> notUsed = new TreeSet<Character>();
        for (int i = 0; i < k; i++)
            notUsed.add((char) ('a' + i));
        ArrayList<Integer> freeSlots = new ArrayList<Integer>();
        
        for (int l = 0, r = n - 1; l <= r; l++, r--) {
            if (s[l] == '?' && s[r] != '?') {
                s[l] = s[r];
            } else if (s[l] != '?' && s[r] == '?') {
                s[r] = s[l];
            } else if (s[l] != '?' && s[r] != '?') {
                if (s[l] != s[r]) {
                    out.print("IMPOSSIBLE");
                    return;
                }
            } else
                freeSlots.add(l);
            notUsed.remove(s[l]);
        }
        
        if (freeSlots.size() < notUsed.size()) {
            out.print("IMPOSSIBLE");
            return;
        }
        
        for (int i = 0; i < freeSlots.size() - notUsed.size(); i++) {
            int c = freeSlots.get(i);
            s[c] = s[n - 1 - c] = 'a';
        }
        
        int i = freeSlots.size() - notUsed.size();
        
        for (Character c : notUsed) {
            int cc = freeSlots.get(i++);
            s[cc] = s[n - 1 - cc] = c;
        }
        
        out.print(new String(s));
        
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().inp();
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