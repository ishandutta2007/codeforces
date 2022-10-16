
import java.util.*;
import java.io.*;

public class A61 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        String s1 = in.readLine(), s2 = in.readLine();
        for (int i = 0; i < s1.length(); i++)
            out.print (s1.charAt (i) == s2.charAt (i) ? '0' : '1');
        out.println();
        out.close();
        System.exit(0);
    }
}