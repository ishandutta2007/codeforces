import java.util.*;
 
 
public class multtable {
 
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        long k = in.nextLong();

        long l = 1, mid;
        long r = (long)n * (long)m;
        long res = -1;

        while(l <= r){
            mid = (l+r)/2;
            long var = 0;
            for(long i = 1;i <= n;i++)
                var += Math.min(m,(mid-1)/i);
 
            if(var >= k)
                r = mid-1;
            else{
                res = mid;
                l = mid+1;
            }
        }

        System.out.println(res);
    }
 
}