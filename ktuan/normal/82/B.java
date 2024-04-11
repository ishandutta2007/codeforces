import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    Comparator<int[]> comp = new Comparator<int[]>() {
    
        public int compare(int[] arg0, int[] arg1) {
            for(int i=0;i<arg0.length && i<arg1.length;++i) {
                if(arg0[i] != arg1[i])
                    return arg0[i] - arg1[i];
            }
            return arg0.length - arg1.length;
        }
    };
    
    public void run() {
        int n = nextInt();
        int[][] ds = new int[n * (n-1) / 2][];
        for(int i=0;i<n*(n-1)/2;++i) {
            int k = nextInt();
            ds[i] = new int[k];
            for(int j=0;j<k;++j)
                ds[i][j] = nextInt();
            Arrays.sort(ds[i]);
        }
        Arrays.sort(ds, comp);
        if(n == 2) {
            System.out.println(1 + " " + ds[0][0]);
            System.out.print(ds[0].length-1);
            for(int i=1;i<ds[0].length;++i)
                System.out.print(" " + ds[0][i]);
            System.out.println();
            return;
        }
        Set<int[]> se = new TreeSet<int[]>(comp);
        for(int i=0;i+1<ds.length;++i) {
            int s = 0;
            ArrayList<Integer> ar = new ArrayList<Integer>();
            for(int j=0;j<ds[i].length;++j) {
                while(s < ds[i+1].length && ds[i+1][s] < ds[i][j])
                    ++s;
                if(s < ds[i+1].length && ds[i+1][s] == ds[i][j])
                    ar.add(ds[i][j]);
            }
            if(ar.size() == 0) continue;
            int[] z = new int[ar.size()];
            for(int j=0;j<ar.size();++j)
                z[j] = ar.get(j);
            se.add(z);
            boolean[] mark = new boolean[202];
            for(int j=0;j<z.length;++j) mark[z[j]] = true;
            add( ds[i], mark, se);
            add( ds[i+1], mark, se);
        }
        for(int[] a : se) {
            System.out.print(a.length);
            for(int i=0;i<a.length;++i)
                System.out.print(" " + a[i]);
            System.out.println();
        }
    }
    
    void add(int[] a, boolean[] b, Set<int[]> se) {
        int c = 0;
        for(int i=0;i<a.length;++i)
            if(!b[a[i]]) ++c;
        int[] r = new int[c];
        c = 0;
        for(int i=0;i<a.length;++i)
            if(!b[a[i]])
                r[c++] = a[i];
        se.add(r);
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
        new BaiB().run();
    }
}