import java.io.*;
import java.util.*;

public class mikefriends {
  private static InputReader in;
  private static PrintWriter out;

  private static int[] radix_sort(int[] s, int[] pos) {
    int N = pos.length;
    int[] count = new int[Math.max(s.length, 27)];
    for (int i = 0; i < N; i++)
      count[s[pos[i]]]++;

    for (int j = 1; j < count.length; j++)
      count[j] += count[j - 1];
    for (int j = count.length - 1; j > 0; j--)
      count[j] = count[j - 1];
    count[0] = 0;

    // get new positions
    int[] nord = new int[N];
    for (int i = 0; i < N; i++)
      nord[count[s[pos[i]]]++] = pos[i];

    return nord;
  }

  private static int[] suffix_array(int[] s) {
    int N = s.length;

    int n1 = (N + 1) / 3, n2 = N / 3, n0 = (N + 2) / 3;

    if (N % 3 == 1)
      n1++;
    // pad S
    int[] ns = new int[N + 3];
    System.arraycopy(s, 0, ns, 0, s.length);

    int[] pos = new int[n1 + n2];
    int idx = 0;
    for (int i = 1; i < N; i += 3)
      pos[idx++] = i;
    if (N % 3 == 1)
      pos[idx++] = N;
    for (int i = 2; i < N; i += 3)
      pos[idx++] = i;

    int[] bmap = new int[N + 1];
    for (int i = 0; i < pos.length; i++)
      bmap[pos[i]] = i;

    int[] fmap = new int[n1 + n2];
    System.arraycopy(pos, 0, fmap, 0, n1 + n2);

    for (int i = 0; i < pos.length; pos[i++] += 2);
    pos = radix_sort(ns, pos);
    for (int i = 0; i < pos.length; pos[i++]--);
    pos = radix_sort(ns, pos);
    for (int i = 0; i < pos.length; pos[i++]--);
    pos = radix_sort(ns, pos);

    // now relabel strings
    int p0 = -1, p1 = -1, p2 = -1, cidx = 0;
    int[] rs = new int[n1 + n2];
    for (int i = 0; i < pos.length; i++) {
      if (ns[pos[i]] != p0 || ns[pos[i] + 1] != p1 || ns[pos[i] + 2] != p2) {
        p0 = ns[pos[i]];
        p1 = ns[pos[i] + 1];
        p2 = ns[pos[i] + 2];
        rs[bmap[pos[i]]] = cidx++;
      } else {
        rs[bmap[pos[i]]] = cidx - 1;
      }
    }

    int[] rSA = new int[n1 + n2];
    if (cidx == n1 + n2) {
      System.arraycopy(pos, 0, rSA, 0, n1 + n2);
    } else {
      int[] r = suffix_array(rs);
      for (int i = 0; i < rSA.length; i++)
        rSA[i] = fmap[r[i]];
    }

    int[] rank = new int[N + 3];
    for (int i = 0; i < rSA.length; i++)
      rank[rSA[i]] = i + 1;

    int[] pos0 = new int[n0];
    int qidx = 0;
    for (int i = 0; i < rSA.length; i++)
      if (rSA[i] % 3 == 1)
        pos0[qidx++] = rSA[i] - 1;
    pos0 = radix_sort(s, pos0);

    int[] ret = new int[N];
    int fidx = 0;
    for (int i = 0, j = 0; fidx < N;) {
      if (j == n1 + n2)
        ret[fidx++] = pos0[i++];
      else if (rSA[j] == N)
        j++;
      else if (i == n0)
        ret[fidx++] = rSA[j++];
      else {
        if (rSA[j] % 3 == 1) {
          if (ns[pos0[i]] < ns[rSA[j]]
              || (ns[pos0[i]] == ns[rSA[j]] && rank[pos0[i] + 1] < rank[rSA[j] + 1]))
            ret[fidx++] = pos0[i++];
          else
            ret[fidx++] = rSA[j++];
        } else {
          if (ns[pos0[i]] < ns[rSA[j]]
              || (ns[pos0[i]] == ns[rSA[j]] && ns[pos0[i] + 1] < ns[rSA[j] + 1])
              || (ns[pos0[i]] == ns[rSA[j]] && ns[pos0[i] + 1] == ns[rSA[j] + 1] && rank[pos0[i] + 2] < rank[rSA[j] + 2]))
            ret[fidx++] = pos0[i++];
          else
            ret[fidx++] = rSA[j++];
        }
      }
    }

    return ret;
  }


  private static int[] lcp(int[] A, int[] rank) {
    int n = rank.length;
    int[] order = new int[n];
    for (int i = 0; i < n; i++) order[rank[i]] = i;
    int[] height = new int[n];

    int h = 0;
    for (int i = 0; i < n; i++) {
      if (order[i] > 0) {
        int j = rank[order[i] - 1];
        while (i + h < n && j + h < n && A[i + h] == A[j + h])
          h++;
        height[order[i]-1] = h;
        if (h > 0)
          h--;
      }
    }

    return height;
  }
  
  static class Pair implements Comparable<Pair> {
    public int a, b;
    public Pair(int a, int b) {
      this.a = a;
      this.b = b;
    }
    
    public int compareTo(Pair other) {
      return b - other.b;
    }
  }
  
  public static int[] seq;
  static class Query implements Comparable<Query> {
    public int from, to, id, sign;
    public int val;
    
    public Query(int from, int to, int val, int id, int sign) {
      this.from = from;
      this.to = to;
      this.val = val;
      this.id = id;
      this.sign = sign;
    }
    
    public int compareTo(Query other) {
      return val - other.val;
    }
  }
  public static int[] which;
  public static int[] all;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), Q = in.nextInt();
    char[][] ss = new char[N][];
    int[] st = new int[N], en = new int[N];
    int total = 0;
    for (int i = 0; i < N; i++) {
      ss[i] = in.next().toCharArray();
      st[i] = total;
      total += ss[i].length;
      en[i] = total;
      total++;
    }
    
    all = new int[total];
    which = new int[total];
    int idx = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < ss[i].length; j++) {
        all[idx] = ss[i][j] - 'a' + 1;
        which[idx++] = i;
      }
      all[idx] = 0;
      which[idx++] = N;
    }
    
    int[] sa = suffix_array(all);
    seq = new int[total];
    for (int i = 0; i < total; i++) {
      seq[i] = which[sa[i]]; 
    }
    int[] p = new int[total];
    for (int i = 0; i < total; i++) p[sa[i]] = i;
    int[] lcp = lcp(all, sa);
    int[][] minR = new int[18][total];
    for (int i = 0; i < total; i++) minR[0][i] = lcp[i];
    for (int i = 1; i < 18; i++) {
      for (int j = 0; j+(1<<(i-1)) < total; j++) {
        minR[i][j] = Math.min(minR[i-1][j],minR[i-1][j+(1<<(i-1))]);
      }
    }
    int[][] minL = new int[18][total];
    for (int i = 0; i < total; i++) minL[0][i] = lcp[i];
    for (int i = 1; i < 18; i++) {
      for (int j = (1<<(i-1)); j < total; j++) {
        minL[i][j] = Math.min(minL[i-1][j],minL[i-1][j-(1<<(i-1))]);
      }
    }
    
    int[] l = new int[N];
    int[] r = new int[N];
    for (int i = 0; i < N; i++) {
      int pos = p[st[i]];
      int g = ss[i].length;
      int cur = pos-1;
      for (int k = 17; k >= 0; k--) {
        if (minL[k][cur] >= g) {
          cur -= (1 << k);
        }
      }
      l[i] = cur+1;
      
      cur = pos;
      for (int k = 17; k >= 0; k--) {
        if (minR[k][cur] >= g) {
          cur += (1 << k);
        }
      }
      r[i] = cur;
    }
    
    StringBuffer buff = new StringBuffer();
    int[] res = new int[Q];
    Query[] qs = new Query[2*Q];
    for (int i = 0; i < Q; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1, k = in.nextInt()-1;
      qs[2*i+0] = new Query(l[k], r[k]+1, b, i, 1);
      qs[2*i+1] = new Query(l[k], r[k]+1, a-1, i, -1);
    }
    Arrays.sort(qs);
    Pair[] pp = new Pair[total];
    for (int i = 0; i < total; i++) {
      pp[i] = new Pair(i+1, seq[i]);
    }
    Arrays.sort(pp);
    int[] tree = new int[total+1];
    int last = 0;
    for (int i = 0; i < qs.length; i++) {
      while (last < total && pp[last].b <= qs[i].val){
        for (int id = pp[last].a; id < tree.length; id += (id & -id)) tree[id]++;
        last++;
      }
      int sum = 0;
      for (int id = qs[i].to; id > 0; id -= (id & -id)) sum += tree[id];
      for (int id = qs[i].from; id > 0; id -= (id & -id)) sum -= tree[id];
      res[qs[i].id] += qs[i].sign * sum;
    }
    for (int i = 0; i < Q; i++) buff.append(res[i]+"\n");
    out.print(buff.toString());
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