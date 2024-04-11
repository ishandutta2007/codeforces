import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int INF = 1000000000;
    
    String[] names = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    HashMap<String, Integer> hm;
    
    boolean[][] like;
    int[] gr;
    
    int[] exp;
    int bestLikes = -1;
    int bestDiff = INF;
    
    
    void go(int v) {
        if (v == 7) {
            int[] cnt = new int[3];
            for (int i = 0; i < 7; i++)
                cnt[gr[i]]++;
            
            for (int i = 0; i < 3; i++)
                if (cnt[i] == 0)
                    return;
                else
                    cnt[i] = exp[i] / cnt[i];
            
            int curDiff = 0;
            int curLikes = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    curDiff = Math.max(curDiff, cnt[i] - cnt[j]);
            
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 7; j++)
                    if (gr[i] == gr[j] && like[i][j])
                        curLikes++;
            
            if (curDiff < bestDiff || (curDiff == bestDiff && curLikes > bestLikes)) {
                bestDiff = curDiff;
                bestLikes = curLikes;
            }
            return;
        }
        for (int i = 0; i < 3; i++) {
            gr[v] = i;
            go(v + 1);
        }
    }
    
    void solve() throws IOException {
        
        hm = new HashMap<String, Integer>();
        for (int i = 0; i < names.length; i++) {
            hm.put(names[i], i);
        }
        
        like = new boolean[7][7];
        gr = new int[7];
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int v1 = hm.get(nextToken());
            nextToken();
            int v2 = hm.get(nextToken());
            like[v1][v2] = true;
        }
        
        exp = new int[3];
        for (int i = 0; i < 3; i++)
            exp[i] = nextInt();
        
        go(0);
        
        out.print(bestDiff + " " + bestLikes);
        
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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