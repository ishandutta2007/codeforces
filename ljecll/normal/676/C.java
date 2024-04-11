import java.io.*;
import java.util.*;
import java.lang.Math;
public class temp {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(sc.nextLine());
        String abstring = st.nextToken();
        int acount = 0;
        int bcount = 0;
        int answer = 0;
        int j = -1;
        for (int i = 0; i < N; i++) {
            if (i > 0) {
                if (abstring.charAt(i-1) == 'a') {
                    acount--;
                    }
                else {
                    bcount--;
                }
            }
            // System.out.println("? " + i + " " + j + " " + acount + " " + bcount);
            while (j < N) {
                // System.out.println(i + " " + j + " " + acount + " " + bcount);
                //System.out.println(Math.min(acount, bcount));
                if (Math.min(acount, bcount) > K) {
                    break;
                }
                j++;
                if (j == N)
                {
                    break;
                }
                if (abstring.charAt(j) == 'a') {
                    acount++;
                }
                else {
                    bcount++;
                }
            }
            //System.out.println(j);
            if (j - i > answer) {
                //System.out.println(j - i);
                answer = j - i;
            }
            // System.out.println(i + " " + j);
        }
        System.out.println(answer);
    }
}