
import java.util.*;
import java.io.*;

public class A58 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        char [] c = in.readLine().toCharArray();
        char [] hello = new char [] {'h', 'e', 'l', 'l', 'o'};
        int idx = 0;
        boolean ok = false;
        for (int i = 0; i < c.length; i++) {
            if (c [i] == hello [idx]) idx++;
            if (idx == 5) {
                ok = true;
                break;
            }
        }
        out.println (ok ? "YES" : "NO");
        out.close();
        System.exit(0);
    }
}