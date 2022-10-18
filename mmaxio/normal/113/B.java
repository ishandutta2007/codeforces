import java.io.*;
import java.util.*;

public class B_TL {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    String s;

    final long X = 239;

    long[] hash;
    long[] pow;

    long getHash(int l, int r) {
        return hash[r] - hash[l] * pow[r - l];
    }

    void solve() throws IOException {
        s = nextToken();
        String st = nextToken();
        String en = nextToken();

        hash = new long[s.length() + 1];
        pow = new long[s.length() + 1];

        pow[0] = 1;

        for (int i = 1; i < hash.length; i++) {
            hash[i] = hash[i - 1] * X + s.charAt(i - 1);
            pow[i] = pow[i - 1] * X;
        }

        long start = System.currentTimeMillis();

        ArrayList<Integer> matchSt = new ArrayList<Integer>();
        ArrayList<Integer> matchEn = new ArrayList<Integer>();

        for (int i = 0; i <= s.length() - st.length(); i++)
            if (s.substring(i, i + st.length()).equals(st))
                matchSt.add(i);

        for (int i = 0; i <= s.length() - en.length(); i++)
            if (s.substring(i, i + en.length()).equals(en))
                matchEn.add(i);

        HashSet<Long>[] ans = new HashSet[s.length()];

        for (int i = 0; i < s.length(); i++)
            ans[i] = new HashSet<Long>();

        for (int i : matchSt) {
            for (int j : matchEn)
                if (i <= j && i + st.length() <= j + en.length())
                    ans[j - i + en.length() - 1].add(getHash(i, j + en.length()));
        }

        int res = 0;
        for (HashSet<Long> p : ans) {
            /*Collections.sort(p);
            if (!p.isEmpty())
                res++;
            for (int i = 1; i < p.size(); i++)
                if (p.get(i).longValue() != p.get(i - 1).longValue())
                    res++;*/
            res += p.size();
        }
        
        if ((st.length() > s.length() || en.length() > s.length()) && res != 0)
            throw new AssertionError();

        out.print(res);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B_TL().inp();
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