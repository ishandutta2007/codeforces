import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */

public class C {
    public static void main(String[] args) {
        new C().run();
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
        if (n == 1) {
            out.println(6);
            return;
        }

        //System.err.println(n);

        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = nextToken();
        }

        int md = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = 0;
                for (int k = 0; k < 6; k++) {
                    x += s[i].charAt(k) == s[j].charAt(k) ? 1 : 0;
                }
                md = Math.max(md, x);
            }
        }
        out.println((5 - md) / 2);
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            //for (int i = 0; i < t; i++)
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}