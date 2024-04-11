import java.io.*;
import java.util.*;

public class Cupboards
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n;
        int[] l = new int[10000], r = new int[10000];
        n = in.nextInt();
        for (int i=0; i<n; i++)
        {
            l[i]=in.nextInt();
            r[i]=in.nextInt();
        }
        int x=0, y=0, m=0;
        for (int i=0; i<n; i++)
        {
            if (l[i]==0) x++;
            else y++;
        }
        m+=Math.min(x, y);
        x=0; y=0;
        for (int i=0; i<n; i++)
        {
            if (r[i]==0) x++;
            else y++;
        }
        m+=Math.min(x, y);
        System.out.println(m);
    }
}