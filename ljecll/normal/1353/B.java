import java.util.*;

public class test
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int tc = 1; tc <= TC; tc++)
        {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] A = new int[n], B = new int[n];
            for (int i = 0; i < n; i++)
            {
                A[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++)
            {
                B[i] = sc.nextInt();
            }
            Arrays.sort(A);
            Arrays.sort(B);
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += A[i];
            }
            for (int i = 0; i < k; i++)
            {
                if (A[i] < B[n - 1 - i])
                {
                    sum += (B[n - 1 - i] - A[i]);
                }
            }
            System.out.println(sum);
        }
    }
}