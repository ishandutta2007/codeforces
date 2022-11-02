
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
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

    
    void run()
    {
        int n = in.nextInt(),m = in.nextInt(),K = in.nextInt();
        int C[][]=new int[n][n];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                C[i][j]=Integer.MAX_VALUE;
        for (int i=0;i<m;i++)
        {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            --a;--b;
            for (int j=a;j<=b;j++)
                if (C[a][j]>c)
                    C[a][j]=c;
        }
        long D[][] = new long[n+1][n+1];
        long INF = (long)1e17;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                D[i][j]=INF;
        for (int i=0;i<n;i++)
        {
            D[i][0]=0;
            for (int j=1;j<=i+1;j++)
            {
                if (i!=0) D[i][j]=D[i-1][j];
                for (int k=1;k<=j;k++)
                    if (C[i-k+1][i]!=Integer.MAX_VALUE)
                    {
                        long prv = i-k<0? 0 : D[i-k][j-k];
                        long curr = prv + C[i-k+1][i];
                        if (curr<D[i][j])
                            D[i][j]=curr;
                    }
            }
        }
        long res = INF;
        for (int i=K;i<=n;i++)
            res=Math.min(res,D[n-1][i]);
        if (res==INF) res = -1;
        out.println(res);
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