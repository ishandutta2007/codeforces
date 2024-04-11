import java.util.*;

public class test
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int tc = 1; tc <= TC; tc++)
        {
            int n = sc.nextInt();
            for (int j = 2; ; j++)
            {
                int co = (1 << j) - 1;
                if (n % co == 0)
                {
                    System.out.println(n / co);
                    break;
                }
            }
        }
    }
}