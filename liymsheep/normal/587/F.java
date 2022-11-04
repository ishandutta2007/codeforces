import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.util.List;
import java.util.Collections;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        private static final int BLOCK_SIZE = 999;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            char[][] strings = new char[n][];
            int length = 0;
            for (int i = 0; i < n; ++i) {
                strings[i] = in.next().toCharArray();
                length += strings[i].length;
            }
            int[] beginPos = new int[n];
            int[] cat = new int[length + n];
            int[] belong = new int[length + n];

            length = 0;
            for (int i = 0; i < n; ++i) {
                beginPos[i] = length;
                for (char c : strings[i]) {
                    belong[length] = i;
                    cat[length++] = c;
                }
                belong[length] = -1;
                cat[length++] = 300 + i;
            }

            int[] sa = SuffixArray.makeSA(cat);
            int[] rank = SuffixArray.makeRank(sa);
            int[] height = SuffixArray.makeHeight(cat, sa, rank);
            RMQ rmq = new SparseTable(height);

            int[] leftBound = new int[n];
            int[] rightBound = new int[n];
            for (int i = 0; i < n; ++i) {
                int at = rank[beginPos[i]];
                int low = 0, high = at;
                while (low < high) {
                    int mid = (low + high) >> 1;
                    if (lcp(mid, at, rmq) >= strings[i].length) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }
                leftBound[i] = low;

                low = at;
                high = cat.length - 1;
                while (low < high) {
                    int mid = ((low + high) >> 1) + 1;
                    if (lcp(at, mid, rmq) >= strings[i].length) {
                        low = mid;
                    } else {
                        high = mid - 1;
                    }
                }
                rightBound[i] = low;
            }

            List<Query> queries = new ArrayList<Query>();
            for (int i = 0; i < q; ++i) {
                int l, r, k;
                l = in.nextInt() - 1;
                r = in.nextInt() - 1;
                k = in.nextInt() - 1;
                if (l != 0) {
                    queries.add(new Query(l - 1, k, -1, i));
                }
                queries.add(new Query(r, k, 1, i));
            }
            Collections.sort(queries);

            Query[] queries1 = queries.toArray(new Query[queries.size()]);

            long[] answers = new long[q];
            int[] count = new int[n];
            for (int i = 0; i < cat.length / BLOCK_SIZE; ++i) {
                int begin = i * BLOCK_SIZE;
                int end = begin + BLOCK_SIZE - 1;

                for (int j = begin; j <= end; ++j) {
                    if (belong[sa[j]] != -1) {
                        ++count[belong[sa[j]]];
                    }
                }

                int ptr = 0, sum = 0;
                for (int j = 0; j < n; ++j) {
                    if (leftBound[j] <= begin && rightBound[j] >= end) {
                        ++sum;
                    }
                    while (ptr < queries1.length && queries1[ptr].pos == j) {
                        answers[queries1[ptr].id] +=
                                queries1[ptr].coef * sum * (long) count[queries1[ptr].k];
                        ++ptr;
                    }
                }

                for (int j = begin; j <= end; ++j) {
                    if (belong[sa[j]] != -1) {
                        --count[belong[sa[j]]];
                    }
                }
            }

            int ptr = 0;
            for (int j = 0; j < n; ++j) {
                if (leftBound[j] % BLOCK_SIZE != 0
                        || leftBound[j] / BLOCK_SIZE == rightBound[j] / BLOCK_SIZE
                        && (rightBound[j] + 1) % BLOCK_SIZE != 0) {
                    for (int i = leftBound[j];
                         i <= rightBound[j] && (i % BLOCK_SIZE != 0 || i == leftBound[j]); ++i) {
                        if (belong[sa[i]] != -1) {
                            ++count[belong[sa[i]]];
                        }
                    }
                }

                if (leftBound[j] / BLOCK_SIZE != rightBound[j] / BLOCK_SIZE) {
                    if ((rightBound[j] + 1) % BLOCK_SIZE != 0) {
                        for (int i = rightBound[j]; (i + 1) % BLOCK_SIZE != 0; --i) {
                            if (belong[sa[i]] != -1) {
                                ++count[belong[sa[i]]];
                            }
                        }
                    }
                }

                while (ptr < queries1.length && queries1[ptr].pos == j) {
                    answers[queries1[ptr].id] +=
                            queries.get(ptr).coef * (long) count[queries1[ptr].k];
                    ++ptr;
                }
            }

            for (long answer : answers) {
                out.println(answer);
            }
        }

        int lcp(int l, int r, RMQ rmq) {
            if (l == r) {
                return Integer.MAX_VALUE;
            }
            return rmq.getMinValue(l + 1, r);
        }

        class Query implements Comparable<Query> {
            public final int pos;
            public final int k;
            public final int coef;
            public final int id;

            Query(int pos, int k, int coef, int id) {
                this.pos = pos;
                this.k = k;
                this.coef = coef;
                this.id = id;
            }


            public int compareTo(Query o) {
                return pos - o.pos;
            }

        }

        interface RMQ {
            int getMinValue(int left, int right);

        }

        class SparseTable implements RMQ {
            int[][] min;
            int[] orig;
            int[] log;
            int size;
            int maxPw;

            SparseTable(int[] seq) {
                this.orig = seq;
                this.size = seq.length;
                construct();
            }

            void construct() {
                int power = 1;
                while ((1 << power) < size) {
                    ++power;
                }
                maxPw = power + 1;
                min = new int[maxPw][size];
                log = new int[size + 1];
                log[0] = 0;
                for (int i = 1; i <= size; ++i) {
                    log[i] = 0;
                    while ((1 << (log[i] + 1)) < i) {
                        ++log[i];
                    }
                }

                for (int i = 0; i < size; ++i) {
                    min[0][i] = orig[i];
                }

                for (int i = 1; i < maxPw; ++i) {
                    for (int j = 0; j < size; ++j) {
                        min[i][j] = min[i - 1][j];
                        if (j + (1 << (i - 1)) < size) {
                            min[i][j] = Math.min(min[i][j], min[i - 1][j + (1 << (i - 1))]);
                        }
                    }
                }
            }


            public int getMinValue(int left, int right) {
                if (right < left) {
                    return Integer.MAX_VALUE;
                }
                int step = log[right - left + 1];
                return Math.min(min[step][left], min[step][right - (1 << step) + 1]);
            }

        }

        static class SuffixArray {
            static boolean cmp(int[] r, int a, int b, int l, int n) {
                int la = r[a], lb = r[b], ra, rb;
                ra = a + l < n ? r[a + l] : -1;
                rb = b + l < n ? r[b + l] : -1;
                return la == lb && ra == rb;
            }

            static int[] makeSA(int s[]) {
                int n = s.length;
                int alphaSize = 1;
                for (int i = 0; i < n; ++i) {
                    alphaSize = Math.max(alphaSize, s[i] + 1);
                }

                int[] wa = new int[Math.max(n, alphaSize) + 10];
                int[] wb = new int[Math.max(n, alphaSize) + 10];
                int[] wc = new int[Math.max(n, alphaSize) + 10];
                int[] wd = new int[Math.max(n, alphaSize) + 10];
                int[] sa = new int[n];

                int[] x = wa, y = wb;
                for (int i = 0; i < n; ++i)
                    ++wc[x[i] = s[i]];
                for (int i = 1; i < alphaSize; ++i)
                    wc[i] += wc[i - 1];
                for (int i = n - 1; i >= 0; --i)
                    sa[--wc[x[i]]] = i;
                for (int tot = 0, p = 1; tot + 1 < n; p <<= 1, alphaSize = tot + 1) {
                    tot = 0;
                    for (int i = n - p; i < n; ++i)
                        y[tot++] = i;
                    for (int i = 0; i < n; ++i) {
                        if (sa[i] >= p) {
                            y[tot++] = sa[i] - p;
                        }
                    }
                    for (int i = 0; i < n; ++i)
                        wd[i] = x[y[i]];
                    for (int i = 0; i < alphaSize; ++i)
                        wc[i] = 0;
                    for (int i = 0; i < n; ++i)
                        ++wc[wd[i]];
                    for (int i = 1; i < alphaSize; ++i)
                        wc[i] += wc[i - 1];
                    for (int i = n - 1; i >= 0; --i)
                        sa[--wc[wd[i]]] = y[i];
                    int[] t = x;
                    x = y;
                    y = t;
                    x[sa[0]] = tot = 0;
                    for (int i = 1; i < n; ++i)
                        x[sa[i]] = cmp(y, sa[i - 1], sa[i], p, n) ? tot : ++tot;
                }

                return sa;
            }

            static int[] makeRank(int sa[]) {
                int rank[] = new int[sa.length];
                for (int i = 0; i < sa.length; ++i) {
                    rank[sa[i]] = i;
                }

                return rank;
            }

            static int[] makeHeight(int s[], int sa[], int rank[]) {
                int n = s.length;
                int height[] = new int[n];
                for (int i = 0; i < n; ++i) {

                    if (0 == rank[i]) {
                        continue;
                    }

                    if (i > 0) {
                        height[rank[i]] = Math.max(0, height[rank[i - 1]] - 1);
                    }

                    for (; s[i + height[rank[i]]] == s[sa[rank[i] - 1] + height[rank[i]]]; ++height[rank[i]]) ;
                }

                return height;
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