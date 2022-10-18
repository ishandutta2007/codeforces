import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.HashSet;

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

        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = nextToken();
        }

        HashSet<String> hs = new HashSet<>();
        for (int i = n - 1; i >= 0; i--) {
            if (!hs.contains(s[i])){
                out.println(s[i]);
            }
            hs.add(s[i]);
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