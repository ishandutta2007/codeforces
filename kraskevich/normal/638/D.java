import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    int[] dx = new int[]{1, 0, 0};
    int[] dy = new int[]{0, 1, 0};
    int[] dz = new int[]{0, 0, 1};

    int n;
    int m;
    int k;

    boolean[][][] was;

    boolean exists(int x, int y, int z) {
        return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k && was[x][y][z];
    }

    boolean canGo(int x1, int y1, int z1, int x2, int y2, int z2) {
        if (x1 > x2 || y1 > y2 || z1 > z2)
            return false;
        return (x2 + y2 + z2) - (x1 + y1 + z1) == 1;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        was = new boolean[n][m][k];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                String line = in.next();
                for (int t = 0; t < k; t++)
                    if (line.charAt(t) == '1')
                        was[i][j][t] = true;
            }
        int res = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                for (int z = 0; z < k; z++) {
                    if (exists(x, y, z)) {
                        boolean any = false;
                        for (int d1 = 0; d1 < 3; d1++) {
                            for (int d2 = 0; d2 < 3; d2++) {
                                int px = x - dx[d1];
                                int py = y - dy[d1];
                                int pz = z - dz[d1];
                                int nx = x + dx[d2];
                                int ny = y + dy[d2];
                                int nz = z + dz[d2];
                                if (exists(nx, ny, nz) && exists(px, py, pz)) {
                                    int ways = 0;
                                    for (int d3 = 0; d3 < 3; d3++) {
                                        int xx = px + dx[d3];
                                        int yy = py + dy[d3];
                                        int zz = pz + dz[d3];
                                        if (exists(xx, yy, zz) && canGo(xx, yy, zz, nx, ny, nz))
                                            ways++;
                                    }
                                    if (ways == 0)
                                        throw new AssertionError("");
                                    if (ways == 1)
                                        any = true;
                                }
                            }
                        }
                        if (any)
                            res++;
                    }
                }
        out.println(res);
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(0, in, out);
        in.close();
        out.close();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        tokenizer = null;
        return line;
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}