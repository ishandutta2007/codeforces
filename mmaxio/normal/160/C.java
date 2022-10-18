import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    Random rnd = new Random();
    
    void sort(int[] a, int l, int r) {
        int i = l;
        int j = r;
        int x = a[l + rnd.nextInt(r - l + 1)];
        do {
            while (a[i] < x)
                i++;
            while (x < a[j])
                j--;
            if (i <= j) {
                int y = a[i];
                a[i] = a[j];
                a[j] = y;
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j)
            sort(a, l, j);
        if (i < r)
            sort(a, i, r);
    }

    void solve() throws IOException {
        int n = nextInt();
        long k = nextLong() - 1;

        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();

        sort(a, 0, n - 1);
        int first = (int) (k / n);
        int i;
        for (i = 0; a[i] < a[first]; i++)
            k -= n;

        int j;
        for (j = i; j < n && a[i] == a[j]; j++)
            ;
        
        int eq = j - i;
        k /= eq;
        out.println(a[first] + " " + a[(int) k]);
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