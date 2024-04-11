import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    void makeUnique(ArrayList<Integer> ls) {
        Collections.sort(ls);
        
        int uk = 0;
        
        for (int i = 0; i < ls.size(); i++)
            if (ls.get(i).compareTo(ls.get(uk)) != 0)
                ls.set(++uk, ls.get(i));
        
        for (int i = ls.size() - 1; i > uk; i--)
            ls.remove(i);
    }
    
    class Cell implements Comparable<Cell>{
        int order;
        int x;
        int y;
        
        public Cell(int x, int y, int x0, int y0) {
            this.x = x;
            this.y = y;
            
            x -= x0;
            y -= y0;
            if (x == 0 && y == 0) {
                this.order = 1;
                return;
            }
            
            int layer = Math.max(Math.abs(x), Math.abs(y));
            this.order = (2 * layer - 1) * (2 * layer - 1);
            if (x == -layer && y != -layer)
                this.order += (y + layer);
            else if (y == layer)
                this.order += (2 * layer) + layer + x;
            else if (x == layer)
                this.order += (4 * layer) + layer - y;
            else
                this.order += (6 * layer) + layer - x;

        }

        @Override
        public int compareTo(Cell o) {
            return order - o.order;
        }
        
    }
    
    int get(int x, int[] p) {
        return x == p[x] ? x : (p[x] = get(p[x], p));
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        
        ArrayList<Integer> all = new ArrayList<Integer>();
        
        all.add(0);
        
        int[][] f = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                f[i][j] = nextInt();
                all.add(f[i][j]);
            }
        
        int[][] symb = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                symb[i][j] = nextInt();
                if (symb[i][j] != -1)
                    all.add(symb[i][j]);
            }
        
        makeUnique(all);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                f[i][j] = Collections.binarySearch(all, f[i][j]);
                if (symb[i][j] != -1)
                    symb[i][j] = Collections.binarySearch(all, symb[i][j]);
            }

        int z = all.size();
        
        ArrayList<Integer>[] list = new ArrayList[all.size()];
        for (int i = 0; i < list.length; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                list[f[i][j]].add(i * m + j);
        
        int[] p = new int[z];
        int[] sz = new int[z];
        int[] root = new int[z];
        int[] col = new int[z];
        boolean[] wasCleared = new boolean[z];
        
        for (int i = 0; i < z; i++) {
            p[i] = i;
            sz[i] = list[i].size();
        }
        root = p.clone();
        col = p.clone();
        
        ArrayDeque<Integer> q = new ArrayDeque<Integer>();
        
        int x0 = nextInt() - 1;
        int y0 = nextInt() - 1;
        q.add(x0); q.add(y0); q.add(symb[x0][y0]);
        symb[x0][y0] = -1;
        
        long ans = 0;
        
        while (!q.isEmpty()) {
            
            int x = q.poll();
            int y = q.poll();
            int parent = q.poll();
            
            int child = col[get(f[x][y], p)];
            
            
            if (child == 0 || child == parent)
                continue;
            
            ans += sz[child];
            if (!wasCleared[child]) {
                wasCleared[child] = true;
                ArrayList<Cell> tmp = new ArrayList<D.Cell>();
                for (int c : list[child]) {
                    int nx = c / m;
                    int ny = c % m;
                    if (symb[nx][ny] != -1)
                        tmp.add(new Cell(nx, ny, x, y));
                }
                Collections.sort(tmp);
                for (Cell c : tmp) {
                    q.add(c.x);
                    q.add(c.y);
                    q.add(symb[c.x][c.y]);
                    symb[c.x][c.y] = -1;
                }
            }
            
            sz[parent] += sz[child];
            sz[child] = 0;
            
            if (root[parent] != -1) {
                p[root[child]] = root[parent];
                root[child] = -1;
            } else {
                root[parent] = root[child];
                col[root[child]] = parent;
                root[child] = -1;
            }
            
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