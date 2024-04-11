import java.io.*;
import java.util.*;

public class worldtour {
  private static InputReader in;
  private static PrintWriter out;
  
  public static ArrayList<Integer>[] fgraph;
  public static ArrayList<Integer>[] bgraph;
  public static int n,m;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    n = in.nextInt();
    m = in.nextInt();
    fgraph = new ArrayList[n];
    bgraph = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      fgraph[i] = new ArrayList<>();
      bgraph[i] = new ArrayList<>();
    }
    for (int i = 0; i < m; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      fgraph[a].add(b);
      bgraph[b].add(a);
    }
    
    int[] fmax = new int[n];
    int[] fmax2 = new int[n];
    int[] fmax3 = new int[n];
    int[] fwhich = new int[n];
    int[] fwhich2 = new int[n];
    int[] fwhich3 = new int[n];
    int[] queue = new int[n];
    int[][] dist = new int[n][n];
    for (int i = 0; i < n; i++) {
      int front = 0, back = 0;
      Arrays.fill(dist[i], 1 << 29);
      queue[back++] = i;
      dist[i][i] = 0;
      while(front < back) {
        int cur = queue[front++];
        for (int next : fgraph[cur]) {
          if (dist[i][next] > dist[i][cur] + 1) {
            dist[i][next] = dist[i][cur] + 1;
            queue[back++] = next;
          }
        }
      }
      fmax[i] = -1;
      fmax2[i] = -1;
      fmax3[i] = -1;
      for (int j = 0; j < n; j++) {
        if (dist[i][j] == 1 << 29) continue;
        if (dist[i][j] > fmax[i]) {
          fmax3[i] = fmax2[i];
          fwhich3[i] = fwhich2[i];
          fmax2[i] = fmax[i];
          fwhich2[i] = fwhich[i];
          fmax[i] = dist[i][j];
          fwhich[i] = j;
        } else if (dist[i][j] > fmax2[i]) {
          fmax3[i] = fmax2[i];
          fwhich3[i] = fwhich2[i];
          fmax2[i] = dist[i][j];
          fwhich2[i] = j;
        } else if (dist[i][j] > fmax3[i]) {
          fmax3[i] = dist[i][j];
          fwhich3[i] = j;
        }
      }
    }
    
    int[] bdist = new int[n];
    int[] bmax = new int[n];
    int[] bwhich = new int[n];
    int[] bmax2 = new int[n];
    int[] bwhich2 = new int[n];
    int[] bmax3 = new int[n];
    int[] bwhich3 = new int[n];

    for (int i = 0; i < n; i++) {
      int front = 0, back = 0;
      Arrays.fill(bdist, 1 << 29);
      queue[back++] = i;
      bdist[i] = 0;
      bmax[i] = -1;
      while(front < back) {
        int cur = queue[front++];
        for (int next : bgraph[cur]) {
          if (bdist[next] > bdist[cur] + 1) {
            bdist[next] = bdist[cur] + 1;
            queue[back++] = next;
          }
        }
      }
      bmax[i] = -1;
      bmax2[i] = -1;
      for (int j = 0; j < n; j++) {
        if (bdist[j] == 1 << 29) continue;
        if (bdist[j] > bmax[i]) {
          bmax3[i] = bmax2[i];
          bwhich3[i] = bwhich2[i];
          bmax2[i] = bmax[i];
          bwhich2[i] = bwhich[i];
          bmax[i] = bdist[j];
          bwhich[i] = j;
        } else if (bdist[j] > bmax2[i]) {
          bmax3[i] = bmax2[i];
          bwhich3[i] = bwhich2[i];
          bmax2[i] = bdist[j];
          bwhich2[i] = j;
        } else if (bdist[j] > bmax3[i]) {
          bmax3[i] = bdist[j];
          bwhich3[i] = j;
        }
      }
    }
    
    int best = 0;
    int b1 = 0, b2 = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j || dist[i][j] == 1 << 29) continue;
        int cur, x[];
        cur = bmax[i] + dist[i][j] + fmax[j];
        x = new int[]{i,j,bwhich[i],fwhich[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich[i];
          c2 = fwhich[j];
        }
        cur = bmax2[i] + dist[i][j] + fmax[j];
        x = new int[]{i,j,bwhich2[i],fwhich[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich2[i];
          c2 = fwhich[j];
        }
        cur = bmax3[i] + dist[i][j] + fmax[j];
        x = new int[]{i,j,bwhich3[i],fwhich[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich3[i];
          c2 = fwhich[j];
        }
        
        cur = bmax[i] + dist[i][j] + fmax2[j];
        x = new int[]{i,j,bwhich[i],fwhich2[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich[i];
          c2 = fwhich2[j];
        }
        cur = bmax2[i] + dist[i][j] + fmax2[j];
        x = new int[]{i,j,bwhich2[i],fwhich2[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich2[i];
          c2 = fwhich2[j];
        }
        cur = bmax3[i] + dist[i][j] + fmax2[j];
        x = new int[]{i,j,bwhich3[i],fwhich2[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich3[i];
          c2 = fwhich2[j];
        }

        cur = bmax[i] + dist[i][j] + fmax3[j];
        x = new int[]{i,j,bwhich[i],fwhich3[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich[i];
          c2 = fwhich3[j];
        }
        cur = bmax2[i] + dist[i][j] + fmax3[j];
        x = new int[]{i,j,bwhich2[i],fwhich3[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich2[i];
          c2 = fwhich3[j];
        }
        cur = bmax3[i] + dist[i][j] + fmax3[j];
        x = new int[]{i,j,bwhich3[i],fwhich3[j]};
        if (distinct(x) && cur > best) {
          best = cur;
          b1 = i;
          b2 = j;
          c1 = bwhich3[i];
          c2 = fwhich3[j];
        }
      }
    }
    
    out.printf("%d %d %d %d\n", c1+1, b1+1, b2+1, c2+1);
    
    out.close();
    System.exit(0);
  }
  
  public static boolean distinct(int[] x) {
    for (int i = 0; i < x.length; i++) {
      for (int j = i+1; j < x.length; j++) {
        if (x[i] == x[j]) return false;
      }
    }
    return true;
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