import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        A solver = new A();
        solver.solve(1, in, out);
        out.close();
    }

    static class A {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int N = in.nextInt();
            int[] F = new int[N];
            for (int i = 0; i < N; i++) {
                F[i] = in.nextInt();
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N-1; j++) {
                    if (F[j] > F[j + 1]) {
                        out.format("%d %d\n", j + 1, j + 2);
                        int q = F[j];
                        F[j] = F[j + 1];
                        F[j + 1] = q;
                    }
                }
            }
        }

    }
}