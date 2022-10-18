import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    HashMap<Integer, Integer> sub;
    HashMap<Integer, Integer> vert;

    int h;
    int tot;

    int myGet(HashMap<Integer, Integer> map, int key) {
        Integer tmp = map.get(key);
        return tmp == null ? 0 : tmp;
    }

    void add(int v, int delta) {
        vert.put(v, myGet(vert, v) + delta);
        while (v != 0) {
            sub.put(v, myGet(sub, v) + delta);
            v >>= 1;
        }
    }

    double go() {
        
        //System.err.println(sub);
        //System.err.println(vert);
        
        int v = 1;
        int leaves = tot;
        int maxOut = -1;
        
        double res = 0;
        
        do {
            int p1 = myGet(vert, v) + myGet(sub, 2 * v);
            int p2 = myGet(vert, v) + myGet(sub, 2 * v + 1);
            //System.err.println(v + " " + p1 + " " + p2);
            if (maxOut >= p1 && maxOut >= p2) {
                res += maxOut * (double)leaves / tot;
                break;
            }
            if (p1 == p2) {
                res += p1 * (double)leaves / tot;
                break;
            } else if (p1 > p2) {
                res += p1 * (double)(leaves >> 1) / tot;
                v = 2 * v;
                leaves >>= 1;
                maxOut = Math.max(maxOut, p2);
            } else {
                res += p2 * (double)(leaves >> 1) / tot;
                v = 2 * v + 1;
                leaves >>= 1;
                maxOut = Math.max(maxOut, p1);
            }
        } while (leaves != 0);
            
        return res; 
        
    }

    void solve() throws IOException {
        h = nextInt();
        tot = 1 << h;
        int q = nextInt();

        sub = new HashMap<Integer, Integer>();
        vert = new HashMap<Integer, Integer>();
        for (int i = 0; i < q; i++) {
            if (nextToken().equals("add"))
                add(nextInt(), nextInt());
            else
                out.printf("%.9f\n", go());
        }
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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