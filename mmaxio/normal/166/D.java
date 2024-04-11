import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Shoe {
        int size;
        int cost;
        int id;

        public Shoe(int cost, int size, int id) {
            this.size = size;
            this.cost = cost;
            this.id = id;
        }

    }

    class Man {
        int money;
        int id;

        public Man(int money, int id) {
            this.money = money;
            this.id = id;
        }

    }

    int rightL, rightR;
    int leftL, leftR;
    Shoe[] bySize;
    Man[][] list;
    int allSz;
    int[] all;

    void dfsShoe(int v) {
        useShoe[v] = true;
        rightR = v + 1;
        if (list[v][0] != null && list[v][0].money >= bySize[v].cost)
            dfsMan(v);
    }

    void dfsMan(int v) {
        useMan[v] = true;
        leftR = v + 1;
        if (v != allSz - 1 && all[v + 1] == all[v] + 1 && bySize[v + 1] != null
                && list[v][0].money >= bySize[v + 1].cost)
            dfsShoe(v + 1);
    }

    boolean[] useShoe;
    boolean[] useMan;
    long profit;
    ArrayList<Integer> ans;

    void upgradeAnswer() {
        int szLeft = leftR - leftL;
        int szRight = rightR - rightL;
        if (szLeft == szRight - 1) {
            int cool = -1;
            for (int i = 0; i < szLeft; i++)
                if (list[leftL + i][1] != null) {
                    cool = i;
                    break;
                }
            if (cool == -1) {
                int min = Integer.MAX_VALUE;
                int minPos = -1;
                for (int i = 0; i < szRight; i++)
                    if (bySize[i + rightL].cost < min) {
                        min = bySize[i + rightL].cost;
                        minPos = i;
                    }
                for (int i = 0; i < minPos; i++) {
                    int cLeft = leftL + i;
                    int cRight = rightL + i;
                    profit += bySize[cRight].cost;
                    ans.add(list[cLeft][0].id);
                    ans.add(bySize[cRight].id);
                }
                for (int i = minPos + 1; i < szRight; i++) {
                    int cLeft = leftL + i - 1;
                    int cRight = rightL + i;
                    profit += bySize[cRight].cost;
                    ans.add(list[cLeft][0].id);
                    ans.add(bySize[cRight].id);
                }
            } else {
                for (int i = 0; i < cool; i++) {
                    int cLeft = leftL + i;
                    int cRight = rightL + i;
                    profit += bySize[cRight].cost;
                    ans.add(list[cLeft][0].id);
                    ans.add(bySize[cRight].id);
                }
                for (int i = cool + 1; i < szLeft; i++) {
                    int cLeft = leftL + i;
                    int cRight = rightL + i + 1;
                    profit += bySize[cRight].cost;
                    ans.add(list[cLeft][0].id);
                    ans.add(bySize[cRight].id);
                }
                // WORST FUCKING PART
                profit += bySize[cool + rightL].cost
                        + bySize[cool + 1 + rightL].cost;
                if (list[cool + leftL][1].money >= bySize[cool + rightL].cost) {
                    ans.add(list[cool + leftL][1].id);
                    ans.add(bySize[cool + rightL].id);
                    ans.add(list[cool + leftL][0].id);
                    ans.add(bySize[cool + rightL + 1].id);
                } else if (list[cool + leftL][0].money >= bySize[cool + rightL].cost) {
                    ans.add(list[cool + leftL][1].id);
                    ans.add(bySize[cool + rightL + 1].id);
                    ans.add(list[cool + leftL][0].id);
                    ans.add(bySize[cool + rightL].id);
                } else
                    throw new AssertionError();
            }

        } else if (szLeft == szRight) {
            for (int i = 0; i < szLeft; i++) {
                int cLeft = leftL + i;
                int cRight = rightL + i;
                profit += bySize[cRight].cost;
                ans.add(list[cLeft][0].id);
                ans.add(bySize[cRight].id);
            }
        } else if (szLeft == szRight + 1) {
            for (int i = 0; i < szRight; i++) {
                int cLeft = leftL + i;
                int cRight = rightL + i;
                profit += bySize[cRight].cost;
                ans.add(list[cLeft][0].id);
                ans.add(bySize[cRight].id);
            }
        } else
            throw new AssertionError();
    }

    void solve() throws IOException {
        ArrayList<Integer> allAL = new ArrayList<Integer>();
        int n = nextInt();
        Shoe[] shoes = new Shoe[n];
        for (int i = 0; i < n; i++) {
            shoes[i] = new Shoe(nextInt(), nextInt(), i + 1);
            allAL.add(shoes[i].size - 1);
            allAL.add(shoes[i].size);
        }

        Collections.sort(allAL);
        allSz = 1;
        for (int i = 1; i < allAL.size(); i++) {
            int val = allAL.get(i);
            if (val != allAL.get(allSz - 1).intValue())
                allAL.set(allSz++, val);
        }

        all = new int[allSz];
        for (int i = 0; i < allSz; i++)
            all[i] = allAL.get(i);

        bySize = new Shoe[allSz];
        for (Shoe s : shoes) {
            s.size = Arrays.binarySearch(all, s.size);
            bySize[s.size] = s;
        }

        int m = nextInt();
        list = new Man[allSz][2];
        int[] cnt = new int[allSz];
        for (int i = 0; i < m; i++) {
            int money = nextInt();
            int foot = nextInt();
            foot = Arrays.binarySearch(all, foot);
            if (foot < 0)
                continue;
            int canBuy = 0;
            if (bySize[foot] != null && bySize[foot].cost <= money)
                canBuy++;
            if (foot != allSz - 1 && all[foot + 1] == all[foot] + 1
                    && bySize[foot + 1] != null
                    && bySize[foot + 1].cost <= money)
                canBuy++;

            if (canBuy == 0)
                continue;
            int ins = 0;
            while (ins < 2 && list[foot][ins] != null
                    && list[foot][ins].money > money)
                ins++;
            if (ins < 2) {
                cnt[foot]++;
                for (int j = Math.min(cnt[foot], 1); j > ins; j--)
                    list[foot][j] = list[foot][j - 1];
                list[foot][ins] = new Man(money, i + 1);
            }
        }

        profit = 0;
        ans = new ArrayList<Integer>();
        useShoe = new boolean[allSz];
        useMan = new boolean[allSz];

        for (int i = 0; i < allSz; i++) {
            if (!useShoe[i] && bySize[i] != null) {
                rightL = i;
                rightR = i;
                leftL = i;
                leftR = i;
                dfsShoe(i);
                upgradeAnswer();
            }
            if (!useMan[i] && list[i][0] != null) {
                rightL = i + 1;
                rightR = i + 1;
                leftL = i;
                leftR = i;
                dfsMan(i);
                upgradeAnswer();
            }
        }

        out.println(profit);
        out.println(ans.size() / 2);
        for (int i = 0; i < ans.size(); i += 2)
            out.println(ans.get(i) + " " + ans.get(i + 1));

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
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