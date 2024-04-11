import java.io.InputStreamReader;
import java.io.IOException;
import java.util.TreeMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int a[] = ArrayUtils.readIntArray(in, n);
                ArrayUtils.sort(a);
                if (n == 1) {
                        out.println(-1);
                        return;
                }
                TreeMap<Integer, Integer> count = new TreeMap<>();
                for (int i = 1; i < n; i++)
                        if (count.containsKey(a[i] - a[i - 1]))
                                count.put(a[i] - a[i - 1], count.get(a[i] - a[i - 1]) + 1);
                        else
                                count.put(a[i] - a[i - 1], 1);
                TreeSet<Integer> res = new TreeSet<>();
                if (count.size() == 1) {
                        res.add(a[0] - count.firstKey());
                        res.add(a[n - 1] + count.firstKey());
                }
                if (count.size() >= 3) {
                        out.println(0);
                        return;
                }
                for (int i = 1; i < n; i++) {
                        int d = a[i] - a[i - 1];
                        if (d % 2 == 1 || d == 0)
                                continue;
                        int cnt2 = 0;
                        if (count.containsKey(d / 2))
                                cnt2 = count.get(d / 2);
                        cnt2 += 2;
                        if (cnt2 == n)
                                res.add(a[i] - d / 2);
                }
                out.println(res.size());
                for (int elem : res)
                        out.print(elem + " ");
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

        public static int[] readIntArray(FastScanner in, int count) {
                int[] array = new int[count];
                for (int i = 0; i < count; i++)
                        array[i] = in.nextInt();
                return array;
        }


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