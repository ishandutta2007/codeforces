
import java.util.*;
import java.io.*;

public class A74 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        int N = Integer.parseInt (in.readLine());
        StringTokenizer st;
        int max = -Integer.MAX_VALUE; String name = "";
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer (in.readLine ());
            String s = st.nextToken ();
            int score = 100 * Integer.parseInt (st.nextToken ())
                        - 50 * Integer.parseInt (st.nextToken ()) 
                        + Integer.parseInt (st.nextToken ())
                        + Integer.parseInt (st.nextToken ())
                        + Integer.parseInt (st.nextToken ())
                        + Integer.parseInt (st.nextToken ())
                        + Integer.parseInt (st.nextToken ());
            if (score > max) {
                max = score;
                name = s;
            }
        }
        out.println (name);
        out.close();
        System.exit (0);
    }
}