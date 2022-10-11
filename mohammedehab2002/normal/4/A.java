import java.util.Scanner;
public class learn {
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        if (a%2==1 || a==2)
        System.out.println("NO");
        else
        System.out.println("YES");
    }
}