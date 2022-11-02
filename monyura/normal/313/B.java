
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
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


    void run()
    {
        String s = in.nextString();
        int[] sum = new int[s.length()];
        for (int i=0;i<s.length()-1;i++)
            sum[i]= (i==0? 0 :sum[i-1]) + (s.charAt(i)==s.charAt(i+1)?1:0);
        int q = in.nextInt();
        for (int i=0;i<q;i++)
        {
            int l = in.nextInt(), r = in.nextInt();
            --l;--r;
            int res = sum[r-1];
            if (l>0) res-=sum[l-1];
            out.println(res);
        }

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