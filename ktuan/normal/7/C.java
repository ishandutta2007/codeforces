import java.util.*;

public class B3 {
    
    static long gcd(long a, long b) {
        if(a == 0) return b;
        else return gcd( b % a, a);
    }
    
    static long[] exgcd(long a, long b) {
        if(a == 0) {
            return new long[]{0,1};
        }
        else {
            long r = b % a;
            long t = b / a;
            long[] l = exgcd( r, a);
            return new long[]{l[1] - l[0] * t, l[0]};
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        long uc = gcd(Math.abs(A), Math.abs(B));
        if(C % uc != 0) {
            System.out.println(-1);
        }
        else {
            long[] kq = exgcd(Math.abs(A) / uc, Math.abs(B) / uc);
            kq[0] *= C / uc;
            kq[1] *= C / uc;
            boolean ok = true;
            for(int d=-1;d<=1;d+=2)
                for(int d2=-1;d2<=1;d2+=2)
                    if(A * d * kq[0] + B * d2 * kq[1] + C == 0) {
                        if(ok) {
                            System.out.println(kq[0] * d + " " + kq[1] * d2);
                            ok = false;
                        }
                    }
        }
    }
}