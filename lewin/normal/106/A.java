import java.io.*;
import java.util.*;

public class cardgame
{
    public static void main (String [] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        PrintWriter out = new PrintWriter (System.out, true);
        
        char suit = in.readLine().charAt (0);
        String [] cards = in.readLine().split (" ");
        
        if (cards[0].charAt(1) == suit && cards[1].charAt(1) != suit)
            out.println ("YES");
        else if (cards [0].charAt(1) != cards[1].charAt(1))
            out.println ("NO");
        else if (rank (cards[0].charAt(0)) > rank (cards[1].charAt(0)))
            out.println ("YES");
        else
            out.println ("NO");
    }
    
    private static char [] arr = new char [] {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    private static int rank (char c) {
        for (int i = 0; i < arr.length; i++)
            if (c == arr [i]) return i;
        return -1;
    }
}