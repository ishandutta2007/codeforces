import java.io.*;
import java.util.*;

public class weirdarray {
  private static InputReader in;
  private static PrintWriter out;
  public static int MAXA = 200001;
  public static ArrayList<Integer>[] f;
  
  public static long[] vals;
  public static boolean[] sameblock;
  public static long[] blockval;
  public static long[] blocksum;
  public static int n;
  public static int BLOCK_SIZE = 300;
  public static int NUM_BLOCKS;

  public static void push(int block) {
    if (sameblock[block]) {
      int start = block * BLOCK_SIZE;
      int end = Math.min(n, start+BLOCK_SIZE);
      Arrays.fill(vals, start, end, blockval[block]);
      blocksum[block] = blockval[block] * (long)(end-start);
      sameblock[block] = false;
    }
  }

  public static void update(int l, int r, long x) {
    if (l > r) return;
    int b1 = (l / BLOCK_SIZE);
    push(b1);
    for (int i = l; i < (b1 + 1) * BLOCK_SIZE && i <= r; i++) {
      blocksum[b1] -= vals[i];
      vals[i] = x;
      blocksum[b1] += vals[i];
    }
    int b2 = (r / BLOCK_SIZE);
    if (b1 == b2) return;
    for (int i = b1+1; i < b2; i++) {
      sameblock[i] = true;
      blockval[i] = x;
      blocksum[i] = x * BLOCK_SIZE;
    }
    push(b2);
    for (int i = b2 * BLOCK_SIZE; i <= r; i++) {
      blocksum[b2] -= vals[i];
      vals[i] = x;
      blocksum[b2] += vals[i];
    }
  }
  
  public static long getSum(int l, int r) {
    if (l > r) return 0;
    long ret = 0;
    int b1 = (l / BLOCK_SIZE);
    push(b1);
    for (int i = l; i < (b1 + 1) * BLOCK_SIZE && i <= r; i++) {
      ret += vals[i];
    }
    int b2 = (r / BLOCK_SIZE);
    if (b1 == b2) return ret;
    for (int i = b1+1; i < b2; i++) {
      ret += blocksum[i];
    }
    push(b2);
    for (int i = b2 * BLOCK_SIZE; i <= r; i++) {
      ret += vals[i];
    }
    return ret;
  }

  public static long get(int pos) {
    int which = pos / BLOCK_SIZE;
    if (sameblock[which]) return blockval[which];
    return vals[pos];
  }
  
  public static int getIdx(long val, int lo, int hi) {
    while (lo<hi) {
      int mid = (lo+hi)>>1;
      if (get(mid) >= val) lo = mid+1;
      else hi = mid;
    }
    return lo;
  }
  
  public static void set(int end, long val) {
    if (end < 0) return;
    if (val < get(end)) return;
    int b = getIdx(val, 0, end);
    update(b, end, val);
  }
  
  public static long query(int start, long maxseen) {
    if (start >= n) return 0;
    int b = getIdx(maxseen, start, n);
    return getSum(start, b-1) + ((long)n-b)*(long)maxseen;
  }

  static class GCD {
    public boolean[] seen;
    public int[] firstseen;
    public long maxseen;
    public GCD() {
      seen = new boolean[MAXA];
      firstseen = new int[MAXA];
      Arrays.fill(firstseen, -10);
    }
    
    public void insert(int time, int num) {
      for (int x : f[num]) {
        if (seen[x]) maxseen = Math.max(maxseen, x);
        else {
          seen[x] = true;
          firstseen[x] = time;
        }
      }
    }
  }
  
  public static long count(int[] arr) {
    int n = arr.length;
    GCD forward = new GCD();
    GCD backward = new GCD();
    long ans = 0;
    for (int i = n-1; i >= 0; i--) {
      backward.insert(i, arr[i]);
      vals[i] = backward.maxseen;
      blocksum[i/BLOCK_SIZE] += vals[i];
      if (i != 0) ans += backward.maxseen;
    }
    for (int i = 0; i < n-1; i++) {
      forward.insert(i, arr[i]);
      for (int div : f[arr[i]]) {
        set(backward.firstseen[div], div);
      }
      long add = query(i+2, forward.maxseen) + forward.maxseen;
      ans += add;
    }
    
    return ans;
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    f = new ArrayList[MAXA];
    for (int i = 0; i < f.length; i++) f[i] = new ArrayList<>();
    for (int i = 1; i < f.length; i++) {
      for (int j = i; j < f.length; j += i)
        f[j].add(i);
    }
    n = in.nextInt();
    NUM_BLOCKS = n/BLOCK_SIZE+10;
    vals = new long[n];
    sameblock = new boolean[NUM_BLOCKS];
    blockval = new long[NUM_BLOCKS];
    blocksum = new long[NUM_BLOCKS];
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    out.println(count(arr));
    out.close();
    System.exit(0);
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