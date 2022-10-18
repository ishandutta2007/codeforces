import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Edge {
        int to, cap;

        public Edge(int to, int cap) {
            super();
            this.to = to;
            this.cap = cap;
        }
    }
    
    final int INF = Integer.MAX_VALUE / 2;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        
        Edge[] to = new Edge[n];
        boolean[] hasIn = new boolean[n];
        
        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            int cap = nextInt();
            to[v1] = new Edge(v2, cap);
            hasIn[v2] = true;
        }
        
        ArrayList<Integer> ansTank = new ArrayList<Integer>();
        ArrayList<Integer> ansTap = new ArrayList<Integer>();
        ArrayList<Integer> ansCap = new ArrayList<Integer>();
        
        for (int i = 0; i < n; i++)
            if (to[i] != null && !hasIn[i]) {
                int cap = INF;
                int tap = i;
                for (; to[tap] != null; tap = to[tap].to)
                    cap = Math.min(cap, to[tap].cap);
                ansTank.add(i + 1);
                ansTap.add(tap + 1);
                ansCap.add(cap);
            }
        
        out.println(ansTank.size());
        for (int i = 0; i < ansTank.size(); i++)
            out.println(ansTank.get(i) + " " + ansTap.get(i) + " " + ansCap.get(i)); 
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