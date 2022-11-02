import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                        a[i] = in.nextInt();
                ArrayUtils.sort(a);
                int t = in.nextInt();
                int res = 0;
                for (int i = 0; i < n; i++)
                        for (int j = i; j < n; j++)
                                if (a[j] - a[i] <= t)
                                        res = Math.max(res, j - i + 1);
                out.println(res);
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        }

class ArrayUtils {


        private static int[] intBuffer;

        public static void sort(int[] array) {
                if (array.length == 0)
                        return;
                intBuffer = new int[array.length];
                mergeSort(array, 0, array.length - 1);
        }

        private static void mergeSort(int[] array, int low, int high) {
                if (low == high)
                        return;
                int middle = (low + high) / 2;
                mergeSort(array, low, middle);
                mergeSort(array, middle + 1, high);
                merge(array, low, middle + 1, middle + 1, high + 1);
        }

        private static void merge(int[] array, int first1, int last1, int first2, int last2) {
                int start = first1;
                int pos = 0;
                while (first1 < last1 || first2 < last2) {
                        if (first1 < last1 && (first2 == last2 || array[first1] <= array[first2]))
                                intBuffer[pos++] = array[first1++];
                        else
                                intBuffer[pos++] = array[first2++];
                }
                System.arraycopy(intBuffer, 0, array, start, pos);
        }


        }