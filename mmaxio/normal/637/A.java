import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashMap;

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
        int n = nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        int max = 0;
        int mt = 0;
        int mans = 0;
        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = i; j < n; j++) {
                total += (a[i] == a[j] ? 1 : 0);
                if (total > max || (total == max && mt > j)) {
                    max = total;
                    mt = j;
                    mans = a[i];
                }
            }
        }

        out.println(mans);
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