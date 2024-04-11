import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Pair implements Comparable<Pair>{
        long key; int value;

        public Pair(long key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            if (key != o.key)
                return key < o.key ? -1 : 1;
            return 0;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int x = nextInt();
        int y = nextInt();
        
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++)
            a[i] = new Pair(nextInt() - x, i + 1);
        
        Pair[] b = new Pair[m];
        for (int i = 0; i < m; i++)
            b[i] = new Pair(nextInt(), i + 1);
        
        y += x;
        
        Arrays.sort(a);
        Arrays.sort(b);
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        int uk = 0;
        for (int i = 0; i < n; i++) {
            while (uk < m && b[uk].key < a[i].key)
                uk++;
            if (uk != m && b[uk].key <= a[i].key + y) {
                ans.add(a[i].value);
                ans.add(b[uk++].value);
            }
        }
        
        out.println(ans.size() / 2);
        for (int i = 0; i < ans.size(); i += 2) {
            out.println(ans.get(i) + " " + ans.get(i + 1));
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