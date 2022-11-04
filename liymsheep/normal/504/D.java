import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.math.BigInteger;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final int MAX_BIT_LENGTH = 2100;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt();
            BitSet[] numbers = new BitSet[m];
            for (int i = 0; i < m; ++i) {
                numbers[i] = new BitSet(MAX_BIT_LENGTH);
            }
            for (int i = 0; i < m; ++i) {
                BigInteger number = new BigInteger(in.next());
                for (int j = 0; j < MAX_BIT_LENGTH; ++j) {
                    if (number.testBit(j)) {
                        numbers[i].set(j);
                    }
                }
            }

            ArrayList<BitSet> axis = new ArrayList<BitSet>();
            ArrayList<Integer> highestBit = new ArrayList<Integer>();
            ArrayList<BitSet> which = new ArrayList<BitSet>();
            for (int i = 0; i < m; ++i) {
                BitSet current = (BitSet) numbers[i].clone();
                BitSet represent = new BitSet(m);
                for (int k = 0; k < axis.size(); ++k) {
                    if (current.get(highestBit.get(k))) {
                        current.xor(axis.get(k));
                        represent.xor(which.get(k));
                    }
                }

                if (current.isEmpty()) {
                    out.print(represent.cardinality());
                    for (int j = 0; j < i; ++j) {
                        if (represent.get(j)) {
                            out.print(" " + j);
                        }
                    }
                    out.println();
                } else {
                    out.println(0);

                    axis.add(current);
                    highestBit.add(current.length() - 1);
                    represent.set(i);
                    which.add(represent);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}