
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

    long getRes(int[][]M,int x,int y,int p)
    {
        if (p==0)
            return M[x][y];
        long s =0;
        int pos = 0,add = 1<<(p-1);
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                s+=getRes(M,x+i*add,y+j*add,p-1);
        return s+getMax(M,x,y,p);
    }

    int getMax(int[][]M,int x,int y,int p)
    {
        int mx = 0, n = 1<<p;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (M[i+x][j+y]>mx)
                    mx = M[i+x][j+y];
        return mx;
    }

    void run()
    {
        int n = in.nextInt();
        Integer []A = new Integer [n];
        for (int i=0;i<n;i++)
            A[i] = in.nextInt();
        if (n==1)
        {
            out.println(A[0]);
            return;
        }
        Arrays.sort(A,Collections.reverseOrder());
        int p = 0;
        while ((1<<(2*(p+1)))<=n)
            ++p;
        n=1<<p;
        int[][] M = new int[n][];
        for (int i=0;i<n;i++)
            M[i] = new int[n];
        int pos = 0;
        for (int t=1<<(p-1);t>=1;t>>=1)
            for (int i=0;i<n;i+=t)
                for (int j=0;j<n;j+=t)
                    if (M[i][j]==0)
                        M[i][j]=A[pos++];
        long ans = getRes(M,0,0,p);
        out.println(ans);

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