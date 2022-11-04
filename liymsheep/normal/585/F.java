import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.io.InputStreamReader;

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
        private static final int MODULO = 1000000007;
        private SuffixAutomaton automaton;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            automaton = new SuffixAutomaton(10);
            automaton.append(in.next().toCharArray());
            char[] low = in.next().toCharArray();
            char[] high = in.next().toCharArray();

            int answer = (go(high, true) - go(low, false)) % MODULO;
            answer = (answer + MODULO) % MODULO;

            out.println(answer);
        }

        private int go(char[] number, boolean inclusive) {

            int[][] nextPos = new int[automaton.size()][10];
            for (int i = 0; i < automaton.size(); ++i) {
                for (int j = 0; j < 10; ++j) {
                    SuffixAutomaton.SuffixAutomatonNode node = automaton.list.get(i);
                    while (node != null && node.ch[j] == null) {
                        node = node.suffixNode;
                    }

                    nextPos[i][j] = node == null ? -1 : node.id;
                }
            }
            int d = number.length / 2;
            int[][][] dp = new int[automaton.size()][d + 1][2];
            int[][][] ndp = new int[automaton.size()][d + 1][2];

            dp[automaton.root.id][0][1] = 1;
            for (int i = 0; i < number.length; ++i) {
                fill(ndp, 0);
                for (int nodeId = 0; nodeId < automaton.size(); ++nodeId) {
                    for (int suffixMatchedLength = 0; suffixMatchedLength <= d; ++suffixMatchedLength) {
                        for (int equalsUpperBound = 0; equalsUpperBound < 2; ++equalsUpperBound) {
                            int currentWays = dp[nodeId][suffixMatchedLength][equalsUpperBound];
                            if (currentWays == 0) {
                                continue;
                            }
                            for (int digit = 0; digit < 10; ++digit) {
                                if (equalsUpperBound == 1 && digit > number[i] - '0') break;
                                int nnid = nextPos[nodeId][digit];
                                int nsml = suffixMatchedLength;
                                if (nnid == -1) {
                                    nsml = 0;
                                    nnid = automaton.root.id;
                                } else {
                                    nsml = Math.min(nsml, automaton.list.get(nnid).maximumLength) + 1;
                                    nnid = automaton.list.get(nnid).ch[digit].id;
                                }

                                if (suffixMatchedLength == d || nsml > d) {
                                    nsml = d;
                                }
                                int neqb = equalsUpperBound == 0 ? 0 : (digit == number[i] - '0' ? 1 : 0);
                                ndp[nnid][nsml][neqb] += currentWays;
                                if (ndp[nnid][nsml][neqb] >= MODULO) {
                                    ndp[nnid][nsml][neqb] -= MODULO;
                                }
                            }
                        }
                    }
                }
                int[][][] temp = dp;
                dp = ndp;
                ndp = temp;
            }
            int answer = 0;
            for (int i = 0; i < automaton.size(); ++i) {
                answer = (answer + dp[i][d][0]) % MODULO;
                if (inclusive) {
                    answer = (answer + dp[i][d][1]) % MODULO;
                }
            }

            return answer;
        }

        private void fill(int[][][] array, int value) {
            for (int[][] sa : array) {
                for (int[] ssa : sa) {
                    Arrays.fill(ssa, value);
                }
            }
        }

        private static class SuffixAutomaton {
            public final int ALPHA;
            SuffixAutomatonNode root;
            SuffixAutomatonNode lastNode;
            ArrayList<SuffixAutomatonNode> list;

            SuffixAutomaton(int ALPHA) {
                this.ALPHA = ALPHA;
                list = new ArrayList<SuffixAutomatonNode>();
                root = new SuffixAutomatonNode();
                lastNode = root;
            }

            public void append(char[] s) {
                for (int i = 0; i < s.length; ++i) {
                    this.extend(s[i] - '0');
                }
            }

            public int size() {
                return list.size();
            }

            SuffixAutomatonNode extend(int c, SuffixAutomatonNode rear) {
                SuffixAutomatonNode p = rear;
                SuffixAutomatonNode np = new SuffixAutomatonNode();
                np.maximumLength = p.maximumLength + 1;
                np.positions = 1;
                while (null != p && null == p.ch[c]) {
                    p.ch[c] = np;
                    p = p.suffixNode;
                }

                if (p == null) {
                    np.suffixNode = root;
                } else {
                    SuffixAutomatonNode q = p.ch[c];
                    if (q.maximumLength == p.maximumLength + 1) {
                        np.suffixNode = q;
                    } else {
                        SuffixAutomatonNode nq = new SuffixAutomatonNode();
                        nq.ch = q.ch.clone();
                        nq.maximumLength = p.maximumLength + 1;
                        nq.suffixNode = q.suffixNode;
                        q.suffixNode = nq;
                        np.suffixNode = nq;

                        while (null != p && p.ch[c] == q) {
                            p.ch[c] = nq;
                            p = p.suffixNode;
                        }
                    }
                }

                lastNode = np;
                return np;
            }

            SuffixAutomatonNode extend(int c) {
                return extend(c, lastNode);
            }

            class SuffixAutomatonNode {
                SuffixAutomatonNode suffixNode;
                SuffixAutomatonNode[] ch;
                int tag;
                int deg;
                int maximumLength;
                int positions;
                int id;

                SuffixAutomatonNode() {
                    suffixNode = null;
                    ch = new SuffixAutomatonNode[ALPHA];
                    maximumLength = 0;
                    positions = 0;
                    tag = 0;
                    deg = 0;
                    id = list.size();

                    list.add(this);
                }

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

    }
}