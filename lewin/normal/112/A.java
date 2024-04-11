import java.util.*;
import java.io.*;

public class A112 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        String s1 = in.readLine().toLowerCase(), s2 = in.readLine().toLowerCase();
        out.println ((int)Math.signum (s1.compareTo (s2)));
        out.close();
        System.exit(0);
    }
}