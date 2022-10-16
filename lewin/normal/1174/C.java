import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader2 in = new InputReader2(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CEhabAndASpecialColoringProblem solver = new CEhabAndASpecialColoringProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class CEhabAndASpecialColoringProblem {
        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = new int[n + 1];
            int[] primes = PrimesAndDivisors.generatePrimes(n + 10);
            boolean[] isPrime = new boolean[n + 11];
            for (int i = 0; i < primes.length; i++) {
                isPrime[primes[i]] = true;
            }
            int t = 1;
            for (int i = 2; i <= n; i++) {
                if (isPrime[i]) {
                    arr[i] = t++;
                } else {
                    for (int j = 2; j * j <= i; j++) {
                        if (i % j == 0) {
                            arr[i] = arr[j];
                            break;
                        }
                    }
                }
            }
            for (int i = 2; i <= n; i++) {
                out.println(arr[i]);
            }
        }

    }

    static class InputReader2 {
        private BufferedReader in;
        private StringTokenizer st;

        public InputReader2(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

    }

    static class PrimesAndDivisors {
        public static int[] generatePrimes(int n) {
            boolean[] sieve = new boolean[n + 1];
            Arrays.fill(sieve, 2, n + 1, true);
            for (int i = 2; i * i <= n; i++)
                if (sieve[i])
                    for (int j = i * i; j <= n; j += i)
                        sieve[j] = false;
            int[] primes = new int[n + 1];
            int cnt = 0;
            for (int i = 0; i < sieve.length; i++)
                if (sieve[i])
                    primes[cnt++] = i;

            return Arrays.copyOf(primes, cnt);
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