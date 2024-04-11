import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class interestingSequence {
    public static final int Maxm = 601;
    public static void main(String Args[]) throws IOException {
        BigInteger pow12[] = new BigInteger[Maxm];
        pow12[0] = BigInteger.valueOf(1);
        for (int i = 1; i < Maxm; i++) pow12[i] = pow12[i-1].multiply(BigInteger.valueOf(12));
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter fout = new PrintWriter(new OutputStreamWriter(System.out));
        String s = fin.readLine(); s.trim();
        BigInteger A = new BigInteger(s);
        ArrayList <Integer> K = new ArrayList <Integer>();
        for (int i = 0; i < Maxm && K.isEmpty(); i++)
            for (int j = 0; j <= i/2 && K.isEmpty(); j++)
                if (pow12[j].add(pow12[i-j]).equals(A)) K.add(i);
        if (K.isEmpty()) fout.println("NO");
        else {
            fout.println("YES");
            fout.println("1");
            fout.println(K.get(0)+1);
            fout.println(K.get(0)/2);
            for (int i = K.get(0)/2; i >= 0; i--)
                if (!pow12[i].add(pow12[K.get(0)-i]).equals(A))
                    fout.println(pow12[i].add(pow12[K.get(0)-i]));
        }
        fout.flush();
    }
}