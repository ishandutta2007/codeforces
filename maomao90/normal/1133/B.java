import java.util.Scanner;

public class E {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt();
        int d[] = new int[n + 5];
        for (int i = 0; i < n; i++) d[i] = in.nextInt() % k;
        int count[] = new int[k + 5];
        for (int i = 0; i < n; i++) count[d[i]]++;
        int ans = 0;
        for (int i = 1; i <= (k - 1) / 2; i++) {
            ans += Math.min(count[i], count[k - i]);
        }
        ans += count[0] / 2;
        if (k % 2 == 0) ans += count[k / 2] / 2;
        System.out.println(ans * 2);
    }
}