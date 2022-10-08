import java.util.Scanner;


public class BaiA {
    
    void run() {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[3];
        int[] b = new int[3];
        for(int i=0;i<3;++i) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        boolean[] infi = new boolean[3];
        for(int i=0;i<3;++i) if(b[i] > 0 && a[i] == 0) {
            infi[(i+1) % 3] = true;
        }
        for(int k=0;k<10;++k) {
            for(int i=0;i<3;++i) if(b[i] > 0 && infi[i]) {
                infi[(i+1) % 3] = true;
            }
        }
        if(b[0] != 0 && b[1] != 0 && b[2] != 0) {
            int tu = 1, mau = 1;
            for(int i=0;i<3;++i) {
                tu *= a[i];
                mau *= b[i];
            }
            if(mau > tu) infi[2] = true;
        }
        if(infi[2]) System.out.println("Ron");
        else System.out.println("Hermione");
    }
    
    public static void main(String[] args) {
        new BaiA().run();
    }
}