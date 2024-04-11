import java.io.*;
import java.util.*;

public class tisland
{
    public static void main (String [] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        PrintWriter out = new PrintWriter (System.out, true);
        
        StringTokenizer st = new StringTokenizer (in.readLine());
        int N = Integer.parseInt (st.nextToken()), M = Integer.parseInt (st.nextToken());
        char [][] grid = new char [N][M];
        Coord [] locs = new Coord [26];
        for (int i = 0; i < N; i++) {
            grid [i] = in.readLine().toCharArray();
            for (int j = 0; j < M; j++)
                if (grid [i][j] >= 'A' && grid [i][j] <= 'Z')
                    locs [(int)(grid [i][j] - 'A')] = new Coord (i, j);
        }
        int [][][] extend = new int [N][M][4];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid [i][j] == '#') {
                    extend [i][j][0] = -1;
                    extend [i][j][1] = -1;
                } else {
                    extend [i][j][0] = extend [i - 1][j][0] + 1;
                    extend [i][j][1] = extend [i][j - 1][1] + 1;
                }
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (grid [i][j] == '#') {
                    extend [i][j][2] = -1;
                    extend [i][j][3] = -1;
                } else {
                    extend [i][j][2] = extend [i + 1][j][2] + 1;
                    extend [i][j][3] = extend [i][j + 1][3] + 1;
                }
            }
        }
        
        int K = Integer.parseInt (in.readLine());
        Instruction [] inst = new Instruction [K];
        for (int i = 0; i < K; i++) {
            String [] s = in.readLine().split (" ");
            inst [i] = new Instruction (s[0].charAt(0), Integer.parseInt(s[1]));
        }
        
        boolean [] canuse = new boolean [26];
        boolean used = false;
        for (int i = 0; i < 26; i++) {
            if (locs [i] == null) continue;
            int curx = locs [i].x, cury = locs [i].y;
            boolean ok = true;
            outer : for (int j = 0; j < K; j++) {
                switch (inst [j].dir) {
                    case 'N' :
                        if (extend [curx][cury][0] < inst [j].steps) {
                            ok = false;
                            break outer;
                        }
                        curx -= inst [j].steps;
                        break;
                    case 'W' :
                        if (extend [curx][cury][1] < inst [j].steps) {
                            ok = false;
                            break outer;
                        }
                        cury -= inst [j].steps;
                        break;
                    case 'S' :
                        if (extend [curx][cury][2] < inst [j].steps) {
                            ok = false;
                            break outer;
                        }
                        curx += inst [j].steps;
                        break;
                    case 'E' :
                        if (extend [curx][cury][3] < inst [j].steps) {
                            ok = false;
                            break outer;
                        }
                        cury += inst [j].steps;
                        break;
                }
            }
            if (ok) {used = true; canuse [i] = true;}
        }
        if (!used) {
            out.println ("no solution");
        } else {
            String s = "";
            for (int i = 0; i < 26; i++)
                if (canuse [i])
                    s += (char)(i + 'A');
            out.println (s);
        }
        out.close();
        System.exit(0);
    }
    
    static class Instruction {
        public char dir;
        public int steps;
        
        public Instruction (char dir, int steps) {
            this.dir = dir;
            this.steps = steps;
        }
    }
    
    static class Coord {
        public int x, y;
        public Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}