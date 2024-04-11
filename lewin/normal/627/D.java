import java.io.*;
import java.util.*;

public class preordertest {
  private static InputReader in;
  private static PrintWriter out;
  public static int n,k,t;
  public static ArrayList<Integer>[] graph;
  public static int[] arr;
  public static int[] queue;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    n = in.nextInt();
    k = in.nextInt();
    arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    int[] brr = Arrays.copyOf(arr, n);
    for (int i = 0; i < n; i++) {
      int j = (int)(Math.random()*(i+1));
      if (j == i) continue;
      int t = brr[i]; brr[i] = brr[j]; brr[j] = t;
    }
    Arrays.sort(brr);
    
    graph = new ArrayList[n];
    for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
    for (int i = 0; i < n-1; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
    }
    
    queue = new int[n];
    freedown = new int[n];
    countdown = new int[n];
    size = new int[n];
    pp = new int[n];
    maxdown = new int[n];
    md1 =  new int[n];
    md2 = new int[n];
    mxid1 = new int[n];
    maxup = new int[n];
    int front = 0, back = 0;
    queue[back++] = 0;
    pp[0] = -1;
    boolean[] vis = new boolean[n];
    vis[0] = true;
    while(front<back) {
      int cur = queue[front++];
      for (int next : graph[cur]) {
        if (vis[next]) continue;
        queue[back++] = next;
        pp[next] = cur;
        vis[next] = true;
      }
    }
    int lo = 0, hi = n-1;
    while(lo<hi) {
      int mid = (lo+hi+1)/2;
      if (f(brr[mid]) < k) hi = mid-1;
      else lo = mid;
    }
    
    out.println(brr[lo]);
    out.close();
    System.exit(0);
  }
  
  public static boolean[] good;
  public static int f(int thresh) {
    good = new boolean[n];
    freeup = new boolean[n];
    t = 0;
    for (int i = 0; i < n; i++) {
      good[i] = arr[i] >= thresh;
      t += good[i] ? 1 : 0;
    }
    dfs0();
    dfs1();
    dfs2();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int inpar = t - countdown[i];
      int szpar = n - size[i];
      if (!good[i]) continue;
      int ret = 0;
      if (inpar == szpar) {
        ret = freedown[i] + md1[i] + szpar;
      } else if (countdown[i] == size[i]) {
        ret = size[i] + maxup[i];
      } else {
        ret = freedown[i] + Math.max(md1[i], maxup[i]);
      }
      ans = Math.max(ans, ret);
    }
    
    return ans;
  }
  
  public static int[] countdown, size, pp;
  public static void dfs0() {
    for (int i = n-1; i >= 0; i--) {
      int node = queue[i];
      countdown[node] = good[node] ? 1 : 0;
      size[node] = 1;
      for (int next : graph[node]) {
        if (next == pp[node]) continue;
        countdown[node] += countdown[next];
        size[node] += size[next];
      }
    }
  }
  
  public static int[] freedown;
  public static int[] maxdown;
  public static int[] md1;
  public static int[] mxid1;
  public static int[] md2;
  public static void dfs1() {
    for(int i = n-1; i >= 0; i--) {
      int node = queue[i];
      int res = good[node] ? 1 : 0;
      int mx1 = 0, mx2 = 0, id1 = 0;
      int add = 0;
      for (int next : graph[node]) {
        if (next == pp[node]) continue;
        if (countdown[next] == size[next]) add += size[next];
        else if (good[next]) {
          if (maxdown[next] > mx1) {
            mx2 = mx1;
            id1 = next;
            mx1 = maxdown[next];
          } else if (maxdown[next] > mx2) {
            mx2 = maxdown[next];
          }
        }
      }
      freedown[node] = add+res;
      md1[node] = mx1;
      md2[node] = mx2;
      mxid1[node] = id1;
      maxdown[node] = good[node] ? freedown[node] + mx1 : 0;
    }
  }
  
  public static int[] maxup;
  public static boolean[] freeup;
  public static void dfs2() {
    for (int i = 1; i < n; i++) {
      int node = queue[i];
      int par = pp[node];
      int inpar = t - countdown[node];
      int szpar = n - size[node];
      int sub = countdown[node] == size[node] ? size[node] : 0;
      if (!good[node]) {
        maxup[node] = 0;
      } else if (inpar == szpar) {
        maxup[node] = szpar;
        freeup[node] = true;
      } else if (good[par]) {
        int add = mxid1[par] == node ? md2[par] : md1[par];
        int res = 0;
        if (freeup[par]) res = add + maxup[par] + freedown[par] - sub;
        else res = Math.max(maxup[par], add) + freedown[par] - sub;
        maxup[node] = res;
      } else {
        maxup[node] = 0;
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