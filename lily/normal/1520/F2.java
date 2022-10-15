import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
    static final int N = 200055;
    static int n, t, tcnt;
    static int[] L = new int [N * 2], R = new int [N * 2], V = new int [N * 2];
    static int build(int l, int r) {
        int x = ++tcnt;
        if (l < r) {
            int mid = (l + r) / 2;
            L[x] = build(l, mid);
            R[x] = build(mid + 1, r);
        }
        V[x] = -1;
        return x;
    }

    static Scanner scanner;

    static int ask(int x, int l, int r) {
        if (V[x] == -1) {
            System.out.println("? " + l + " " + r);
            System.out.flush();
            V[x] = r - l + 1 - scanner.nextInt();
        }
        return V[x];
    }

    static int solve(int x, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int lv = ask(L[x], l, mid);
        if (lv < k) return solve(R[x], mid + 1, r, k - lv);
        else return solve(L[x], l, mid, k);
    }

    static void upd(int x, int l, int r, int ans) {
        V[x]--;
        if (l == r) return;
        int mid = (l + r) / 2;
        if (ans <= mid) upd(L[x], l, mid, ans);
        else upd(R[x], mid + 1, r, ans);
    }

    public static void main(String[] args) {
        scanner = new Scanner(new BufferedInputStream(System.in));
        n = scanner.nextInt();
        t = scanner.nextInt();
        build(1, n);
        while (t -- > 0) {
            int k = scanner.nextInt();
            int ans = solve(1, 1, n, k);
            upd(1, 1, n, ans);
            System.out.println("! " + ans);
            System.out.flush();
        }
    }
}