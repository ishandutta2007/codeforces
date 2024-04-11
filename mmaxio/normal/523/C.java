import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */
public class C {
    public static void main(String[] args) {
        new C().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        char[] t = nextToken().toCharArray();

        int bl = -1;
        int br = t.length;
        for (int i = 0; i < s.length; i++) {
            bl++;
            while (bl < t.length && t[bl] != s[i]) {
                bl++;
            }
        }
        
        for (int i = s.length - 1; i >= 0; i--) {
        	br--;
        	while (br >= 0 && t[br] != s[i]) {
        		br--;
        	}
        }
        
//        System.err.println(bl + " " + br);

        if (bl == t.length || br == -1 || bl > br) {
            out.println(0);
        }else {
            out.println(br - bl);
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}