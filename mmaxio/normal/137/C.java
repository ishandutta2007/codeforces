import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Segment {
        int l;
        int r;
        int id;
        public Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }
        
        
    }
    
    Comparator<Segment> byLeft = new Comparator<Segment>() {
        @Override
        public int compare(Segment o1, Segment o2) {
            if (o1.l < o2.l)
                return -1;
            if (o1.l > o2.l)
                return 1;
            return 0;
        }
    }; 
    
    Comparator<Segment> byRight = new Comparator<Segment>() {
        @Override
        public int compare(Segment o1, Segment o2) {
            if (o1.r < o2.r)
                return 1;
            if (o1.r > o2.r)
                return -1;
            return 0;
        }
    };

    void solve() throws IOException {
        int n = nextInt();
        Segment[] s = new Segment[n];
        
        for (int i = 0; i < n; i++)
            s[i] = new Segment(nextInt(), nextInt());
        
        Arrays.sort(s, byLeft);
        for (int i = 0; i < n; i++)
            s[i].id = i;
        
        Arrays.sort(s, byRight);
        int min = Integer.MAX_VALUE;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (min < s[i].id)
                ans++;
            min = Math.min(min, s[i].id);
        }
        
        out.print(ans);
        
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