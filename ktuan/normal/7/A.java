import java.util.*;
public class B1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] a = new char[8][];
        for(int i=0;i<8;++i)
            a[i] = sc.nextLine().toCharArray();
        int dem = 0;
        for(int i=0;i<8;++i) {
            boolean ok = true;
            for(int j=0;j<8;++j) if(a[i][j] != 'B') ok = false;
            if(ok) ++dem;
        }
        for(int j=0;j<8;++j) {
            boolean ok = true;
            for(int i=0;i<8;++i)
                if(a[i][j] != 'B') ok = false;
            if(ok) ++dem;
        }
        if(dem == 16)
            System.out.println(8);
        else System.out.println(dem);
    }
}