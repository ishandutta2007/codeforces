import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();
            AhoCorasick ah = new AhoCorasick(t.length + 1);
            ah.addString(new String(t));
            int[][] dp = new int[s.length + 1][ah.nodeCount];
            for (int[] x : dp) Arrays.fill(x, -(1 << 29));
            dp[0][0] = 0;
            for (int cletter = 0; cletter < s.length; cletter++) {
                for (int cnode = 0; cnode < ah.nodeCount; cnode++) {
                    char from = s[cletter], to = s[cletter];
                    if (s[cletter] == '?') {
                        from = 'a';
                        to = 'z';
                    }
                    for (char z = from; z <= to; z++) {
                        int nnode = ah.transition(cnode, z);
                        dp[cletter + 1][nnode] = Math.max(dp[cletter + 1][nnode], dp[cletter][cnode] + (ah.nodes[nnode].leaf ? 1 : 0));
                    }
                }
            }

            out.println(AUtils.max(dp[s.length]));
        }

    }

    static class AhoCorasick {
        static final int ALPHABET_SIZE = 26;
        public AhoCorasick.Node[] nodes;
        public int nodeCount;

        public AhoCorasick(int maxNodes) {
            nodes = new AhoCorasick.Node[maxNodes];
            // create root
            nodes[0] = new AhoCorasick.Node();
            nodes[0].suffLink = 0;
            nodes[0].parent = -1;
            nodeCount = 1;
        }

        public void addString(String s) {
            int cur = 0;
            for (char ch : s.toCharArray()) {
                int c = ch - 'a';
                if (nodes[cur].children[c] == -1) {
                    nodes[nodeCount] = new AhoCorasick.Node();
                    nodes[nodeCount].parent = cur;
                    nodes[nodeCount].charFromParent = ch;
                    nodes[cur].children[c] = nodeCount++;
                }
                cur = nodes[cur].children[c];
            }
            nodes[cur].leaf = true;
        }

        public int suffLink(int nodeIndex) {
            AhoCorasick.Node node = nodes[nodeIndex];
            if (node.suffLink == -1)
                node.suffLink = node.parent == 0 ? 0 : transition(suffLink(node.parent), node.charFromParent);
            return node.suffLink;
        }

        public int transition(int nodeIndex, char ch) {
            int c = ch - 'a';
            AhoCorasick.Node node = nodes[nodeIndex];
            if (node.transitions[c] == -1)
                node.transitions[c] = node.children[c] != -1 ? node.children[c] : (nodeIndex == 0 ? 0 : transition(suffLink(nodeIndex), ch));
            return node.transitions[c];
        }

        public static class Node {
            public int parent;
            public char charFromParent;
            public int suffLink = -1;
            public int[] children = new int[ALPHABET_SIZE];
            public int[] transitions = new int[ALPHABET_SIZE];
            public boolean leaf;

            {
                Arrays.fill(children, -1);
                Arrays.fill(transitions, -1);
            }
        }

    }

    static class AUtils {
        public static int max(int[] arr) {
            int res = arr[0];
            for (int x : arr) res = Math.max(res, x);
            return res;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}