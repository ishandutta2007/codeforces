import java.io.*;
import java.util.*;

public class Main {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    
    StringTokenizer st = new StringTokenizer (in.readLine());
    int N = Integer.parseInt(st.nextToken()), P = Integer.parseInt(st.nextToken());
    char maxlet = (char)('a' + P - 1);
    char[] c = in.readLine().toCharArray();
    int size = N - 1;
    outer : while (true) {
      c[size]++;
      int idx = size;
      while (idx >= 0 && c[idx] > maxlet) {
        if (idx > 0) c[idx - 1]++;
        idx--;
      }
      
      if (idx == -1) {
        out.println ("NO");
        out.close();
        System.exit(0);
      }
      size = idx;
      
      for (int j = idx - 1; j >= idx - 2 && j >= 0; j--) {
        if (c[idx] == c[j]) {
          continue outer;
        }
      }
      break;
    }
    
    boolean[] takenLetters = new boolean[P];
    for (int j = size; j >= size - 1 && j >= 0; j--)
      takenLetters[c[j] - 'a'] = true;
    
    for (int j = size + 1; j < N; j++) {
      char q = 'a';
      while (q <= maxlet && takenLetters[q - 'a']) q++;
      if (q > maxlet) {
        out.println ("NO");
        out.close();
        System.exit(0);
      }
      c[j] = q;
      takenLetters[q - 'a'] = true;
      if (j - 2 >= 0) takenLetters[c[j - 2] - 'a'] = false;
    }
    
    out.println (new String(c));
    out.close();
    System.exit(0);
  }
}