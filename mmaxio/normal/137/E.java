import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final String VOWEL = "aeiouAEIOU";

    boolean isVowel(char c) {
        return VOWEL.indexOf(c) >= 0;
    }

    class Prefix implements Comparable<Prefix> {
        int len, sum;

        public Prefix(int len, int sum) {
            this.len = len;
            this.sum = sum;
        }

        @Override
        public int compareTo(Prefix o) {
            if (sum == o.sum)
                return len - o.len;
            return sum - o.sum;
        }

    }

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        int[] a = new int[s.length];

        for (int i = 0; i < a.length; i++) {
            a[i] = isVowel(s[i]) ? -1 : 2;
        }

        Prefix[] p = new Prefix[a.length + 1];
        p[0] = new Prefix(0, 0);
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            sum += a[i];
            p[i + 1] = new Prefix(i + 1, sum);
        }

        int minLen = Integer.MAX_VALUE;

        int ansLen = 0;
        int ansCnt = 0;

        Arrays.sort(p);
        for (int i = 0; i < p.length; i++) {
            if (minLen < p[i].len) {
                int curLen = p[i].len - minLen;
                if (ansLen < curLen)
                    ansCnt = 0;
                ansLen = Math.max(ansLen, curLen);
                if (ansLen == curLen)
                    ansCnt++;
            } else
                minLen = p[i].len;
        }

        if (ansLen == 0)
            out.print("No solution");
        else
            out.print(ansLen + " " + ansCnt);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new E().inp();
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