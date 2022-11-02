import java.io.*;
import java.util.*;

public class Task {

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[k];
        for (int i = 0; i < k; i++)
            a[i] = in.nextInt();
        int[] lastUse = new int[k];
        Arrays.fill(lastUse, -1);
        boolean[] canBeFirst = new boolean[k];
        int[] sum = new int[k];
        int[] dish = new int[n - 1];
        int[] upset = new int[n - 1];
        int pos = -1;
        for (int i = 0; i < n - 1; i++) {
            dish[i] = in.nextInt();
            dish[i]--;
            if (dish[i] >= 0)
                lastUse[dish[i]] = i;
            upset[i] = in.nextInt();
            if (upset[i] == 1 && pos == -1)
                pos = i;
        }
        if (pos == -1) {
            int free = 0;
            for (int i = 0; i < dish.length; i++)
                if (dish[i] < 0)
                    free++;
                else
                    sum[dish[i]]++;
            for (int i = 0; i < k; i++)
                if (free + sum[i] >= a[i])
                    out.print("Y");
                else
                    out.print("N");
            out.println();
            return;
        }
        int minFirst = n;
        int free = 0;
        for (int i = 0; i < pos; i++)
            if (dish[i] >= 0)
                sum[dish[i]]++;
            else
                free++;
        for (int i = 0; i < k; i++) {
            if (lastUse[i] >= pos)
                continue;
            if (free + sum[i] >= a[i]) {
                canBeFirst[i] = true;
                minFirst = Math.min(minFirst, a[i] - sum[i]);
            }
        }
        for (int i = pos; i < dish.length; i++)
            if (dish[i] >= 0)
                sum[dish[i]]++;
            else
                free++;
        for (int i = 0; i < k; i++)
            if (canBeFirst[i] || free - minFirst + sum[i] >= a[i])
                out.print("Y");
            else
                out.print("N");
        out.println();
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++)
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