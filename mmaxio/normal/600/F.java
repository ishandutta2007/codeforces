import java.io.*;
import java.util.*;

public class BipartiteEdgeColoring {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n1 = nextInt();
        int n2 = nextInt();
        int m = nextInt();
        int[] deg = new int[n1 + n2];
        int[] v1 = new int[m];
        int[] v2 = new int[m];
        for (int i = 0; i < m; i++) {
            v1[i] = nextInt() - 1;
            v2[i] = nextInt() - 1 + n1;
            deg[v1[i]]++;
            deg[v2[i]]++;
        }

        int colors = 0;
        for (int i = 0; i < n1 + n2; i++) {
            colors = Math.max(colors, deg[i]);
        }
        
        int[][] to = new int[n1 + n2][colors];
        for (int i = 0; i < n1 + n2; i++) {
            Arrays.fill(to[i], -1);
        }

        int[] path = new int[n1 + n2];
        int size = 0;

        outer: for (int i = 0; i < m; i++) {
            int p = v1[i];
            int q = v2[i];
            
            int freeP = -1;

            for (int j = 0; j < colors; j++) {
                if (to[p][j] == -1) {
                    freeP = j;
                    break;
                }
            }

            if (to[q][freeP] == -1) {
                to[p][freeP] = q;
                to[q][freeP] = p;
                continue outer;
            }
            
            int freeQ = -1;
            for (int j = 0; j < colors; j++) {
                if (to[q][j] == -1) {
                    freeQ = j;
                    break;
                }
            }

            path[0] = p;
            path[1] = q;
            size = 2;
            int move = freeP;
            int last = q;
            while (to[last][move] != -1) {
                last = to[last][move];
                move ^= freeP ^ freeQ;
                path[size++] = last;
            }

            to[last][move ^ freeP ^ freeQ] = -1;
            for (int j = size - 2; j >= 0; j--) {
                p = path[j];
                q = path[j + 1];
                to[p][move] = q;
                to[q][move] = p;
                move ^= freeP ^ freeQ;
            }
            
//          if (p == 1 && q == 1 + n2) {
//              System.err.println(Arrays.deepToString(to));
//          }

        }

        int[][] adj = new int[n1][n2];
        for (int i = 0; i < n1; i++) {
            Arrays.fill(adj[i], -1);
            for (int j = 0; j < colors; j++) {
                if (to[i][j] != -1) {
                    adj[i][to[i][j] - n1] = j;
                }
            }
        }

        out.println(colors);
        for (int i = 0; i < m; i++) {
            out.print(adj[v1[i]][v2[i] - n1] + 1 + " ");
        }
        out.println();

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new BipartiteEdgeColoring().inp();
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