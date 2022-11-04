import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author 
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] map = new char[n][];
        for (int i = 0; i < n; ++i) {
            map[i] = in.next().toCharArray();
        }
        int[] group = new int[n];
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            boolean hasToRemove = false;
            for (int j = 0; j < n; ++j) {
                if (j == 0 || group[j] != group[j - 1]) {
                    continue;
                }
                if (map[j - 1][i] > map[j][i]) {
                    hasToRemove = true;
                    break;
                }
            }
            if (hasToRemove) {
                ++answer;
                continue;
            }
            int colors = -1;
            for (int j = n - 1; j >= 0; --j) {
                int originalGroup = group[j];
                group[j] = colors;
                if (j == 0 || originalGroup != group[j - 1]) {
                    ++colors;
                } else {
                    if (map[j - 1][i] != map[j][i]) {
                        ++colors;
                    }
                }
            }
        }

        out.println(answer);
    }
}