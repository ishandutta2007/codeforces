import java.util.*;

public class test
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int tc = 1; tc <= TC; tc++)
        {
            String s = sc.next();
            for (int i = 0; i < s.length(); i += 2)
            {
                System.out.print(s.charAt(i));
            }
            System.out.println(s.charAt(s.length() - 1));
        }
    }
}