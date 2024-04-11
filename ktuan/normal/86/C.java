import java.io.*;
import java.util.*;
import java.math.*;

public class BaiC implements Runnable {
    
    class Trie {
        Trie[] next;
        Trie[] jump;
        int len;
        int id;
        
        Trie() {
            next = new Trie[4];
            jump = new Trie[4];
            id = cnt++;
        }
    }
    
    final int mod = 1000000009;
    int[] charToInt;
    int n, m;
    Trie root;
    String[] dna;
    int cnt;
    int[][][] F;
    
    void add(String s) {
        Trie p = root;
        for(int i=0;i<s.length();++i) {
            int id = charToInt[s.charAt(i)];
            if(p.next[id] == null) {
                p.next[id] = new Trie();
            }
            p = p.next[id];
        }
    }
    
    Trie find(String s) {
        Trie p = root;
        for(int i=0;i<s.length();++i) {
            int id = s.charAt(i) - '0';
            if(p.next[id] == null) return null;
            p = p.next[id];
        }
        return p;
    }
    
    void dfs(Trie p, String s) {
        // init len
        for(int i=0;i<s.length();++i) {
            String s2 = s.substring(i);
            boolean found = false;
            for(int j=0;j<dna.length;++j) if(dna[j].equals(s2)) {
                found = true;
                break;
            }
            if(found) {
                p.len = s.length() - i;
                break;
            }
        }
        // init jump
        for(int ad=0;ad<4;++ad) {
            String s2 = s + ad;
            for(int i=0;i<=s2.length();++i) {
                String s3 = s2.substring(i);
                Trie t = find(s3);
                if(t != null) {
                    p.jump[ad] = t;
                    break;
                }
            }
        }
        for(int i=0;i<4;++i) if(p.next[i] != null) {
            dfs( p.next[i], s + i);
        }
    }
    
    int solve(int len, Trie node, int last) {
        if(len == n) {
            if(last == n) return 1;
            else return 0;
        }
        if(len - last > 10) return 0;
        int res = F[len][node.id][len - last];
        if(res != -1) return res;
        res = 0;
        for(int ad=0;ad<4;++ad) {
            Trie nn = node.jump[ad];
            int nl = last;
            if(nn.len > 0) {
                if(last >= len - nn.len + 1) nl = len + 1;
            }
            res += solve( len + 1, nn, nl);
            if(res >= mod) res -= mod;
        }
        F[len][node.id][len - last] = res;
        return res;
    }
    
    public void run() {
        charToInt = new int[256];
        charToInt['A'] = 0;
        charToInt['C'] = 1;
        charToInt['G'] = 2;
        charToInt['T'] = 3;
        n = nextInt();
        m = nextInt();
        dna = new String[m];
        root = new Trie();
        for(int i=0;i<m;++i) {
            String s = nextStr();
            String s2 = "";
            for(int j=0;j<s.length();++j) s2 += charToInt[s.charAt(j)];
            dna[i] = s2;
            add(s);
        }
        dfs(root, "");
        F = new int[n][cnt][12];
        for(int[][] a2 : F) for(int[] a1 : a2) Arrays.fill( a1, -1);
        int res = solve(0, root, 0);
        System.out.println(res);
    }
    
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;
    
    String nextStr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }
    
    int nextInt() {
        return Integer.parseInt(nextStr());
    }
    
    long nextLong() {
        return Long.parseLong(nextStr());
    }
    
    double nextDouble() {
        return Double.parseDouble(nextStr());
    }
    
    public static void main(String[] args) {
        new BaiC().run();
    }
}