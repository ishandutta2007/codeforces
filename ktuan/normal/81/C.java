import java.io.*;
import java.util.*;
import java.math.*;

public class BaiC implements Runnable {
    
    public void run() {
        int n = nextInt();
        int a = nextInt();
        int b = nextInt();
        int[] c = new int[n];
        for(int i=0;i<n;++i)
            c[i] = nextInt();
        
        ArrayList<int[]> ar = new ArrayList<int[]>();
        for(int i=0;i<n;++i)
            ar.add(new int[]{c[i], i});
        
        if(a == b) {
            for(int i=0;i<a;++i) System.out.print(1 + " ");
            for(int i=0;i<a;++i) System.out.print(2 + " ");
        }
        else if(a < b) {
            Collections.sort(ar, new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    if(a[0] != b[0]) return b[0] - a[0];
                    else return a[1] - b[1];
                }
            });
            int[] f = new int[n];
            Arrays.fill(f, 2);
            for(int i=0;i<a;++i) f[ar.get(i)[1]] = 1;
            for(int i=0;i<n;++i) System.out.print(f[i] + " ");
        }
        else {
            Collections.sort(ar, new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    if(a[0] != b[0]) return a[0] - b[0];
                    else return a[1] - b[1];
                }
            });
            int[] f = new int[n];
            Arrays.fill(f, 2);
            for(int i=0;i<a;++i) f[ar.get(i)[1]] = 1;
            for(int i=0;i<n;++i) System.out.print(f[i] + " ");
        }
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