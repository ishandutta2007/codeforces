import java.util.Scanner;
public class learn {
    public static void main(String[] args)
    {
        Scanner a=new Scanner(System.in);
        long l=a.nextLong(),w=a.nextLong(),s=a.nextLong();
        long m1=l/s;
        if (l%s!=0)
        m1++;
        long m2=w/s;
        if (w%s!=0)
        m2++;
        System.out.print(m1*m2);
    }
}