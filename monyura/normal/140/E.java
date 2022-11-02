
import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;


public class Main {

    static int P;
    static int m;
    static BigInteger Prev;
    static long C[]=new long[6000];
    static void init()
    {
        Prev=BigInteger.ONE;
        C[0]=1;
        for (int i=1;i<=5000;i++)
        {
            Prev=Prev.multiply(BigInteger.valueOf(m-i+1)).divide(BigInteger.valueOf(i));
            C[i]=Prev.mod(BigInteger.valueOf(P)).longValue();
        }
    }

    static long getC(int k)
    {
        if (k>m) return 0;
        return C[k];
    }
     public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        m=sc.nextInt();
        P=sc.nextInt();
        init();
        int L[]=new int[n];
        for (int i=0;i<n;i++)
            L[i]=sc.nextInt();
        int K[][]=new int[5002][5002];
        K[1][1]=1;
        for (int i=2;i<=5000;i++)
            for (int j=1;j<=5000;j++)
                K[i][j]=(int)(((long)(K[i-1][j-1])*j+(long)(K[i-1][j])*(j-1))%P);
        long D[]=new long[5002];
        for (int i=0;i<5002;i++)
            D[i]=0;
        long sum=1,tmp;
        for (int i=0;i<n;i++)
        {
            long curr=0;
            for (int j=1;j<=L[i];j++)
            {
                tmp=(sum*K[L[i]][j]%P)*getC(j)%P;
                if (i!=0 && j<=L[i-1])
                    tmp=(tmp+P-(D[j]*K[L[i]][j]%P))%P;
                D[j]=tmp;
                curr=curr+D[j];
                if (curr>=P)
                    curr-=P;
            }
            sum=curr;
        }
        long res=0;
        for (int i=1;i<=L[n-1];i++)
            res=(res+D[i])%P;
        System.out.println(res);
    }

}