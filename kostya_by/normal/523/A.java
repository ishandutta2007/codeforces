import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author kostya_by
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
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int m = in.nextInt();
        int n = in.nextInt();
        char[][] field = new char[n][];
        for (int i = 0; i < n; i++) {
            field[i] = in.next().toCharArray();
        }
        for (int i = 0; i < 2 * m; i++) {
            for (int j = 0; j < 2 * n; j++) {
                out.print(field[j / 2][i / 2]);
            }
            out.print("\n");
        }
    }
}