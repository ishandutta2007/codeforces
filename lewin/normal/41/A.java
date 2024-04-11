
import java.util.*;
import java.io.*;

public class A41 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        String s1 = in.readLine(), s2 = in.readLine();
        boolean print = false;
        for (int i = 0; i < s1.length(); i++)
            if (s2.charAt (s2.length() - 1 - i) != s1.charAt (i)) {
                print = true;
                out.println ("NO");
                break;
            }
        if (!print) out.println ("YES");
        out.close();
        System.exit(0);
    }
}