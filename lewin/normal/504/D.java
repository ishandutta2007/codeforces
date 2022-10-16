import java.io.*;
import java.math.*;
import java.util.*;

public class mishaxor {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    
    int idx = 0;
    BigInteger[] b1 = new BigInteger[N];
    BitSet[] b2 = new BitSet[N];
    for (int i = 0; i < N; i++) {
      BigInteger m = new BigInteger(in.next());
      BitSet r = new BitSet();
      for (int j = 0; j < idx; j++) {
        BigInteger x = m.xor(b1[j]);
        if (x.compareTo(m) < 0) {
          m = x;
          r.xor(b2[j]);
        }
      }
      if (m.compareTo(BigInteger.ZERO) == 0) {
        out.print(r.cardinality());
        for (int j = r.nextSetBit(0); j >= 0; j = r.nextSetBit(j+1))
          out.print(" "+j);
        out.println();
      } else {
        r.set(i);
        b1[idx] = m;
        b2[idx++] = r;
        out.println(0);
      }
    }
    out.close();
    System.exit(0);
  }
}