import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.nextLine();
        s = s.replace(" ", "");
        String left = s.split("=")[0];
        String right = s.split("=")[1];
        String[] signs = left.split("\\Q?\\E");
        long n = Long.valueOf(right);
        long pos = 1;
        long neg = 0;
       for (String sign : signs)
            if (sign.equals("+"))
                pos++;
            else
                neg++;
        if (pos + neg > 1)
            neg--;
        long maxValue = n * pos - neg;
        long minValue = pos - n * neg;
        if (n < minValue || maxValue < n) {
            out.println("Impossible");
            return;
        }
        out.println("Possible");
        ArrayList<Long> positives = new ArrayList<>();
        for (int i = 0; i < pos; i++)
            positives.add(n);
        ArrayList<Long> negatives = new ArrayList<>();
        for (int i = 0; i < neg; i++)
            negatives.add(1L);
        long curValue = maxValue;
        for (int i = 0; i < pos; i++) {
            if (curValue > n) {
                long delta = Math.min(curValue - n, n - 1);
                positives.set(i, n - delta);
                curValue -= delta;
            }
        }
        for (int i = 0; i < neg; i++) {
            if (curValue > n) {
                long delta = Math.min(curValue - n, n - 1);
                negatives.set(i, 1 + delta);
                curValue -= delta;
            }
        }
        ArrayList<Long> numbers = new ArrayList<>();
        int posPtr = 0;
        int negPtr = 0;
        numbers.add(positives.get(posPtr++));
        for (int i = 1; i < signs.length; i++) {
            if (signs[i].equals("+")) {
                numbers.add(positives.get(posPtr++));
            } else {
                numbers.add(negatives.get(negPtr++));
            }
        }
        int sPtr = 1;
        for (long num : numbers) {
            out.print(num + " ");
            if (sPtr < signs.length)
                out.print(signs[sPtr++] + " ");
        }
        out.print("= ");
        out.println(n);
    }
}

class FastScanner {
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {

        }
        return null;
    }

}