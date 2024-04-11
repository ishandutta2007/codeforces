import java.io.*;
import java.util.*;

public class Main {
    private static BufferedReader in;
    private static PrintWriter out;
    
    static class Triplet implements Comparable <Triplet> {
      public int  a, b, c;
      
      public Triplet (int _a, int _b, int _c) {
          a = _a;
          b = _b;
          c = _c;
      }
      
      public int compareTo (Triplet other) {
          return (a == other.a) ? b - other.b : a - other.a;
      }
  }
    
    private static int [] suffix_array (char [] s) {
      int n = s.length;
      int [] id = new int [n];
      for (int i = 0; i < n; i++)
          id[i] = s[i] - 'A';
      
      for (int k = 1; k <= n; k <<= 1) {
          Triplet [] elem = new Triplet [n];
          for (int i = 0; i < n; i++)
              elem[i] = new Triplet (id[i], (i + k < n) ? id[i + k] : -1, i);
          Arrays.sort (elem);
          int cur = -1;
          for (int i = 0; i < n; i++) {
              if (i == 0
                      || !(elem[i].a == elem[i - 1].a && elem[i].b == elem[i - 1].b))
                  cur++;
              id[elem[i].c] = cur;
          }
      }
      
      int[] inv = new int[n];
      for (int i = 0; i < n; i++)
        inv[id[i]] = i;
      return inv;
  }
   
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        char[] let = in.readLine().toCharArray();
        int N = let.length;
        int[] ret = suffix_array(let);
        int add = 0, front = 0, back = N - 1;
        int[] count = new int[N];
        for (int i = 0; i < N; i++) {
          while (ret[front] + add >= N || let[ret[front] + add] != let[add])
            front++;
          while (ret[back] + add >= N || let[ret[back] + add] != let[add])
            back--;
          count[i] = back - front + 1;
          add++;
        }
        int[] z = new int[N];
        int L = 0, R = 0;
        for (int i = 1; i < N; i++) {
          if (i > R) {
            L = R = i;
            while (R < N && let[R-L] == let[R]) R++;
            z[i] = R-L; R--;
          } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
              L = i;
              while (R < N && let[R-L] == let[R]) R++;
              z[i] = R-L; R--;
            }
          }
        }
        z[0] = N;
        int cnt = 0;
        for (int i = 0; i < N; i++) if (z[i] == N - i) cnt++;
        out.println (cnt);
        for (int i = N - 1; i >= 0; i--) {
          if (z[i] == N - i) {
            out.println((N - i) + " " + count[N - i - 1]);
          }
        }
        
        out.close();
        System.exit(0);
    }
}