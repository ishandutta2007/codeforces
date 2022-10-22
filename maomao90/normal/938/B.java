import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n + 5];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        int pos[] = new int[1000005];
        for (int i = 0; i < 1000005; i++) pos[i] = 0;
        for (int i = 0; i < n; i++) pos[a[i]] = 1;
        int ans = 0;
        for (int i = 0; i <= 500000; i++) {
            if (pos[i] == 1 || pos[1000000 - i + 1] == 1) ans = i - 1;
        }
        System.out.println(ans);
    }
}