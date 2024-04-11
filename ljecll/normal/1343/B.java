import java.util.*;

public class test
{
    public static int[] solve(int n)
    {
        int[] res = new int[n];
        for (int i = 0; i < n / 2; i++)
        {
            res[i] = (2 * i + 2);
            res[i + (n / 2)] = (2 * i + 1);
        }
        res[n - 1] = 0;
        for (int i = 0; i < n / 2; i++)
        {
            res[n - 1] += res[i];
        }
        for (int i = n / 2; i < n - 1; i++)
        {
            res[n - 1] -= res[i];
        }
        return res;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int tc = 1; tc <= TC; tc++)
        {
            int n = sc.nextInt();
            if (n % 4 != 0)
            {
                System.out.println("NO");
                continue;
            }
            System.out.println("YES");
            int[] res = solve(n);
            for (int i = 0; i < res.length; i++)
            {
                System.out.print(Integer.toString(res[i]) + ' ');
            }
            System.out.println();
        }
    }
}