
import java.util.*;
import java.io.*;

public class A96 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        char [] c = in.readLine().toCharArray();
        int count = 1;
        for (int i = 1; i < c.length; i++) {
            if (c [i] == c [i - 1]) {
                count++;
                if (count == 7) {
                    out.println ("YES");
                    out.close();
                    System.exit (0);
                }
            } else count = 1;
        }
        out.println ("NO");
        out.close();
        System.exit(0);
    }
}