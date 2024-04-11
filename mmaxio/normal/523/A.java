import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */
public class A {
    public static void main(String[] args) {
        new A().run();
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
        int m = nextInt();
        int n = nextInt();
        char[][] c = new char[n][];
        for (int i = 0; i < n; i++) {
            c[i] = nextToken().toCharArray();
        }

        for (int i = 0; i < 2 * m; i++) {
            for (int j = 0; j < 2 * n; j++) {
                out.print(c[j / 2][i / 2]);
            }
            out.println();
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