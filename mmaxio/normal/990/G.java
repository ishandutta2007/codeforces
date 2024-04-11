import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Collection;
import java.util.NoSuchElementException;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author beginner1010
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskG {
        final int maxN = (int) 2e5 + 5;
        long[] count;
        EzIntArrayList[] adj;
        int[] a;
        ArrayList<Integer>[] nodes;
        int[] timer;
        int[] valid;
        int[] Q;
 
        int bfs(int source, int curTimer) {
            int beg = 0;
            int end = 0;
            Q[end++] = source;
            timer[source] = curTimer;
            int ans = 0;
            while (beg < end) {
                int node = Q[beg++];
                ans++;
                for (int i = 0; i < adj[node].size(); i++) {
                  int neighbor = adj[node].get(i);
                  if (timer[neighbor] != curTimer && valid[a[neighbor]] == curTimer) {
                      timer[neighbor] = curTimer;
                      Q[end++] = neighbor;
                  }
                }
            }
            return ans;
        }
 
        public void solve(int testNumber, InputReader in, PrintWriter out) {
 
            int n = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            adj = new EzIntArrayList[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new EzIntArrayList();
            }
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                adj[a].add(b);
                adj[b].add(a);
            }
 
            nodes = new ArrayList[maxN];
            for (int i = 0; i < n; i++) {
                if (nodes[a[i]] == null) nodes[a[i]] = new ArrayList<>();
                nodes[a[i]].add(i);
            }
 
            count = new long[maxN];
            timer = new int[n];
            Q = new int[n];
            valid = new int[maxN];
            for (int i = maxN - 1; i >= 1; i--) {
                int curTimer = i;
                for (int j = i; j < maxN; j += i) valid[j] = curTimer;
                for (int j = i; j < maxN; j += i)
                    if (nodes[j] != null) {
                        for (int start : nodes[j]) {
                            if (timer[start] == curTimer) continue;
                            long cnt = bfs(start, curTimer);
                            count[i] += (cnt * (cnt + 1)) >> 1;
                        }
                    }
                for (int j = i + i; j < maxN; j += i) {
                    count[i] -= count[j];
                }
            }
            for (int i = 0; i < maxN; i++) {
                if (count[i] > 0) out.println(i + " " + count[i]);
            }
        }
 
    }
 
    static class InputReader {
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputStream stream;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        private boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int nextInt() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }
 
    }
}
 
class EzIntArrayList {
  private static final int DEFAULT_CAPACITY = 10;
  private static final double ENLARGE_SCALE = 2.0;
  private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
  private static final int HASHCODE_MULTIPLIER = 0x01000193;
 
  private int[] array;
  private int size;
 
  public EzIntArrayList() {
      this(DEFAULT_CAPACITY);
  }
 
  public EzIntArrayList(int capacity) {
      if (capacity < 0) {
          throw new IllegalArgumentException("Capacity must be non-negative");
      }
      array = new int[capacity];
      size = 0;
  }
 
  public EzIntArrayList(int[] srcArray) {
      size = srcArray.length;
      array = new int[size];
      System.arraycopy(srcArray, 0, array, 0, size);
  }
 
  public EzIntArrayList(Collection<Integer> javaCollection) {
      size = javaCollection.size();
      array = new int[size];
      int i = 0;
      for (int element : javaCollection) {
          array[i++] = element;
      }
  }
 
  public int size() {
      return size;
  }
 
    public boolean add(int element) {
      if (size == array.length) {
          enlarge();
      }
      array[size++] = element;
      return true;
  }
 
    public int get(int index) {
      return array[index];
  }
 
    private void enlarge() {
      int newSize = Math.max(size + 1, (int) (size * ENLARGE_SCALE));
      int[] newArray = new int[newSize];
      System.arraycopy(array, 0, newArray, 0, size);
      array = newArray;
  }
 
}