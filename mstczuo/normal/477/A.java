import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        a = a.multiply(a.add(BigInteger.valueOf(1))).divide(BigInteger.valueOf(2)).multiply(b).add(a);
        b = b.multiply(b.subtract(BigInteger.valueOf(1))).divide(BigInteger.valueOf(2));
        BigInteger ans = a.multiply(b).remainder(BigInteger.valueOf(1000000007));
        System.out.println(ans);
    }
}