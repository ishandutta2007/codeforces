import java.io.*;
import java.util.*;

public class foxdinner {
  private static InputReader in;
  private static PrintWriter out;
  
  public static boolean[] prime, matched, mat[];
  public static int N, arr[], next[], prev[];

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    if (N%2 == 1) {
      out.println("Impossible");
      out.close();
      System.exit(0);
    }
    int c = 0;
    arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = in.nextInt();
      if (arr[i]%2 == 0) c++;
      else c--;
    }
    if (c != 0) {
      out.println("Impossible");
      out.close();
      System.exit(0);
    }
    prime = new boolean[50000];
    Arrays.fill(prime, true);
    prime[0] = false; prime[1] = false;
    for (int i = 4; i < prime.length; i += 2) prime[i] = false;
    for (int i = 3; i < prime.length; i += 2) {
      if (prime[i]) {
        for (int j = i+i; j < prime.length; j += i)
          prime[j] = false;
      }
    }
    
    mat = new boolean[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        mat[i][j] = prime[arr[i] + arr[j]];
      }
    }
    
    next = new int[N];
    prev = new int[N];
    matched = new boolean[N];
    Arrays.fill(next, -1);
    Arrays.fill(prev, -1);
    int m = 0;
    for (int i = 0; i < N; i++) {
      vis = new boolean[N];
      if (dfs(i)) m++;
    }
    if (m != N) out.println("Impossible");
    else {
      ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
      boolean[] vis = new boolean[N];
      for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        int q = i;
        ArrayList<Integer> add = new ArrayList<Integer>();
        do {
          vis[q] = true;
          add.add(q+1);
          q = next[q];
        } while (q != i);
        ans.add(add);
      }
      out.println(ans.size());
      for (ArrayList<Integer> r : ans) {
        out.print(r.size());
        for (int k : r) out.print(" "+k);
        out.println();
      }
      out.close();
      System.exit(0);
    }
  }
  
  public static boolean[] vis;
  public static boolean dfs(int i) {
    vis[i] = true;
    for (int j = 0; j < N; j++) {
      if (prev[i] != j && mat[i][j]) {
        if (!matched[j]) {
          next[i] = j;
          prev[j] = i;
          matched[j] = true;
          return true;
        } else {
          if (!vis[prev[j]] && dfs(prev[j])) {
            next[i] = j;
            prev[j] = i;
            matched[j] = true;
            return true;
          }
        }
      }
    }
    return false;
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