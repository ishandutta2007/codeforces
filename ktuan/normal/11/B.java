import java.util.*;
import java.io.*;
public class B2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long t = 0;
        if(n == 0) {
            System.out.println(0);
            return;
        }
        for(int i=1;;++i) {
            t += i;
            if(Math.abs(t) >= Math.abs(n) && (t+n) % 2 == 0) {
                System.out.println(i);
                break;
            }
        }
    }
}