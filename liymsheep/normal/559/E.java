import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.Arrays;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Set<Integer> locations = new HashSet<Integer>();

            int[][] spotlights = new int[n][];
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                int l = in.nextInt();
                locations.add(a);
                locations.add(a - l);
                locations.add(a + l);
                spotlights[i] = new int[]{a, l};
            }

            Arrays.sort(spotlights, new Comparator<int[]>() {

                public int compare(int[] o1, int[] o2) {
                    return Integer.compare(o1[0], o2[0]);
                }
            });

            locations.add(-1000000000);
            Integer[] loc = locations.toArray(new Integer[locations.size()]);
            Arrays.sort(loc);

            ArrayList<Integer>[] to = new ArrayList[loc.length];
            for (int i = 0; i < loc.length; ++i) {
                to[i] = new ArrayList<Integer>();
            }

            for (int i = 0; i < n; ++i) {
                int from = Arrays.binarySearch(loc, spotlights[i][0] - spotlights[i][1]);
                to[from].add(i);
            }

            int[][] maxValue = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    maxValue[i][j] = spotlights[j][0] + spotlights[j][1];
                    if (j > i) {
                        maxValue[i][j] = Math.max(maxValue[i][j], maxValue[i][j - 1]);
                    }
                }
            }

            int[][] dp = new int[n + 1][loc.length];
            for (int i = 0; i < n; ++i) {
                for (int last = loc.length - 1; last > 0; --last) {
                    dp[i][last - 1] = Math.max(dp[i][last - 1], dp[i][last] - (loc[last] - loc[last - 1]));
                }

                for (int last = 0; last < loc.length; ++last) {

                    {
                        int contrib = 0;
                        if (spotlights[i][0] + spotlights[i][1] > loc[last]) {
                            contrib = Math.min(spotlights[i][1], spotlights[i][0] + spotlights[i][1] - loc[last]);
                        }
                        int next = Arrays.binarySearch(loc, spotlights[i][0] + spotlights[i][1]);
                        next = Math.max(last, next);
                        dp[i + 1][next] = Math.max(dp[i + 1][next], dp[i][last] + contrib);
                    }

                    if (last + 1 < loc.length) {
                        dp[i][last + 1] = Math.max(dp[i][last + 1], dp[i][last]);
                    }

                    for (Integer j : to[last]) {
                        int contrib = Math.min(spotlights[j][1], spotlights[j][0] - loc[last]);
                        int next = Math.max(j > i ? maxValue[i][j - 1] : 0, spotlights[j][0]);
                        contrib += next - spotlights[j][0];
                        next = Arrays.binarySearch(loc, next);
                        dp[j + 1][next] = Math.max(dp[j + 1][next], dp[i][last] + contrib);
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j < loc.length; ++j) {
                    ans = Math.max(dp[i][j], ans);
                }
            }

            out.println(ans);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}