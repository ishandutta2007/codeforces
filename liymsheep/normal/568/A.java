import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    private static final int MAX_NUMBER = 10000001;
    private static final boolean isPrime[];
    static {
        isPrime = new boolean[MAX_NUMBER];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX_NUMBER; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i + i; j < MAX_NUMBER; j += i) {
                isPrime[j] = false;
            }
        }
    }

    static int arr[] = new int[10];
    private static boolean isPal(int x) {
        int len = 0;
        while (x != 0) {
            arr[len++] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < len - 1 - i; ++i) {
            if (arr[i] != arr[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long p = in.nextLong();
        long q = in.nextLong();
        int c1 = 0, c2 = 0;
        // c1 * q <= c2 * p
        int maxv = 0;
        for (int i = 1; i < MAX_NUMBER; ++i) {
            if (isPrime[i]) ++c1;
            if (isPal(i)) ++c2;

            if (c1 * q <= c2 * p) {
                maxv = i;
            }
        }
        out.println(maxv);
    }
}