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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();

            int value = process(in.nextInt());
            for (int i = 1; i < n; i++) {
                if (process(in.nextInt()) != value) {
                    out.println("No");
                    return;
                }
            }

            out.println("Yes");
        }

        private int process(int x) {
            while (x % 2 == 0) {
                x /= 2;
            }

            while (x % 3 == 0) {
                x /= 3;
            }

            return x;
        }

    }
}