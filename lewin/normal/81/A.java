
import java.util.*;
import java.io.*;

public class A81 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        char [] c  = in.readLine().toCharArray();
        char [] ans = new char [c.length];
        int front = 0;
        for (int i = 0; i < c.length; i++)
            if (front == 0 || ans [front - 1] != c [i])
                ans [front++] = c [i];
            else front--;
        out.println (new String (ans, 0, front));
        out.close();
        System.exit(0);
    }
}