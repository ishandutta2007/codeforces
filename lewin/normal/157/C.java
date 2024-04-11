
import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader (System.in));
        out = new PrintWriter(System.out, true);
        
        String s = in.readLine();
        String t = in.readLine();
        
        String add = "";
        for (int i = 0; i < t.length(); i++)
            add += "*";
        s = add + s + add;
        
        char [] s1 = s.toCharArray();
        char [] s2 = t.toCharArray();
        int min = s2.length;
        for (int i = 0; i < s1.length - s2.length; i++) {
            int match = 0;
            for (int j = 0; j < s2.length; j++)
                if (s1 [i + j] == s2 [j])
                    match++;
            if (s2.length - match <= min)
                min = s2.length - match;
        }
        
        out.println (min);
        out.close();
        System.exit(0);
    }
}