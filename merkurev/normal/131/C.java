import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A
{
    static BigInteger c(BigInteger a,BigInteger b)
    {
        BigInteger  r=BigInteger.valueOf(1);
        for (BigInteger i=(a.subtract(b)).add(BigInteger.valueOf(1));i.compareTo(a)<=0;i=i.add(BigInteger.valueOf(1)))
            r=r.multiply(i);
        for (BigInteger i=BigInteger.valueOf(2);i.compareTo(b)<=0;i=i.add(BigInteger.valueOf(1)))
            r=r.divide(i);
        return r;
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
    int n,m,t;
    BigInteger r=BigInteger.valueOf(0);
    //cin>>n>>m>>t;
    n=in.nextInt();
    m=in.nextInt();
    t=in.nextInt();
    for (int i=1;i<=t-4;i++)
    {

        r=r.add(c(BigInteger.valueOf(m),BigInteger.valueOf(i)).multiply(c(BigInteger.valueOf(n),BigInteger.valueOf(t-i))));
    }

    
    out.print(r);
    out.flush();
    }

}