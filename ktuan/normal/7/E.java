import java.util.*;

public class B5 {
    
    static class Expr {
        String s;
        boolean[] left, right; // + - * /
        boolean bad;
        Expr() {
            left = new boolean[4];
            right = new boolean[4];
        }
        void normal() {
            String r = "";
            for(int i=0;i<s.length();++i)
                if(s.charAt(i) != ' ')
                    r = r + s.charAt(i);
            s = r;
        }
        
        boolean isname(char c) {
            return "+-*/()0123456789".indexOf(c) == -1;
        }
        
        int getop(char c) {
            return "+-*/".indexOf(c);
        }
        
        void process() {
            // init is bad
            for(int i=0;i<s.length();++i) {
                if(isname(s.charAt(i))) {
                    int j = i;
                    while(j < s.length() && isname(s.charAt(j))) ++j;
                    --j;
                    char before = ' ', after = ' ';
                    if(i > 0) before = s.charAt(i-1);
                    if(j + 1 < s.length()) after = s.charAt(j+1);
                    int bop = getop(before);
                    int aop = getop(after);
                    String sn = s.substring(i, j + 1);
                    if(ma.containsKey(sn)) {
                        int id = ma.get(sn);
                        // System.out.println(id);
                        if(bop != -1 && a[id].e.left[bop]) bad = true;
                        if(aop != -1 && a[id].e.right[aop]) bad = true;
                        if(a[id].e.bad) bad = true;
                    }
                    i = j;
                }
            }
            // init left / right
            int level = 0;
            for(int i=0;i<s.length();++i) {
                if(s.charAt(i) == '(') level ++;
                else if(s.charAt(i) == ')') level --;
                else {
                    int op = getop(s.charAt(i));
                    if(op != -1 && level == 0) {
                        if(op == 0) { // +
                            left[1] = true;
                            left[2] = true;
                            left[3] = true;
                            right[2] = right[3] = true;
                        }
                        else if(op == 1) { // -
                            left[1] = left[2] = left[3] = true;
                            right[2] = right[3] = true;
                        }
                        else if(op == 2) { // *
                            left[3] = true;
                        }
                        else {
                            left[3] = true;
                        }
                    }
                }
            }
        }
    }
    
    static class Def {
        
        String name;
        Expr e;
        
        Def() {}
    }
    
    static Def[] a;
    static TreeMap<String, Integer> ma = new TreeMap<String, Integer>();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        a = new Def[n+1];
        for(int i=0;i<n;++i) {
            String s = sc.nextLine();
            String name = null;
            String ex = null;
            int dem = 0;
            for(int j=0;j<s.length();++j) {
                if(s.charAt(j) == 'e') ++dem;
                if(dem == 2) {
                    s = s.substring(j + 1);
                    while(s.charAt(0) == ' ') s = s.substring(1);
                    for(int t=0;t<s.length();++t) if(s.charAt(t) == ' ') {
                        name = s.substring(0,t);
                        ex = s.substring(t+1,s.length());
                        break;
                    }
                    break;
                }
            }
            a[i] = new Def();
            a[i].name = name;
            a[i].e = new Expr();
            a[i].e.s = ex;
        }
        a[n] = new Def();
        a[n].name = "A_B_C";
        a[n].e = new Expr();
        a[n].e.s = sc.nextLine();
        for(int i=0;i<=n;++i) {
            a[i].e.normal();
            a[i].e.process();
            ma.put(a[i].name, i);
        }
        if(a[n].e.bad)
            System.out.println("Suspicious");
        else System.out.println("OK");
    }
}