import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

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
            int n = in.nextInt(), q = in.nextInt();
            int freeservers = n;
            PriorityQueue<TaskC.Server> free = new PriorityQueue<>((a, b) -> (a.id - b.id));
            PriorityQueue<TaskC.Server> busy = new PriorityQueue<>((a, b) -> (a.timefree - b.timefree));
            for (int i = 1; i <= n; i++) free.add(new TaskC.Server(i, -1));
            for (int i = 0; i < q; i++) {
                int time = in.nextInt(), need = in.nextInt(), duration = in.nextInt();
                while (busy.size() > 0 && busy.peek().timefree <= time) {
                    free.add(busy.poll());
                }

                if (need > free.size()) {
                    out.println(-1);
                } else {
                    int ans = 0;
                    for (int j = 0; j < need; j++) {
                        TaskC.Server s = free.poll();
                        s.timefree = time + duration;
                        busy.add(s);
                        ans += s.id;
                    }
                    out.println(ans);
                }
            }
        }

        static class Server {
            public int id;
            public int timefree;

            public Server(int id, int timefree) {
                this.id = id;
                this.timefree = timefree;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}