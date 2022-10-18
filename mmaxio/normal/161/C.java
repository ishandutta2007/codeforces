import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int ans;
    
    void check(int l1, int r1, int l2, int r2, int len) {
        if (l1 == 0)
            l1++;
        if (l2 == 0)
            l2++;
        
        int mid = 1 << (len - 1);
        if (l1 > mid || r1 < mid || l2 > mid || r2 < mid)
            return;
        
        ans = Math.max(ans, Math.min(r1, r2) - Math.max(l1, l2) + 1);
    }

    void solve() throws IOException {
        int l1 = nextInt();
        int r1 = nextInt();
        int l2 = nextInt();
        int r2 = nextInt();

        ans = 0;

        for (int bit = 1; bit <= 30; bit++) {
            // bit - 1 presents
            // bit doesn't

            int smallMask = (1 << bit) - 1;
            ArrayList<Integer> segm1 = new ArrayList<Integer>();
            int left = l1 >> bit;
            int right = r1 >> bit;
            if (right - left > 1) {
                segm1.add(0);
                segm1.add(smallMask);
            } else if (right == left) {
                segm1.add(l1 & smallMask);
                segm1.add(r1 & smallMask);
            } else {
                segm1.add(l1 & smallMask);
                segm1.add(smallMask);
                segm1.add(0);
                segm1.add(r1 & smallMask);
            }

            ArrayList<Integer> segm2 = new ArrayList<Integer>();
            left = l2 >> bit;
            right = r2 >> bit;
            if (right - left > 1) {
                segm2.add(0);
                segm2.add(smallMask);
            } else if (right == left) {
                segm2.add(l2 & smallMask);
                segm2.add(r2 & smallMask);
            } else {
                segm2.add(l2 & smallMask);
                segm2.add(smallMask);
                segm2.add(0);
                segm2.add(r2 & smallMask);
            }

            for (int i = 0; i < segm1.size(); i += 2)
                for (int j = 0; j < segm2.size(); j += 2) {
                    check(segm1.get(i), segm1.get(i + 1), segm2.get(j),
                            segm2.get(j + 1), bit);
                }
        }
        out.println(ans);
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