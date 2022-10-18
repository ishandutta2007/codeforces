import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int ROOT = 46300;
    
    ArrayList<Integer> primes;
    
    int ind;
    
    int go(int x, int div, int sign, int lastInd) {
        //System.err.println(x + " " + div + " " + sign + " " + lastInd);
        if (x < div)
            return 0;
        int res = sign * (x / div);
        for (int i = lastInd + 1; i < ind; i++) {
            if (primes.get(i) > x / div)
                break;
            res += go(x, div * primes.get(i), -sign, i);
        }
        return res;
    }
    
    int go(int x) {
        return go(x, 1, 1, -1);
    }

    void solve() throws IOException {
        int l = nextInt();
        int r = nextInt();
        int k = nextInt();
        
        boolean[] isPrime = new boolean[ROOT];
        Arrays.fill(isPrime, true);
        
        primes = new ArrayList<Integer>();
        
        for (int i = 2; i < ROOT; i++) {
            if (isPrime[i]) {
                primes.add(i);
                for (int j = i * i; j < ROOT; j += i)
                    isPrime[j] = false;
            }
        }
        
        for (int p : primes) if (k != p && k % p == 0) {
            out.print(0);
            return;
        }
        
        if (k > ROOT) {
            if (l <= k && k <= r) 
                out.print(1);
            else
                out.print(0);
            return;
        }
        
        ind = Collections.binarySearch(primes, k);
        
        if (l % k == 0)
            l /= k;
        else
            l = l / k + 1;
        
        r /= k;
        
        //System.err.println(go(7));
        
        out.print(go(r) - go(l - 1));
        
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
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