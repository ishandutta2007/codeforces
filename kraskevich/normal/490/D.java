import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;


public class Task {
    final long INF = (long)1e18;

    long apply(long init, int div3, int div2) {
        for (int i = 0; i < div3; i++) {
            if (init % 3 != 0)
                return -1;
            init /= 3;
            init *= 2;
        }
        for (int i = 0; i < div2; i++) {
            if (init % 2 != 0)
                return -1;
            init /= 2;
        }
        return init;
    }

    class Data implements Comparable<Data> {
        int steps;
        long width;
        long height;

        Data(int steps, long width, long height) {
            this.steps = steps;
            this.width = width;
            this.height = height;
        }

        long getArea() {
            return width * height;
        }

        @Override
        public int compareTo(Data other) {
            return steps - other.steps;
        }
    }

    Map<Long, Data> generate(long width, long height) {
        Map<Long, Data> res = new HashMap<>();
        for (int wd3 = 0; wd3 < 20; wd3++)
            for (int wd2 = 0; wd2 < 50; wd2++) {
                long curW = apply(width, wd3, wd2);
                if (curW == -1)
                    break;
                for (int hd3 = 0; hd3 < 20; hd3++)
                    for (int hd2 = 0; hd2 < 50; hd2++) {
                        long curH = apply(height, hd3, hd2);
                        if (curH == -1)
                            break;
                        long area = curW * curH;
                        Data curData = new Data(wd3 + wd2 + hd3 + hd2, curW, curH);
                        if (!res.containsKey(area) || res.get(area).compareTo(curData) > 0)
                            res.put(area, curData);
                    }
            }
        return res;
    }

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        long w1 = in.nextInt();
        long h1 = in.nextInt();
        long w2 = in.nextInt();
        long h2 = in.nextInt();
        long res = -1;
        long resW1 = 0;
        long resH1 = 0;
        long resW2 = 0;
        long resH2 = 0;
        Map<Long, Data> map1 = generate(w1, h1);
        Map<Long, Data> map2 = generate(w2, h2);
        for (Long elem : map1.keySet()) {
            if (!map2.containsKey(elem))
                continue;
            Data first = map1.get(elem);
            Data second = map2.get(elem);
            if (res == -1 || first.steps + second.steps < res) {
                res = first.steps + second.steps;
                resW1 = first.width;
                resH1 = first.height;
                resW2 = second.width;
                resH2 = second.height;
            }
        }
        out.println(res);
        if (res != -1) {
            out.println(resW1 + " " + resH1);
            out.println(resW2 + " " + resH2);
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        for (int i = 0; i < t; i++)
            new Task().solve(in, out);
        out.flush();
    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = reader.readLine();
                if (line == null)
                    throw new IOException();
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public void close() {
            try {
                reader.close();
            } catch (IOException e) {
                // ignore
            }
        }
    }
}