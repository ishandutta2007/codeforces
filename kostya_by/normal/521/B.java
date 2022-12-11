import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
import java.util.SortedSet;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.util.SortedMap;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Constantine Sokol
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    final int MOD = 1000000009;

    SortedSet<Integer> set;
    SortedMap<Pair, Integer> map;
    int[][] points;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        set = new TreeSet<>();
        map = new TreeMap<>();
        points = new int[2][n];
        for (int i = 0; i < n; i++) {
            points[0][i] = in.nextInt();
            points[1][i] = in.nextInt();
            map.put(new Pair(points[0][i], points[1][i]), i);

        }
        for (int i = 0; i < n; i++) {
            if (isFree(i)) {
                set.add(i);
            }
        }
        long answer = 0;
        for (int i = 0; i < n; i++) {
            int current;
            if (i % 2 == 0) {
                current = set.last();
            } else {
                current = set.first();
            }
            answer = (answer * n + current) % MOD;
            set.remove(current);
            map.remove(new Pair(points[0][current], points[1][current]));
            trySetFree(points[0][current] - 1, points[1][current] - 1);
            trySetFree(points[0][current], points[1][current] - 1);
            trySetFree(points[0][current] + 1, points[1][current] - 1);
            tryUnsetFree(points[0][current] - 1, points[1][current]);
            tryUnsetFree(points[0][current] + 1, points[1][current]);
            tryUnsetFree(points[0][current] - 2, points[1][current]);
            tryUnsetFree(points[0][current] + 2, points[1][current]);
        }
        out.println(answer);
    }

    void trySetFree(int x, int y) {
        int id = getId(x, y);
        if (id == -1) {
            return;
        }
        if (isFree(id)) {
            set.add(id);
        }
    }

    void tryUnsetFree(int x, int y) {
        int id = getId(x, y);
        if (id == -1) {
            return;
        }
        if (!isFree(id) && set.contains(id)) {
            set.remove(id);
        }
    }

    int getId(int x, int y) {
        Pair pair = new Pair(x, y);
        Integer id = map.get(pair);
        if (id != null) {
            return id;
        }
        return -1;
    }

    int countUnder(int x, int y) {
        int count = 0;
        if (map.containsKey(new Pair(x - 1, y - 1))) {
            count += 1;
        }
        if (map.containsKey(new Pair(x, y - 1))) {
            count += 1;
        }
        if (map.containsKey(new Pair(x + 1, y - 1))) {
            count += 1;
        }
        return count;
    }

    boolean isFree(int id) {
        int x = points[0][id];
        int y = points[1][id];
        if (map.containsKey(new Pair(x - 1, y + 1))) {
            if (countUnder(x - 1, y + 1) == 1) {
                return false;
            }
        }
        if (map.containsKey(new Pair(x, y + 1))) {
            if (countUnder(x, y + 1) == 1) {
                return false;
            }
        }
        if (map.containsKey(new Pair(x + 1, y + 1))) {
            if (countUnder(x + 1, y + 1) == 1) {
                return false;
            }
        }
        return true;
    }
}

class Pair implements Comparable<Pair> {
    int first;
    int second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    public int compareTo(Pair another) {
        if (first != another.first) {
            return first - another.first;
        }
        return second - another.second;
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }
}