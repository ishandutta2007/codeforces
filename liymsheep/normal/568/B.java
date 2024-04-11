import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Yang
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
}

class TaskB {
    private static final int MODULO = 1000000007;
    private static final int SIZE = 4007;
    private static final int[][] CHOOSE;
    private static final int[] POWER;

    static {
        CHOOSE = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i) {
            CHOOSE[i][0] = CHOOSE[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                CHOOSE[i][j] = CHOOSE[i - 1][j] + CHOOSE[i - 1][j - 1];
                if (CHOOSE[i][j] >= MODULO) {
                    CHOOSE[i][j] -= MODULO;
                }
            }
        }

        POWER = new int[SIZE * SIZE];
        POWER[0] = 1;
        for (int i = 1; i < POWER.length; ++i) {
            POWER[i] = POWER[i - 1] + POWER[i - 1];
            if (POWER[i] >= MODULO) {
                POWER[i] -= MODULO;
            }
        }
    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] f = new int[n + 1];
        int[] g = new int[n + 1];
        f[0] = 1;
        f[1] = 1;
        g[0] = g[1] = 1;
        for (int i = 2; i <= n; ++i) {
            g[i] = POWER[i * (i - 1) / 2];
            f[i] = f[i - 1];
            for (int j = 1; j < i; ++j) {
                f[i] = (int) ((f[i] + CHOOSE[i - 1][j] * (long) (f[i - 1 - j])) % MODULO);
            }
//            out.println("f[" + i + "] = " + f[i]);
        }
        int[] t = new int[n + 1];
        t[0] = 1;
        t[1] = 2;
        for (int i = 2; i <= n; ++i) {
            t[i] = (t[i - 1] * 2) % MODULO;
            for (int j = 1; j < i; ++j) {
                t[i] = (int) ((t[i] + CHOOSE[i - 1][j] * (long) (t[i - 1 - j])) % MODULO);
            }
//            out.println("t[" + i + "] = " + t[i]);
        }
        out.println((t[n] - f[n] + MODULO) % MODULO);
    }
}