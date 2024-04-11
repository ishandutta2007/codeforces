import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Sumdif {
    
    static BigInteger a;
    
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        BigInteger k,l,a;
        int ans=1;
        k=in.nextBigInteger();
        l=in.nextBigInteger();
        a=k;
        while (a.compareTo(l)==-1) 
        {
            ans++;
            a=a.multiply(k);
        }
        if (a.compareTo(l)==0) 
        {
            out.println("YES");
            out.print(ans-1);
        }
        else
            out.print("NO");
        out.flush();

     }
}