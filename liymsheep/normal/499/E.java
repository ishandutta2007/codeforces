import java.util.List;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author 
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    private static final int INFINITY = 1000000000;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n, m;
        n = in.nextInt();
        m = in.nextInt();
        int[] a = new int[n];
        int[] bi = new int[m];
        int[] bj = new int[m];
        int[][][] cont = new int[n][][];
        int lastNode = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            int[][] units = decomp(a[i]);
            cont[i] = new int[units.length][3];
            for (int j = 0; j < units.length; ++j) {
                cont[i][j][0] = units[j][0];
                cont[i][j][1] = units[j][1];
                cont[i][j][2] = lastNode++;
            }
        }
        for (int i = 0; i < m; ++i) {
            bi[i] = in.nextInt() - 1;
            bj[i] = in.nextInt() - 1;
        }
        MaxFlow net = new MaxFlow(lastNode + 2, lastNode, lastNode + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < cont[i].length; ++j) {
                if (i % 2 == 0) {
                    net.insert(lastNode, cont[i][j][2], cont[i][j][1]);
                } else {
                    net.insert(cont[i][j][2], lastNode + 1, cont[i][j][1]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            int u = bi[i], v = bj[i];
            if (u % 2 == 1) {
                int t = u;
                u = v;
                v = t;
            }
            for (int j = 0; j < cont[u].length; ++j) {
                for (int k = 0; k < cont[v].length; ++k) {
                    if (cont[u][j][0] == cont[v][k][0]) {
                        net.insert(cont[u][j][2], cont[v][k][2], INFINITY);
                    }
                }
            }
        }

        out.println(net.maxFlow());
    }

    private int[][] decomp(int x) {
        List<int[]> result = new ArrayList<int[]>();
        for (int i = 2; i * i <= x; ++i) {
            if (x % i != 0) continue;
            int pow = 0;
            while (x % i == 0) {
                x /= i;
                ++pow;
            }
            result.add(new int[] {i, pow});
        }
        if (x != 1) {
            result.add(new int[] {x, 1});
        }
        return result.toArray(new int[result.size()][]);
    }
}

class MaxFlow
{
    public class Edge
    {
        public int u,v,c;
        public Edge next,r;

        public Edge(int u,int v,int c)
        {
            this.u = u;
            this.v = v;
            this.c = c;
            next = r = null;
        }
    }

    public Edge vertex[];
    public int height[], nheight[];
    public int s, t, n;

    public void init(int n,int s,int t)
    {
        height = new int[n+1];
        nheight = new int[n+1];
        vertex = new Edge[n+1];
        this.s = s;
        this.t = t;
        this.n = n;
    }

    public MaxFlow(int n,int s,int t)
    {
        init(n,s,t);
    }

    public void insert(int u,int v,int c)
    {
        Edge e = new Edge(u,v,c);
        Edge r = new Edge(v,u,0);
        e.r = r;
        r.r = e;
        e.next = vertex[u];
        vertex[u] = e;
        r.next = vertex[v];
        vertex[v] = r;
    }

    public int augPath(int u,int push)
    {
        if (u == t) return push;
        int flow = push, minheight = n-1;
        for (Edge e = vertex[u]; e != null; e = e.next)
            if (e.c != 0)
            {
                if (height[e.v] + 1 == height[e.u])
                {
                    int delta = flow < e.c ? flow : e.c;
                    if (delta > 0)
                        delta = augPath(e.v,delta);
                    e.c -= delta;
                    e.r.c += delta;
                    flow -= delta;
                    if (0 == flow || height[s] >= n) return push - flow;
                }
                minheight = Math.min(minheight, height[e.v]);
            }
        if (push == flow)
        {
            --nheight[height[u]];
            if (0 == nheight[height[u]]) height[s] = n;
            height[u] = ++minheight;
            ++nheight[height[u]];
        }
        return push - flow;
    }

    public int maxFlow()
    {
        Arrays.fill(height, 0);
        Arrays.fill(nheight, 0);
        nheight[0] = n;
        int flow = 0;
        while (height[s] < n)
            flow += augPath(s,Integer.MAX_VALUE);
        return flow;
    }
}