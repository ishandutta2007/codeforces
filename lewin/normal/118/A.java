import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main{
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    Arrays.stream(in.readLine().split("")).forEach(c -> {
        char k = Character.toLowerCase(c.charAt(0));
        if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' || k == 'y') 
          return;
        out.print("." + k);
      }
    );
    out.println();
    out.close();
    System.exit(0);
  }
}