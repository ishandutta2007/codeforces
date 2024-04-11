import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int digit(char c) {
        if (c >= '0' && c <= '9')
            return c - '0';
        else
            return 10 + c - 'A';
    }
    
    char letter(int x) {
        if (x < 10)
            return (char) ('0' + x);
        else
            return (char) ('A' + x - 10);
    }

    void solve() throws IOException {
        String[] tmp = nextString().split(" ");
        int initSys = Integer.parseInt(tmp[0]);
        int endSys = 0;
        boolean roman = false;
        if (tmp[1].equals("R"))
            roman = true;
        else
            endSys = Integer.parseInt(tmp[1]);
        
        String num = nextString();
        int i = 0;
        while (i < num.length() && num.charAt(i) == '0')
            i++;
        if (i == num.length()) {
            out.print("0");
            return;
        }
        else
            num = num.substring(i);
        
        long number = 0;
        for (char c : num.toCharArray()) {
            number = number * initSys + digit(c);
        }
        
        //System.err.println(number);
        
        if (!roman) {
            ArrayList<Character> ans = new ArrayList<Character>();
            while (number != 0) {
                ans.add(letter((int) (number % endSys)));
                number /= endSys;
            }
            Collections.reverse(ans);
            for (Character c : ans)
                out.print(c);
        } else {
            while (number >= 1000) {
                out.print("M");
                number -= 1000;
            }
            long dig = number / 100;
            if (dig == 9)
                out.print("CM");
            else if (dig == 4)
                out.print("CD");
            else if (dig >= 5) {
                out.print("D");
                for (int j = 0; j < dig - 5; j++)
                    out.print("C");
            } else {
                for (int j = 0; j < dig; j++)
                    out.print("C");
            }
            number %= 100;
            
            dig = number / 10;
            if (dig == 9)
                out.print("XC");
            else if (dig == 4)
                out.print("XL");
            else if (dig >= 5) {
                out.print("L");
                for (int j = 0; j < dig - 5; j++)
                    out.print("X");
            } else {
                for (int j = 0; j < dig; j++)
                    out.print("X");
            }
            number %= 10;
            dig = number;
            if (dig == 9)
                out.print("IX");
            else if (dig == 4)
                out.print("IV");
            else if (dig >= 5) {
                out.print("V");
                for (int j = 0; j < dig - 5; j++)
                    out.print("I");
            } else {
                for (int j = 0; j < dig; j++)
                    out.print("I");
            }
        }
            
        
            
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}