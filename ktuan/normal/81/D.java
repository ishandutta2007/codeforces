import java.io.*;
import java.util.*;
import java.math.*;

public class BaiD implements Runnable {
    
    public void run() {
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[m];
        for(int i=0;i<m;++i)
            a[i] = nextInt();
        if(n % 2 == 1 && m == 2) {
            System.out.println(-1);
            return;
        }
        {
            int total = 0;
            for(int i=0;i<m;++i)
                total += a[i];
            if(total < n) {
                System.out.println(-1);
                return;
            }
        }
        int maxi = n / 2;
        for(int i=0;i<m;++i)
        {
            int total = 0;
            for(int j=0;j<m;++j) if(j != i) total += a[j];
            if(total < n - maxi)
            {
                System.out.println(-1);
                return;
            }
        }
        
        ArrayList<int[]> ar = new ArrayList<int[]>();
        for(int i=0;i<m;++i)
            ar.add(new int[]{a[i],i});
        Collections.sort(ar, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]) return b[0] - a[0];
                else return a[1] - b[1];
            }
        });
        
        int[] f = new int[n];
        boolean dau = true;
        for(int i=0;i<ar.size();++i) {
            int sl = ar.get(i)[0];
            int id = ar.get(i)[1] + 1; 
            if(dau) {
                for(int j=0;j<n;++j) if(f[j] == 0 && sl > 0 && f[(j+1)%n] != id && f[(j+n-1)%n] != id) {
                    f[j] = id;
                    --sl;
                }
            }
            else {
                for(int j=n-1;j>=0;--j) if(f[j] == 0 && sl > 0 && f[(j+1)%n] != id && f[(j+n-1)%n] != id) {
                    f[j] = id;
                    --sl;
                }
            }
            
            dau = !dau;
        }
        
        for(int i=0;i<n;++i)
            System.out.print(f[i] + " ");
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
        new BaiD().run();
    }
}