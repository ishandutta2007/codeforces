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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                String s = in.nextToken();
                int n = s.length();
                int[][] next = new int[n][26];
                for (char c = 'a'; c <= 'z'; c++) {
                        int last = n;
                        for (int i = n - 1; i >= 0; i--)   {
                                if (s.charAt(i) == c)
                                        last = i;
                                next[i][c - 'a'] = last;
                        }
                }
                long[] cnt = new long[27];
                for (int i = 0; i < n; i++) {
                        int[] pos = new int[26];
                        for (int j = 0; j < 26; j++)
                                pos[j] = next[i][j];
                        ArrayUtils.sort(pos);
                        for (int c = 0; c < pos.length; c++) {
                                int last = c == pos.length - 1 ? n : pos[c + 1]; 
                                cnt[c + 1] += last - pos[c];
                        }
                }
                int max = 26;
                while (cnt[max] == 0)
                        max--;
                out.println(max);
                for (int i = 1; i <= max; i++)
                        out.println(cnt[i]);
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