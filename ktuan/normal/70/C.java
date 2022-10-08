import java.io.*;
import java.util.*;
import java.math.*;

public class BaiC implements Runnable {
    
    String rev(String s) {
        String r = "";
        for(int i=s.length()-1;i>=0;--i)
            r += s.charAt(i);
        return r;
    }
    
    int rev(int a) {
        return Integer.parseInt(rev("" + a));
    }
    
    boolean special(int i, int j) {
        String si = "" + i;
        String sj = "" + j;
        if(si.equals(rev(si)) && sj.equals(rev(sj))) return false;
        if(rev(si).equals(sj)) return false;
        return true;
    }
    
    final double eps = 1e-8;
    
    class Data implements Comparable<Data> {
        double d;
        
        public Data(double d) {
            this.d = d;
        }
        
        public int compareTo(Data z) {
            if(Math.abs(d - z.d) <= eps)
                return 0;
            if(d < z.d) return -1;
            else return 1;
        }
    }
    
    void add(TreeMap<Data, Integer> count, double d, int value) {
        Data key = new Data(d);
        count.put(key, value + get(count, key));
    }
    
    int get(TreeMap<Data, Integer> count, double d) {
        Data key = new Data(d);
        if(count.containsKey(key)) return count.get(key);
        else return 0;
    }
    int get(TreeMap<Data, Integer> count, Data key) {
        if(count.containsKey(key)) return count.get(key);
        else return 0;
    }
    
    public void run() {
        TreeMap<Data, Integer> count = new TreeMap<Data, Integer>();
        
        TreeMap<Data, Integer> cj = new TreeMap<Data, Integer>();
        
        int maxx = nextInt();
        int maxy = nextInt();
        int w = nextInt();
        
        double[] val = new double[Math.max(maxx, maxy) + 10];
        for(int i=1;i<=Math.max(maxx,maxy);++i) {
            int t = rev(i);
            val[i] = i * 1.0 / t;
        }
        
        for(int i=1;i<=maxx;++i) {
            add(count, val[i], 1);
        }
        
        int sj = 1;
        int z = 0;
        
        long res = 1000000000000000L;
        int rx = -1, ry = -1;
        
        for(int i=maxx;i>=1;--i) {
            while(sj <= maxy && z < w) {
                // them sj
                add( cj, val[sj], 1);
                // update z
                z += get( count, 1 / val[sj]);
                ++sj;
            }
            
            // System.out.println(i + " " + sj + " " + z);
            
            if(z >= w) {
                long cur = (sj-1) * (long) i;
                if(res > cur) {
                    res = cur;
                    rx = i;
                    ry = sj - 1;
                }
            }
            
            // bot i
            add( count, val[i], -1);
            // update z
            z -= get( cj, 1 / val[i]);
        }
        
        if(rx == -1) System.out.println(-1);
        else System.out.println(rx + " " + ry);
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
        new BaiC().run();
    }
}