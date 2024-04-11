import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by vaksenov on 16.01.2016.
 */
public class B {
    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void writePath(int[] path, int a, int b) {
        if (path[0] == a) {
            for (int i = 0; i < path.length; i++) {
                out.print((path[i] + 1) + " ");
            }
        } else {
            for (int i = 0; i < path.length; i++) {
                out.print(path[path.length - i - 1] + " ");
            }
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int a = nextInt() - 1;
        int b = nextInt() - 1;
        int c = nextInt() - 1;
        int d = nextInt() - 1;

        int[] x = new int[]{a, b};
        int[] y = new int[]{c, d};
        Arrays.sort(x);
        Arrays.sort(y);

        if (n == 4) {
            out.println(-1);
            return;
        }
        if (k <= n) {
            out.println(-1);
            return;
        }
        int[] path = new int[n];
        Arrays.fill(path, -1);
        path[0] = a;
        path[1] = c;
        path[3] = d;
        path[n - 1] = b;
        int v = 0;
        for (int i = 0; i < n; i++) {
            while (v == a || v == b || v == c || v == d) v++;
            if (path[i] == -1)
                path[i] = v++;
        }
        int[] path2 = new int[n];
        path2[0] = c;
        path2[1] = a;
        path2[2] = path[2];
        for (int i = 3; i < n - 1; i++) {
            path2[i] = path[n - 1 - i + 3];
        }

        path2[n - 1] = d;

        writePath(path, a, b);
        out.println();
        writePath(path2, c, d);
    }


    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}