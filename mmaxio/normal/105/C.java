import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MAXSIZE = 10;

    class Weapon {
        String name;
        int base;// base MAIN stat
        int size;

        public Weapon(String name, int base, int size) {
            this.name = name;
            this.base = base;
            this.size = size;
        }

    }

    class Resident implements Comparable<Resident>{
        String name;
        String home;
        int bonus;

        public Resident(String name, String home, int bonus) {
            super();
            this.name = name;
            this.home = home;
            this.bonus = bonus;
        }

        @Override
        public int compareTo(Resident o) {
            return o.bonus - bonus;
        }
        
        
    }

    void solve() throws IOException {
        int n = nextInt();

        ArrayList<Weapon> atk = new ArrayList<Weapon>();
        ArrayList<Weapon> def = new ArrayList<Weapon>();
        ArrayList<Weapon> res = new ArrayList<Weapon>();

        int totalSize = 0;

        for (int i = 0; i < n; i++) {
            
            String[] tmp = nextString().split(" ");
            ArrayList<Weapon> cur = null;
            int ind = -1;
            if (tmp[1].equals("weapon")) {
                cur = atk;
                ind = 2;
            } else if (tmp[1].equals("armor")) {
                cur = def;
                ind = 3;
            } else if (tmp[1].equals("orb")) {
                cur = res;
                ind = 4;
            }
            cur.add(new Weapon(tmp[0], Integer.parseInt(tmp[ind]), Integer
                    .parseInt(tmp[5])));
            totalSize += Integer.parseInt(tmp[5]);
        }

        int k = nextInt();

        ArrayList<Resident> atkR = new ArrayList<Resident>();
        ArrayList<Resident> defR = new ArrayList<Resident>();
        ArrayList<Resident> resR = new ArrayList<Resident>();

        for (int i = 0; i < k; i++) {
            String[] tmp = nextString().split(" ");
            ArrayList<Resident> curR = null;
            if (tmp[1].equals("gladiator"))
                curR = atkR;
            else if (tmp[1].equals("sentry"))
                curR = defR;
            else if (tmp[1].equals("physician"))
                curR = resR;

            curR.add(new Resident(tmp[0], tmp[3], Integer.parseInt(tmp[2])));

        }

        if (totalSize == k) {
            Weapon bestW = null;
            int bestStat = 0;
            for (Weapon w : atk) {
                int cur = w.base;
                for (Resident r : atkR)
                    if (r.home.equals(w.name))
                        cur += r.bonus;
                if (cur > bestStat) {
                    bestStat = cur;
                    bestW = w;
                }
            }
            out.print(bestW.name + " " + bestW.size + " ");
            for (Resident r : atkR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : defR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : resR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            out.println();

            bestW = null;
            bestStat = 0;
            for (Weapon w : def) {
                int cur = w.base;
                for (Resident r : defR)
                    if (r.home.equals(w.name))
                        cur += r.bonus;
                if (cur > bestStat) {
                    bestStat = cur;
                    bestW = w;
                }
            }
            out.print(bestW.name + " " + bestW.size + " ");
            for (Resident r : atkR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : defR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : resR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            out.println();

            bestW = null;
            bestStat = 0;
            for (Weapon w : res) {
                int cur = w.base;
                for (Resident r : resR)
                    if (r.home.equals(w.name))
                        cur += r.bonus;
                if (cur > bestStat) {
                    bestStat = cur;
                    bestW = w;
                }
            }
            out.print(bestW.name + " " + bestW.size + " ");
            for (Resident r : atkR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : defR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            for (Resident r : resR)
                if (r.home.equals(bestW.name))
                    out.print(r.name + " ");
            out.println();
            return;
        }

        // this task sucks a lot
        
        Collections.sort(atkR);
        Collections.sort(defR);
        Collections.sort(resR);
        int[] bonusAtk = new int[MAXSIZE + 1];
        int[] bonusDef = new int[MAXSIZE + 1];
        int[] bonusRes = new int[MAXSIZE + 1];
        bonusAtk[0] = 0;
        for (int i = 1; i <= MAXSIZE; i++) {
            if (i >= atkR.size())
                bonusAtk[i] = bonusAtk[i - 1];
            else
                bonusAtk[i] = bonusAtk[i - 1] + atkR.get(i - 1).bonus;
        }
        bonusDef[0] = 0;
        for (int i = 1; i <= MAXSIZE; i++) {
            if (i >= defR.size())
                bonusDef[i] = bonusDef[i - 1];
            else
                bonusDef[i] = bonusDef[i - 1] + defR.get(i - 1).bonus;
        }
        bonusRes[0] = 0;
        for (int i = 1; i <= MAXSIZE; i++) {
            if (i >= resR.size())
                bonusRes[i] = bonusRes[i - 1];
            else
                bonusRes[i] = bonusRes[i - 1] + resR.get(i - 1).bonus;
        }
        
        Weapon bestAtk = null;
        int bestStat = -1;
        for (Weapon w : atk)
            if (w.base + bonusAtk[w.size] > bestStat) {
                bestStat = w.base + bonusAtk[w.size];
                bestAtk = w;
            }
        
        Weapon bestDef = null;
        bestStat = -1;
        for (Weapon w : def)
            if (w.base + bonusDef[w.size] > bestStat) {
                bestStat = w.base + bonusDef[w.size];
                bestDef = w;
            }
        
        Weapon bestRes = null;
        bestStat = -1;
        for (Weapon w : res)
            if (w.base + bonusRes[w.size] > bestStat) {
                bestStat = w.base + bonusRes[w.size];
                bestRes = w;
            }
        
        ArrayList<Resident> unusedR = new ArrayList<Resident>();
        for (int i = bestAtk.size; i < atkR.size(); i++)
            unusedR.add(atkR.get(i));
        for (int i = bestDef.size; i < defR.size(); i++)
            unusedR.add(defR.get(i));
        for (int i = bestRes.size; i < resR.size(); i++)
            unusedR.add(resR.get(i));
        
        int leftSize = totalSize - bestAtk.size - bestDef.size - bestRes.size;
        
        int needAdd = Math.max(unusedR.size() - leftSize, 0);
        
        int outpAtk = Math.min(bestAtk.size, atkR.size() + needAdd);
        out.print(bestAtk.name + " " + outpAtk + " ");
        int outpNeed = Math.min(outpAtk, atkR.size());
        for (int i = 0; i < outpNeed; i++)
            out.print(atkR.get(i).name + " ");
        for (int i = outpNeed; i < bestAtk.size && needAdd > 0; i++)
            out.print(unusedR.get(--needAdd).name);
        out.println();
        
        int outpDef = Math.min(bestDef.size, defR.size() + needAdd);
        out.print(bestDef.name + " " + outpDef + " ");
        outpNeed = Math.min(outpDef, defR.size());
        for (int i = 0; i < outpNeed; i++)
            out.print(defR.get(i).name + " ");
        for (int i = outpNeed; i < bestDef.size && needAdd > 0; i++)
            out.print(unusedR.get(--needAdd).name + " ");
        out.println();
        
        int outpRes = Math.min(bestRes.size, resR.size() + needAdd);
        out.print(bestRes.name + " " + outpRes + " ");
        outpNeed = Math.min(outpRes, resR.size());
        for (int i = 0; i < outpNeed; i++)
            out.print(resR.get(i).name + " ");
        for (int i = outpNeed; i < bestRes.size && needAdd > 0; i++)
            out.print(unusedR.get(--needAdd).name + " ");

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