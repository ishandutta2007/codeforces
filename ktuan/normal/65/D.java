import java.util.*;
import java.math.*;
import java.io.*;

public class BaiD {
    
    int n;
    char[] a;
    
    void run() {
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        a = sc.next().toCharArray();
        
        /*
        {
            n = 10000;
            a = new char[n];
            String s = "GHRS?";
            Random random = new Random();
            for(int i=0;i<n;++i) {
                a[i] = s.charAt(random.nextInt(5));
            }
        }*/
        Comparator comp = new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                for(int i=0;i<a.length;++i)
                    if(a[i] != b[i])
                        return a[i] - b[i];
                return 0;
            }
        };
        
        TreeSet<int[]> se = new TreeSet<int[]>(comp);
        se.add(new int[]{0,0,0,0});
        String[] longName = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin" };
        String s = "";
        for(int i=0;i<4;++i)
            s = s + longName[i].charAt(0);
        for(int i=0;i<n;++i) {
            int id = s.indexOf(a[i]);
            TreeSet<int[]> nse = new TreeSet<int[]>(comp);
            for(int[] oldstate : se) {
                if(id == -1) {
                    int minvalue = getmin(oldstate);
                    for(int j=0;j<4;++j) if(oldstate[j] == minvalue) {
                        int[] z = oldstate.clone();
                        z[j]++;
                        nse.add(z);
                    }
                }
                else {
                    int[] z = oldstate.clone();
                    z[id]++;
                    nse.add(z);
                }
            }
            se = nse;
        }
        {
            boolean[] ok = new boolean[4];
            for(int[] state : se) {
                int minvalue = getmin(state);
                for(int j=0;j<4;++j) if(state[j] == minvalue) {
                    ok[j] = true;
                }
            }
            for(int j=0;j<4;++j) if(ok[j]) System.out.println(longName[j]);
        }
    }
    
    int getmin(int[] z) {
        int r = z[0];
        for(int i=1;i<z.length;++i) r = Math.min(r,z[i]);
        return r;
    }
    
    public static void main(String[] args) {
        new BaiD().run();
    }
}