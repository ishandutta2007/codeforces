import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void print(Object x) {
        System.out.println(x + "");
    }

    public static String unformat(long x) {
        long d = x % 256;
        long c = (x / 256) % 256;
        long b = (x / (256*256)) % (256);
        long a = (x / (256*256*256)) % 256;
        return a + "." + b + "." + c + "." + d;
    }

    public static void solve(int k, ArrayList<Long> addresses) {
        for (int mask = 31; mask > 0; mask--) {
            int mod = (int) Math.pow(2, mask);
            Set<Long> networks = new HashSet<Long>();
            for (long address : addresses) {
                networks.add(address / mod);
            }
            //print(networks.size() + " with mask " + mask);
            if (networks.size() == k) {
                long newMask = 0;
                for (int i = 31; i >= mask; i--) {
                    newMask += (long) Math.pow(2, i);
                }
                print(unformat(newMask));
                return;
            }
        }
        print("-1");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useDelimiter("\\.|\\s+");
        int n = in.nextInt();
        int k = in.nextInt();

        ArrayList<Long> addresses = new ArrayList<Long>();
        for (int i = 0; i < n; i++) {
            long a = in.nextInt();
            long b = in.nextInt();
            long c = in.nextInt();
            long d = in.nextInt();
            addresses.add(256*256*256*a + 256*256*b + 256*c + d);
        }
        solve(k, addresses);
    }
}