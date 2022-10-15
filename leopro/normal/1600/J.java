import java.util.*;

import java.io.*;
public class A13
{
    static int c=0;
    public static void dfs(int adj[][],int v[],int src)
    {
        c++;
        v[src]=1;
        int max=0;
        for(Integer a:adj[src])
        {
            if(a != -1 && v[a]==0)
            {
                dfs(adj,v,a);
            }
        }

    }
    public static boolean check(int i,int j,int n,int m)
    {
        if(i<n && j<m && i>=0 && j>=0)
        {
            return true;
        }
        return false;
    }
    public static void addEdges(int adj[][],int i,int j, char ch[],int n,int m)
    {
        int src=i*m+j;
        for(int index = 0; index < ch.length; index++)
        {
            char ch1 = ch[index];
            if(ch1=='U')
            {
                if(check(i-1,j,n,m))
                {
                    int dst=(i-1)*m+j;
                    adj[src][index] = dst;

                }
            }
            else
            if(ch1=='R')
            {
                if(check(i,j+1,n,m))
                {
                    int dst=(i)*m+(j+1);
                    adj[src][index] = dst;

                }
            }
            else
            if(ch1=='L')
            {
                if(check(i,j-1,n,m))
                {
                    int dst=(i)*m+(j-1);
                    adj[src][index] = dst;

                }
            }
            else
            if(ch1=='D')
            {
                if(check(i+1,j,n,m))
                {
                    int dst=(i+1)*m+j;
                    adj[src][index] = dst;

                }
            }

        }
    }
    public static void process()throws IOException
    {
        int n=I();
        int m=I();
        int a[][]=new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=I();
            }
        }
        int adj[][] = new int[n * m][4];
        for (int i = 0; i < n * m; i++) {
            for (int x = 0; x < 4; x++) {
                adj[i][x] = -1; // nothing
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mask=a[i][j];
                char ch[]= {'L','D','R','U'};
                char cp[] = new char[4];
                for(int k=0;k<4;k++)
                {
                    if((mask&(1<<k))==0)
                    {
                        cp[k] = ch[k];
                    } else {
                        cp[k] = '\0'; // nothing
                    }
                }
                addEdges(adj,i,j,cp,n,m);
            }
        }

        int v[]=new int[n*m];
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for(int i=0;i<n*m;i++)
        {

            if(v[i]==0)
            {
                c=0;
                dfs(adj,v,i);
                arr.add(c);
            }
        }
        Collections.sort(arr);
        Collections.reverse(arr);
        for(int i=0;i<arr.size();i++)
        {
            out.print(arr.get(i)+" ");
        }
        pn("");



    }
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static void sort(char[] a) {
        int n = a.length;
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int oi = r.nextInt(n);
            char temp = a[i];
            a[i] = a[oi];
            a[oi] = temp;
        }
        Arrays.sort(a);
    }
    static FastReader sc = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);
    static void pn(Object o){out.println(o);out.flush();}
    static void p(Object o){out.print(o);out.flush();}
    static void pni(Object o){out.println(o);System.out.flush();}
    static int I() throws IOException{return sc.nextInt();}
    static long L() throws IOException{return sc.nextLong();}
    static double D() throws IOException{return sc.nextDouble();}
    static String S() throws IOException{return sc.next();}
    static char C() throws IOException{return sc.next().charAt(0);}
    static int[] Ai(int n) throws IOException{int[] arr = new int[n];for (int i = 0; i < n; i++)arr[i] = I();return arr;}
    static String[] As(int n) throws IOException{String s[] = new String[n];for (int i = 0; i < n; i++)s[i] = S();return s;}
    static long[] Al(int n) throws IOException {long[] arr = new long[n];for (int i = 0; i < n; i++)arr[i] = L();return arr;}
    static void dyn(int dp[][],int n,int m,int z)throws IOException {for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ dp[i][j]=z;}} }

//	*--------------------------------------------------------------------------------------------------------------------------------*//

    public static void main(String[] args)throws IOException{try{boolean oj=true;if(oj==true)
    {PrintWriter out=new PrintWriter(System.out);}
    else
    {out=new PrintWriter("output.txt");}

        {
            process();
        }out.flush();out.close();}catch(Exception e){return;}}}
//*-----------------------------------------------------------------------------------------------------------------------------------*//