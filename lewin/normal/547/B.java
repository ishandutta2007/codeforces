import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    private static double EPS = 0.000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(char[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + "");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static class Range {
        int start;
        int end;
        public Range(int s, int e) {
            start = s;
            end = e;
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int n = nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) heights[i] = nextInt();
        int[] partner = new int[n];
        for (int i = 0; i < n; i++) partner[i] = -1;

        Set<Integer> heightSet = new HashSet<Integer>();
        for (int i = 0; i < n; i++) heightSet.add(heights[i]);
        List<Integer> reversed = new ArrayList<Integer>();
        reversed.addAll(heightSet);
        Collections.sort(reversed);
        Collections.reverse(reversed);

        Map<Integer, List<Integer>> indices = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < n; i++) {
            if (!indices.containsKey(heights[i])) indices.put(heights[i], new ArrayList<Integer>());
            indices.get(heights[i]).add(i);
        }

        List<Integer> maxSize = new ArrayList<Integer>();
        List<Integer> res = new ArrayList<Integer>();
        int last = 0;
        for (int x : reversed) {
            int max = 1;
            for (int i : indices.get(x)) {
                boolean left = i > 0 && partner[i-1] != -1;
                boolean right = i < n - 1 && partner[i+1] != -1;
                if (!left && !right) partner[i] = i;
                else if (!left) {
                    int j = partner[i+1];
                    partner[i] = j;
                    partner[j] = i;
                    max = Math.max(max, j - i + 1);
                } else if (!right) {
                    partner[i] = partner[i-1];
                    partner[partner[i]] = i;
                    max = Math.max(max, i - partner[i] + 1);
                } else {
                    int j = partner[i-1];
                    partner[j] = partner[i+1];
                    partner[partner[j]] = j;
                    max = Math.max(max, partner[j] - j + 1);
                }
            }
            maxSize.add(max);
            while (last < max) {
                res.add(x);
                last++;
            }
        }
        print(join(res, " "));
    }
}