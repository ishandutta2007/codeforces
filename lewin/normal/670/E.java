import java.io.*;
import java.util.*;

public class correctbracketseq {
  private static InputReader in;
  private static PrintWriter out;
  public static char[] s;
  public static int didx;
  public static ArrayList<Integer>[] children;
  public static int[] par;
  public static int[] prev, next;
  public static boolean[] del;
  public static int[] fc, lc;
  public static int cpos, cc;
  public static int which;
  public static int dfs(int pos, int p) {
    int cnode = didx; didx++;
    par[cnode] = p;
    if (p != -1) {
      if (children[p].size() > 0) {
        int pc = children[p].get(children[p].size()-1);
        prev[cnode] = pc;
        next[pc] = cnode;
      }
      if (children[p].size() == 0) fc[p] = cnode;
      lc[p] = cnode;
      children[p].add(cnode);
    }
    if (pos == cc) {
      cpos = cnode;
      which = 0;
    }
    int cur = pos+1;
    while (s[cur] != ')') {
      cur = dfs(cur, cnode);
    }
    if (cur == cc) {
      cpos = cnode;
      which = 1;
    }
    return cur+1;
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), m = in.nextInt();
    cc = in.nextInt()-1;
    s = in.next().toCharArray();
    children = new ArrayList[n+1];
    par = new int[n+1];
    prev = new int[n+1];
    next = new int[n+1];
    fc = new int[n+1];
    lc = new int[n+1];
    Arrays.fill(fc, -1);
    Arrays.fill(lc, -1);
    Arrays.fill(prev, -1);
    Arrays.fill(next, -1);
    for (int i = 0; i <= n; i++) children[i] = new ArrayList<>();
    int cur = 0;
    didx = 1;
    while (cur < n) {
      cur = dfs(cur, 0);
    }
    del = new boolean[n+1];
    char[] cmd = in.next().toCharArray();
    for (char c : cmd) {
      switch(c) {
        case 'R':
          if (which == 0) {
            if (fc[cpos] == -1) which = 1;
            else {
              cpos = fc[cpos];
            }
          } else {
            if (next[cpos] != -1) {
              cpos = next[cpos];
              which = 0;
            } else {
              cpos = par[cpos];
            }
          }
          break;
        case 'L':
          if (which == 0) {
            if (prev[cpos] != -1) {
              cpos = prev[cpos];
              which = 1;
            } else {
              cpos = par[cpos];
            }
          } else {
            if (lc[cpos] == -1) which = 0;
            else {
              cpos = lc[cpos];
            }
          }
          break;
        case 'D':
          del[cpos] = true;
          int nn = next[cpos];
          int pp = prev[cpos];
          if (nn != -1) prev[nn] = pp;
          if (pp != -1) next[pp] = nn;
          int px = par[cpos];
          if (fc[px] == cpos) fc[px] = nn;
          if (lc[px] == cpos) lc[px] = pp;
          if (nn != -1) {
            cpos = nn;
            which = 0;
          } else {
            if (par[cpos] == 0) {
              cpos = pp;
              which = 1;
            } else {
              cpos = par[cpos];
              which = 1;
            }
          }
      }
    }
    
    for (int next : children[0]) if (!del[next]) print(next);
    out.println();
    out.close();
    System.exit(0);
  }

  public static void print(int root) {
    out.print("(");
    for (int next : children[root]) if (!del[next]) print(next);
    out.print(")");
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