import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    static final int ITER = 90;
    
    class Jumper implements Comparable<Jumper>{
        int fat;
        int speed;
        int id;
        
        public Jumper(int fat, int speed, int id) {
            this.fat = fat;
            this.speed = speed;
            this.id = id;
        }

        @Override
        public int compareTo(Jumper o) {
            if (fat != o.fat)
                return fat < o.fat ? -1 : 1;
            if (speed != o.speed)
                return speed < o.speed ? -1 : 1;
            return 0;
        }
    }
    
    Jumper[] a;
    int n, k;
    
    boolean can(double time) {
        int j = 0;
        for (int i = 1; i <= k; i++) {
            while (j < n && 1.0 * i / a[j].speed > time)
                j++;
            if (j == n)
                return false;
            j++;
        }
        return true;
    }

    void solve() throws IOException {
        n = nextInt();
        k = nextInt();
        nextInt();
        
        int[] fat = new int[n];
        int[] speed = new int[n];
        for (int i = 0; i < n; i++)
            fat[i] = nextInt();
        for (int i = 0; i < n; i++)
            speed[i] = nextInt();
        a = new Jumper[n];
        for (int i = 0; i < n; i++)
            a[i] = new Jumper(fat[i], speed[i], i + 1);
        Arrays.sort(a);
        double l = 0;
        double r = 100000;
        
        for (int iter = 0; iter < ITER; iter++) {
            double mid = (l + r) * 0.5;
            if (can(mid))
                r = mid;
            else
                l = mid;
        }
        
        int j = 0;
        for (int i = 1; i <= k; i++) {
            while (j < n && 1.0 * i / a[j].speed > r)
                j++;
            out.print(a[j].id + " ");
            j++;
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().inp();
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