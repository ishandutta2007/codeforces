import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */
public class D {
    public static void main(String[] args) {
        new D().run();
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

    public long ans(int v, int x, int b, int c) {
        return (long)(v - x) / 5 * b + (long)(v - x) % 5 * c;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int b = nextInt();
        int c = nextInt();

        if (5 * c < b) {
            b = 5 * c;
        }

        ArrayList<Integer>[] e = new ArrayList[5];
        for (int i = 0; i < 5; i++) {
            e[i] = new ArrayList<>();
        }

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            e[Math.floorMod(a[i], 5)].add(a[i]);
        }

        Arrays.sort(a);
        for (int i = 0; i < 5; i++) {
            Collections.sort(e[i]);
            Collections.reverse(e[i]);
        }

        long best = Long.MAX_VALUE;
        for (int mod = 0; mod < 5; mod++) {
            int[] l = new int[5];
            int[] r = new int[5];
            int modSum = 0;
            long totalSum = 0;
            int z = 0;
            up:
            for (int i = a.length - 1; i >= 0; i--) {
                int v = a[i] + (5 + mod - Math.floorMod(a[i], 5)) % 5;
                for (int m = 0; m < 5; m++) {
                    while (l[m] < e[m].size() && e[m].get(l[m]) > v) {
                        if (l[m] < r[m]) {
                            modSum -= (5 + mod - Math.floorMod(e[m].get(l[m]), 5)) % 5;
                            totalSum -= e[m].get(l[m]);
                            z--;
                        }
                        l[m]++;
                    }
                    r[m] = Math.max(r[m], l[m]);
                }
                for (int j = z; j < k; j++) {
                    int bi = -1;
                    for (int m = 0; m < 5; m++) {
                        if (bi == -1 && r[m] < e[m].size()) {
                            bi = m;
                            continue;
                        }
                        if (r[m] < e[m].size() && ans(v, e[m].get(r[m]), b, c) < ans(v, e[bi].get(r[bi]), b, c)) {
                            bi = m;
                        }
                    }
                    if (bi == -1) {
                        break up;
                    }
                    modSum += (5 + mod - Math.floorMod(e[bi].get(r[bi]), 5)) % 5;
                    totalSum += e[bi].get(r[bi]);
                    r[bi]++;
                    z++;
                }
                best = Math.min(modSum * c + (1L * v * k - totalSum - modSum) / 5 * b, best);
            }
        }

        out.println(best);
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