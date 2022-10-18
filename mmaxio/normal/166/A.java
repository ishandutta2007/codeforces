import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Team implements Comparable<Team>{
        int ac;
        int penalty;
        
        public Team(int ac, int penalty) {
            this.ac = ac;
            this.penalty = penalty;
        }

        @Override
        public int compareTo(Team o) {
            if (ac != o.ac)
                return ac > o.ac ? -1 : 1;
            return (penalty == o.penalty) ? 0 : (penalty < o.penalty ? -1 : 1);
        }
        
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt() - 1;
        
        Team[] a = new Team[n];
        for (int i = 0; i < n; i++)
            a[i] = new Team(nextInt(), nextInt());
        
        Arrays.sort(a);
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && a[j].compareTo(a[i]) == 0)
                j++;
            if (i <= k && k < j) {
                out.println(j - i);
                return;
            }
            i = j;
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