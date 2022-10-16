
import java.util.*;
import java.io.*;

public class A71 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        int N = Integer.parseInt (in.readLine());
        for (int i = 0; i < N; i++) {
            String s = in.readLine();
            if (s.length() <= 10) out.println (s);
            else out.println (s.charAt (0) + "" + (s.length() - 2) + "" + s.charAt (s.length() - 1));
        }
        out.close();
        System.exit(0);
    }
}