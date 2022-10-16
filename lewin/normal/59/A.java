import java.util.*;
import java.io.*;

public class A59 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        String s = in.readLine();
        int countL = 0;
        for (char c : s.toCharArray())
            if (c >= 'a' && c <= 'z')
                countL++;
        if (countL >= s.length() - countL)
            out.println (s.toLowerCase());
        else
            out.println (s.toUpperCase());
        out.close();
        System.exit(0);
    }
}