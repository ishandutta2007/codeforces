import java.io.*;
import java.util.*;

public class Task {

    final int OPEN = 0;
    final int CLOSE = 1;

    class Event {
        int time;
        int id;
        int type;

        Event(int time, int type, int id) {
            this.time = time;
            this.type = type;
            this.id = id;
        }
    }

    int stringToInt(String s) {
        if (s.startsWith("0"))
            return Integer.parseInt(s.substring(1));
        return Integer.parseInt(s);
    }

    int readTime(FastScanner in) {
        String s = in.next();
        String[] parts = s.split(":");
        int h = stringToInt(parts[0]);
        int m = stringToInt(parts[1]);
        int ss = stringToInt(parts[2]);
        return h * 60 * 60 + m * 60 + ss;
    }

    void add(TreeMap<Integer, Integer> map, int val, int delta) {
        int cur = map.getOrDefault(val, 0);
        cur += delta;
        if (cur == 0)
            map.remove(val);
        else
            map.put(val, cur);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int T = in.nextInt();
        int maxSize = 0;
        ArrayList<Event> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int time = readTime(in);
            events.add(new Event(time, OPEN, i));
            events.add(new Event(time + T - 1, CLOSE, i));
        }
        TreeMap<Integer, Integer> now = new TreeMap<>();
        Collections.sort(events, new Comparator<Event>() {
            @Override
            public int compare(Event o1, Event o2) {
                if (o1.time != o2.time)
                    return Integer.compare(o1.time, o2.time);
                return Integer.compare(o1.type, o2.type);
            }
        });
        int[] color = new int[n];
        int newCol = 1;
        int lastCol = -1;
        for (Event e : events) {
            if (e.type == CLOSE) {
                add(now, color[e.id], -1);
            } else {
                int cur;
                if (now.size() != m) {
                    cur = newCol++;
                } else {
                    cur = lastCol;
                }
                color[e.id] = cur;
                lastCol = cur;
                add(now, cur, 1);
                maxSize = Math.max(maxSize, now.size());
            }
        }
        if (maxSize != m) {
            out.println("No solution");
            return;
        }
        out.println(newCol - 1);
        for (int i = 0; i < n; i++)
            out.println(color[i]);
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int testsCount = 1;
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}