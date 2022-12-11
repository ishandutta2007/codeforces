import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kanstantsin Sokal
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int[] positions;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            positions = new int[n];

            for (int i = 0; i < n; i++) {
                int x = in.nextInt() - 1;
                positions[x] = i;
            }

            long answer = 0;
            for (int i = 1; i < n; i++) {
                int a = positions[i - 1];
                int b = positions[i];

                answer += Math.abs(a - b);
            }

            out.println(answer);
        }

    }
}