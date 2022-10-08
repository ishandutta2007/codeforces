import java.util.*;
public class B2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int x = 0, y = 0;
        int[][] a = new int[1000][2];
        int na = 0;
        a[na++] = new int[]{x,y};
        boolean ok = true;
        for(int i=0;i<s.length();++i) {
            if(s.charAt(i) == 'L') {
                --y;
            } else
                if(s.charAt(i) == 'R') {
                    ++y;
                } else
                    if(s.charAt(i) == 'D') {
                        --x;
                    } else
                        if(s.charAt(i) == 'U') {
                            ++x;
                        } 
            a[na++] = new int[]{x,y};
        }
        for(int i=0;i<na;++i) for(int j=0;j<na;++j)
            if(Math.abs(i-j) > 1) {
                int t = Math.abs(a[i][0]-a[j][0]) + Math.abs(a[i][1] - a[j][1]);
                if(t <= 1) ok =false;
            }
        if(ok) System.out.println("OK");
        else System.out.println("BUG");
    }
}