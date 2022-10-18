import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out,true);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n  = Integer.parseInt(st.nextToken());
        int d  = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        int a  = Integer.parseInt(st.nextToken());
        int b  = Integer.parseInt(st.nextToken());
        long[][] mas = new long[n][2];
        for(int i = 0;i < n;i++) {
            st = new StringTokenizer(in.readLine());
            mas[i][0] = (long)a * Integer.parseInt(st.nextToken())+ (long) b * Integer.parseInt(st.nextToken());
            mas[i][1] = i+1;
        }
        Arrays.sort(mas,new Comparator<long[]>() {
            @Override
            public int compare(long[] o1, long[] o2) {
                return Long.compare(o1[0], o2[0]);
            }
        });

        int c = 0;
        if(mas[0][0] <= d) c++;
        for(int i = 1;i < n;i++) {
            mas[i][0] += mas[i-1][0];
            if(mas[i][0] <= d) c++;
        }
        //out.println(Arrays.deepToString(mas));
        out.println(c);
        for(int i = 0;i < c;i++) out.print((mas[i][1])+" ");
        out.println();
    }
}