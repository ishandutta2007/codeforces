import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        int now = n;
        boolean[] used = new boolean[n+1];
        for (int i = 1; i <= n; i++) {
            int x = stdin.nextInt();
            used[x] = true;
            if (x == now) {
                while (used[now]) {
                    System.out.format("%d ", now);
                    now--;
                }
            }
            System.out.println("");
        }
    }
}