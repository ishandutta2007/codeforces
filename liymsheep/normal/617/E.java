import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;
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
        private static final int BLOCK_SIZE = 350;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int k = in.nextInt();

            int[] a = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                a[i] = in.nextInt();
                a[i] ^= a[i - 1];
            }

            Query[] queries = new Query[m];
            for (int i = 0; i < m; ++i) {
                queries[i] = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
            }
            long[] answers = new long[m];

            Arrays.sort(queries);
            long[] countL = new long[1 << 20];
            long[] countR = new long[1 << 20];
            long answer = 0;
            for (int i = 0; i < m; ) {
                int j = i;
                while (j < m && queries[i].blockId == queries[j].blockId) {
                    ++j;
                }

                Query[] block = new Query[j - i];
                for (int t = i; t < j; ++t) {
                    block[t - i] = queries[t];
                }

                Arrays.sort(block, new Comparator<Query>() {

                    public int compare(Query o1, Query o2) {
                        return Integer.compare(o1.right, o2.right);
                    }
                });

                int maxL = Integer.MIN_VALUE;
                for (Query query : block) {
                    maxL = Math.max(maxL, query.left);
                }

                int ptr = maxL;
                for (Query query : block) {
                    while (ptr <= query.right) {
                        ++countL[a[ptr]];
                        ++countR[a[ptr + 1]];
                        answer += countL[a[ptr + 1] ^ k];

                        ++ptr;
                    }

                    for (int p = Math.min(query.right, maxL - 1); p >= query.left; --p) {
                        ++countR[a[p + 1]];
                        ++countL[a[p]];
                        answer += countR[a[p] ^ k];
                    }

                    answers[query.queryId] = answer;

                    for (int p = query.left; p < maxL && p <= query.right; ++p) {
                        answer -= countR[a[p] ^ k];
                        --countR[a[p + 1]];
                        --countL[a[p]];
                    }
                }

                while (ptr > maxL) {
                    --ptr;
                    answer -= countL[a[ptr + 1] ^ k];
                    --countL[a[ptr]];
                    --countR[a[ptr + 1]];
                }

                i = j;
            }

            for (int i = 0; i < m; ++i) {
                out.println(answers[i]);
            }
        }

        static class Query implements Comparable<Query> {
            int left;
            int right;
            int queryId;
            int blockId;

            Query(int left, int right, int queryId) {
                this.left = left;
                this.right = right;
                this.queryId = queryId;
                this.blockId = left / BLOCK_SIZE;
            }


            public int compareTo(Query o) {
                return Integer.compare(blockId, o.blockId);
            }

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