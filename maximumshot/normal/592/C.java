import java.math.BigInteger;
import java.util.Scanner;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.IntStream;

public class Max {

    public long gcd(long x, long y) {
        return (x == 0?y : gcd(y % x, x));
    }

    public void show(long x, long y) {
        long g = gcd(x, y);
        System.out.println(x / g + "/" + y / g);
    }

    public void solve() {

        long t, w, b;
        Scanner in = new Scanner(System.in);

        t = in.nextLong();
        w = in.nextLong();
        b = in.nextLong();

        if(w > b) {
            // swap
            long tmp = w;
            w = b;
            b = tmp;
        }

        long g = gcd(w, b);

        if(w > t) {
            show(t, t);
        }else {

            BigInteger kmax = BigInteger.valueOf(t - w + 1).multiply(BigInteger.valueOf(g)).divide(BigInteger.valueOf(w).multiply(
                    BigInteger.valueOf(b)));

            long ans = kmax.longValue() * w + w - 1;

            if(kmax.add(BigInteger.ONE).multiply(BigInteger.valueOf(w)).multiply(BigInteger.valueOf(b)).compareTo(
                    BigInteger.valueOf(t).multiply(BigInteger.valueOf(g))
            ) > 0) {}
            else {
                ans += t - (kmax.longValue() + 1) * (b / g) * w + 1;
            }

            show(ans, t);
        }
    }

    public static void main(String[] args) {

        Max MAX = new Max();
        MAX.solve();

    }


}