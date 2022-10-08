import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    int[] a, b;
    int na, nb;
    long res = -1;
    
    void go(int pos, boolean gra, boolean lsb, boolean positive, long cur, long cur2) {
        if(pos == -1) {
            long tmp = cur;
            tmp *= cur2;
            res = Math.max(res, tmp);
            return;
        }
        boolean[] mark = new boolean[10];
        for(int ad=0;ad<10;++ad) if((ad >= a[pos] || gra) && (ad <= b[pos] || lsb)) mark[ad] = true;
        if(mark[4]) go( pos - 1, gra || 4 > a[pos], lsb || 4 < b[pos], true, cur * 10 + 4, cur2 * 10 + 5);
        if(mark[5]) go( pos - 1, gra || 5 > a[pos], lsb || 5 < b[pos], true, cur * 10 + 5, cur2 * 10 + 4);
        if(true) {
            int sm = 1000, la = -1;
            for(int ad=0;ad<10;++ad) if(mark[ad]) {
                sm = Math.min(sm, ad);
                la = ad;
            }
            if(sm < 10) go( pos - 1, gra || sm > a[pos], lsb || sm < b[pos], positive || sm > 0, cur * 10 + sm, cur2 * 10 + (positive || sm > 0 ? (9-sm) : 0));
            if(la >= 0) go( pos - 1, gra || la > a[pos], lsb || la < b[pos], positive || la > 0, cur * 10 + la, cur2 * 10 + (positive || la > 0 ? (9-la) : 0));
        }
    }
    
    public void run() {
        a = new int[11];
        b = new int[11];
        na = nb = 0;
        int x = nextInt();
        int y = nextInt();
        for(;x>0;x/=10) a[na++] = x % 10;
        for(;y>0;y/=10) b[nb++] = y % 10;
        go( Math.max(na, nb) - 1, false, false, false, 0, 0);
        System.out.println(res);
    }
    
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;
    
    String nextStr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }
    
    int nextInt() {
        return Integer.parseInt(nextStr());
    }
    
    long nextLong() {
        return Long.parseLong(nextStr());
    }
    
    double nextDouble() {
        return Double.parseDouble(nextStr());
    }
    
    public static void main(String[] args) {
        new BaiA().run();
    }
}