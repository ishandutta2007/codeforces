import java.util.Scanner;
import java.util.List;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Set;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author 
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        int m = in.nextInt();
        int[] c = new int[m];
        int[] d = new int[m];
        int[] k = new int[m];
        for (int i = 0; i < m; ++i) {
            c[i] = in.nextInt();
            d[i] = in.nextInt();
            k[i] = in.nextInt();
        }

        List<int[]> events = new ArrayList<int[]>();
        for (int i = 0; i < n; ++i) {
            events.add(new int[] {a[i], 0, i});
        }
        for (int i = 0; i < m; ++i) {
            events.add(new int[] {c[i], -1, i});
        }

        Collections.sort(events, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                for (int i = 0; i < o1.length; ++i) {
                    if (o1[i] != o2[i]) {
                        return o1[i] - o2[i];
                    }
                }
                return 0;
            }
        });

        int[] allRightEnds = new int[n + m];
        for (int i = 0; i < n; ++i) {
            allRightEnds[i] = b[i];
        }
        for (int i = 0; i < m; ++i) {
            allRightEnds[n + i] = d[i];
        }
        Order rightEnds = new Order(allRightEnds);

        values = new List[rightEnds.size()];
        for (int i = 0; i < rightEnds.size(); ++i) {
            values[i] = new ArrayList<Integer>();
        }
        int[] answer = new int[n];
        NavigableSet<Integer> activeRightEnds = new TreeSet<Integer>();
        for (int[] event : events) {
            int whose = event[2];
            if (event[1] == 0) {
                // Query
                int right = b[whose];
                Integer nextRight = activeRightEnds.higher(right - 1);
                if (nextRight == null) {
                    out.println("NO");
                    return;
                }
                nextRight = rightEnds.get(nextRight);
                int last = values[nextRight].size() - 1;
                answer[whose] = values[nextRight].get(last);
                if (--k[values[nextRight].get(last)] == 0) {
                    values[nextRight].remove(last);
                    if (values[nextRight].isEmpty()) {
                        activeRightEnds.remove(rightEnds.getByIndex(nextRight));
                    }
                }
            } else if (event[1] == -1) {
                int right = rightEnds.get(d[whose]);
                values[right].add(whose);
                activeRightEnds.add(d[whose]);
            }
        }
        out.println("YES");
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(answer[i] + 1);
        }
    }

    private List<Integer>[] values;

    static class Order {

        private int arr[];

        Order(int orig[]) {
            int temp[] = orig.clone();
            Arrays.sort(temp);

            int total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    ++total;

            arr = new int[total];
            arr[0] = temp[0];
            total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    arr[total++] = temp[i];
        }

        public int size() {
            return arr.length;
        }

        public int get(int x) {
            return Arrays.binarySearch(arr, x);
        }

        public int getByIndex(int x) {
            return arr[x];
        }
    }
}