
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;



public class Main
{

    static FastInputReader in ;
    static PrintWriter out;
    public static void main(String args[])
    {
      
        in = new FastInputReader(System.in);
        out = new PrintWriter(System.out);
        new Main().run();
        System.out.flush();
        out.flush();
    }

    public static BigInteger BI(long a)
    {
        return BigInteger.valueOf(a);
    }

    BigInteger sqroot(BigInteger a)
    {
        BigInteger l = BI(0), r = a, res = BI(-1);
        while (l.compareTo(r)<=0)
        {
            BigInteger c = l.add(r).divide(BI(2));
            if (c.multiply(c).compareTo(a)<=0)
            {
                res = c;
                l = c.add(BI(1));
            }
            else
            {
                r = c.subtract(BI(1));
            }
        }
        return res;

    }
    void run()
    {
        long n = in.nextLong();
        ArrayList<BigInteger> vec = new ArrayList();
        for (long b = 0,add = 1;b<=n;add<<=1)
        {
            BigInteger D = BI(2*b-1).multiply(BI(2*b-1)).add(BI(8*n));
            if (D.compareTo(BI(0))>=0)
            {
                BigInteger rt = sqroot(D);
                if (rt.multiply(rt).equals(D))
                {
                    BigInteger num = BI(-2*b+1).add(rt);
                    if (num.mod(BI(2)).equals(BI(0)) && num.compareTo(BI(0))>=0)
                    {
                        BigInteger a = num.divide(BI(2));
                        if (a.mod(BI(2)).equals(BI(1)))
                           vec.add(a.multiply(BI(add)));
                    }
                    num = BI(-2*b+1).subtract(rt);
                    if (num.mod(BI(2)).equals(BI(0)) && num.compareTo(BI(0))>=0)
                    {
                        BigInteger a = num.divide(BI(2));
                        if (a.mod(BI(2)).equals(BI(1)))
                           vec.add(a.multiply(BI(add)));
                    }
                }
            }
            b+=add;
        }
        Collections.sort(vec);
        if (vec.size()!=0)
        {
            for (int i=0;i<vec.size();i++)
                out.println(vec.get(i));
        }
        else
            out.println("-1");

    }
   
}



class FastInputReader
{
    BufferedReader br;
    StringTokenizer st = null;
    public FastInputReader(InputStream str)
    {
        br = new BufferedReader(new InputStreamReader(str));
    }

    private String getToken()
    {
        while (st ==null || !st.hasMoreTokens())
        try
        {
            st = new StringTokenizer(br.readLine());
        }
        catch (IOException exp)
        {
            throw new RuntimeException();
        }
        return st.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(getToken());
    }

    public long nextLong()
    {
        return Long.parseLong(getToken());
    }

    public double nextDouble()
    {
        return Double.parseDouble(getToken());
    }

    public String nextString()
    {
        return getToken();
    }
}
/*
 4 3 2
 1 2 10 O
 2 3 10 I
 1 3 20 O
1 3
 0 0
 */