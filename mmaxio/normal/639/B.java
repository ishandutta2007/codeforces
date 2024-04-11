import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
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

    public void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        int h = nextInt();
        if (2 * h < d) {
            out.println(-1);
            return;
        }

        if (d == 1) {
            if (n > 2) {
                out.println(-1);
                return;
            }
            out.println("1 2");
            return;
        }

        int[] diam = new int[d + 1];
        int v = 1;
        for (int i = 0; i <= d; i++) {
            if (i != h) {
                diam[i] = v++;
            }
        }

        out.println((diam[0] + 1) + " " + (diam[1] + 1));
        for (int i = 1; i < d; i++) {
            out.println((diam[i] + 1) + " " + (diam[i + 1] + 1));
        }
        for (int i = d + 1; i < n; i++) {
            out.println((i + 1) + " " + (diam[1] + 1));
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}