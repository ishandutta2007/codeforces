import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Event implements Comparable<Event>{
        double x;
        boolean open;
        
        public Event(double x, boolean open) {
            this.x = x;
            this.open = open;
        }

        @Override
        public int compareTo(Event o) {
            return Double.compare(x, o.x);
        }
        
    }

    void solve() throws IOException {
        int n = nextInt();
        int l = nextInt();
        int v1 = nextInt();
        int v2 = nextInt();
        
        double len = 1.0 * v2 / (v1 + v2);
        ArrayList<Event> all = new ArrayList<Event>();
        for (int i = 0; i < n; i++) {
            double en = 1.0 * nextInt() / l;
            double st = en - len;
            if (st < 0) {
                all.add(new Event(st + 2, true));
                all.add(new Event(2, false));
                all.add(new Event(0, true));
                all.add(new Event(en, false));
            } else {
                all.add(new Event(st, true));
                all.add(new Event(en, false));
            }
        }
        
        double[] ans = new double[n + 1];
        Collections.sort(all);
        int cnt = 0;
        double prev = 0;
        for (int i = 0; i < all.size(); i++) {
            ans[cnt] += all.get(i).x - prev;
            prev = all.get(i).x;
            if (all.get(i).open)
                cnt++;
            else
                cnt--;
        }
        
        ans[cnt] += (2 - prev);
        
        for (double x : ans)
            out.printf("%.12f\n", x * 0.5);
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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