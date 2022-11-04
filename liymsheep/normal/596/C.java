import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Map;
import java.io.BufferedReader;
import java.util.List;
import java.util.Collections;
import java.util.TreeMap;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.Map.Entry;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            HashMap<Integer, List<int[]>> map = new HashMap<Integer, List<int[]>>();
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                int delta = y - x;
                if (!map.containsKey(delta)) {
                    map.put(delta, new ArrayList<int[]>());
                }
                map.get(delta).add(new int[]{x, y});
            }

            HashMap<Integer, Integer> first = new HashMap<Integer, Integer>();

            for (Map.Entry<Integer, List<int[]>> entry : map.entrySet()) {
                first.put(entry.getKey(), 0);
                Collections.sort(entry.getValue(), new Comparator<int[]>() {

                    public int compare(int[] o1, int[] o2) {
                        if (o1[0] != o2[0]) {
                            return Integer.compare(o1[0], o2[0]);
                        }
                        return Integer.compare(o1[1], o2[1]);
                    }
                });
            }


            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; ++i) {
                int delta = in.nextInt();
                if (!map.containsKey(delta)) {
                    out.println("NO");
                    return;
                }
                if (first.get(delta) >= map.get(delta).size()) {
                    out.println("NO");
                    return;
                }
                x[i] = map.get(delta).get(first.get(delta))[0];
                y[i] = map.get(delta).get(first.get(delta))[1];

                first.put(delta, first.get(delta) + 1);
            }
//        for (int i = 0; i < n; ++i) {
//            out.println(x[i] + " " + y[i]);
//        }

            TreeMap<Integer, Integer> tree = new TreeMap<Integer, Integer>();
            for (int i = 0; i < n; ++i) {
                Integer higher = tree.higherKey(x[i] - 1);
                if (higher != null && tree.get(higher) >= y[i]) {
                    out.println("NO");
                    return;
                }
                while (true) {
                    Integer lower = tree.lowerKey(x[i] + 1);
                    if (lower != null && tree.get(lower) <= y[i]) {
                        tree.remove(lower);
                    } else {
                        break;
                    }
                }

                tree.put(x[i], y[i]);
            }

            out.println("YES");
            for (int i = 0; i < n; ++i) {
                out.println(x[i] + " " + y[i]);
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}