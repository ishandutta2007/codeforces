import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void mergeOut(ArrayList<Integer> a, ArrayList<Integer> b) {
        int uk1 = 0;
        int uk2 = 0;
        while (uk1 < a.size() && uk2 < b.size()) {
            if (a.get(uk1) < b.get(uk2)) {
                out.print(a.get(uk1) + " ");
                uk1++;
            } else {
                out.print(b.get(uk2) + " ");
                uk2++;
            }
        }
        for (int i = uk1; i < a.size(); i++)
            out.print(a.get(i) + " ");

        for (int i = uk2; i < b.size(); i++)
            out.print(b.get(i) + " ");

        return;

    }

    void solve() throws IOException {
        int n = nextInt();
        int[] place = new int[3 * n + 1];
        for (int i = 0; i < 3 * n; i++)
            place[nextInt()] = i;
        boolean[] used = new boolean[3 * n + 1];

        int[][] teams = new int[n][3];
        int[] leader = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++)
                teams[i][j] = nextInt();
            leader[i] = teams[i][0];
            for (int j = 1; j < 3; j++)
                if (place[teams[i][j]] < place[leader[i]])
                    leader[i] = teams[i][j];
        }

        int who = nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++)
                if (teams[i][j] == who) {
                    if (leader[i] != who) {
                        for (int p = 1; p <= 3 * n; p++)
                            if (p != who)
                                out.print(p + " ");
                        return;
                    }

                    ArrayList<Integer> picked = new ArrayList<Integer>();
                    ArrayList<Integer> notPicked = new ArrayList<Integer>();
                    for (int k = 1; k <= 3 * n; k++)
                        if (used[k])
                            picked.add(k);
                    
                    for (int k = 0; k < 3; k++)
                        if (teams[i][k] != who) {
                            notPicked.add(teams[i][k]);
                            used[teams[i][k]] = true;
                        }
                    used[who] = true;
                    if (notPicked.get(0) > notPicked.get(1)) {
                        int tmp = notPicked.get(0);
                        notPicked.set(0, notPicked.get(1));
                        notPicked.set(1, tmp);
                    }

                    for (int k = 1; k <= 3 * n; k++)
                        if (!used[k])
                            notPicked.add(k);

                    mergeOut(picked, notPicked);
                    return;

                }
            for (int j = 0; j < 3; j++)
                used[teams[i][j]] = true;
        }

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