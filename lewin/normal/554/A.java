import java.util.HashSet;
import java.util.Scanner;

public class MissingLetter {
  public static void main (String[] args) {
    Scanner in = new Scanner (System.in);
    String s = in.next();
    HashSet<String> hs = new HashSet<>();
    for (int i = 0; i <= s.length(); i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        hs.add(s.substring(0,i)+c+s.substring(i));
      }
    }
    System.out.println(hs.size());
    System.exit(0);
  }
}