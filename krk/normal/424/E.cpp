#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const ld Inf = 1e9;
const string cols = "RGB";
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxd = 3;
const int Maxm = 200;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arg1, arg2;
int pw1[Maxm], pw2[Maxm];

struct layer {
    int val[Maxd];
    ii h;
    void Update()
    {
        if (val[0] > val[2]) swap(val[0], val[2]);
        //if (!val[0] && val[1]) val[1] = 1;
        h.first = ((ll(val[0]) * arg1 + val[1]) % mod1 * arg1 + val[2]) % mod1;
        h.second = ((ll(val[0]) * arg2 + val[1]) % mod2 * arg2 + val[2]) % mod2;
    }
    layer() {
        val[0] = val[1] = val[2] = 0;
        h = ii(0, 0);
    }
    layer(const string &s)
    {
        for (int i = 0; i < s.length(); i++)
            val[i] = cols.find(s[i]) + 1;
        Update();
    }
    bool canTake(int x)
    {
        return val[x] && (x == 1 && val[0] && val[2] || x != 1 && val[1]);
    }
    bool canPutSide()
    {
        return !val[0] || !val[2];
    }
    bool canPutMiddle()
    {
        return !val[1];
    }
    int Take(int x)
    {
        int res = val[x]; val[x] = 0;
        Update();
        return res;
    }
    void putSide(int x)
    {
        if (!val[2]) val[2] = x;
        else val[0] = x;
        Update();
    }
    void putMiddle(int x)
    {
        val[1] = x;
        Update();
    }
    bool Full()
    {
        return val[0] && val[1] && val[2];
    }
    bool Final()
    {
        return !val[1] || !val[0] && !val[2];
    }
};

struct node {
    vector <layer> layers;
    ii h;
    void removeLayer(int a)
    {
        h.first = (h.first - ll(pw1[3 * a]) * layers[a].h.first % mod1 + mod1) % mod1;
        h.second = (h.second - ll(pw2[3 * a]) * layers[a].h.second % mod2 + mod2) % mod2;
    }
    void addLayer(int a)
    {
        h.first = (h.first + ll(pw1[3 * a]) * layers[a].h.first) % mod1;
        h.second = (h.second + ll(pw2[3 * a]) * layers[a].h.second) % mod2;
    }
    void moveLayer(int a)
    {
        while (a > 0 && layers[a].h < layers[a - 1].h) {
            removeLayer(a - 1);
            swap(layers[a], layers[a - 1]);
            addLayer(a);
            a--;
        }
        addLayer(a);
    }
    void Move(int a, int ind, int b, bool sid)
    {
        removeLayer(a);
        removeLayer(b);
        int x = layers[a].Take(ind);
        if (sid) layers[b].putSide(x);
        else layers[b].putMiddle(x);
        addLayer(b);
        if (layers[a].Final()) {
            layers[a] = layer();
            while (a + 1 < layers.size()) {
                removeLayer(a + 1);
                swap(layers[a], layers[a + 1]);
                addLayer(a);
                a++;
            }
            layers.pop_back();
        } else {
            if (!layers[a].val[0])
                layers[a].val[1] = 1;
            layers[a].Update();
            moveLayer(a);
        }
    }
};

int n;
map <ii, ld> M;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Print(node &G)
{
    for (int i = int(G.layers.size()) - 1; i >= 0; i--) {
        for (int j = 0; j < Maxd; j++)
            printf("%c", G.layers[i].val[j] > 0? cols[G.layers[i].val[j] - 1]: '.');
        printf("\n");
    }
}

ld Solve(node &G)
{
    int prv = int(G.layers.size()) - 2;
    if (prv > 0 && G.layers[prv].h < G.layers[prv - 1].h) {
        G.removeLayer(prv);
        G.moveLayer(prv);
    }
    auto it = M.find(G.h);
    if (it != M.end()) return it->second;
    int lim = int(G.layers.size()) - 1;
    if (G.layers.back().Full())
        G.layers.push_back(layer());
    int lst = int(G.layers.size()) - 1;
    ld best[4] = {Inf, Inf, Inf, Inf};
    node oldG;
    for (int i = 0; i < lim; i++) if (i == 0 || G.layers[i].h != G.layers[i - 1].h)
        for (int j = 0; j < Maxd; j++)
            if (G.layers[i].canTake(j) && 
                (j == 0 || j == 1 || (j == 2 && G.layers[i].val[0] != G.layers[i].val[2]))) {
                int col = G.layers[i].val[j];
                if (G.layers[lst].canPutSide()) {
                 //   printf("1) before\n");
                 //   Print(G);
                    oldG = G;
                    G.Move(i, j, lst, true);
                 //   printf("2) after\n");
                 //   Print(G);
                    best[col] = min(best[col], Solve(G));
                    G = oldG;
                }
                if (G.layers[lst].canPutMiddle()) {                
                //    printf("3) before (%d, %d, %d), col = %d\n", i, j, lst, col);
                //    Print(G);
                    oldG = G;
                    G.Move(i, j, lst, false);
                //    printf("4) after\n");
                //    Print(G);
                    best[col] = min(best[col], Solve(G));
                    G = oldG;
                }
        }
    if (lim != lst)
        G.layers.pop_back();
    int justtowait = 1;
    ld res = 0;
    if (best[1] >= Inf) justtowait++;
    else res += best[1];
    if (best[2] >= Inf) justtowait += 2;
    else res += 2 * best[2];
    if (best[3] >= Inf) justtowait += 2;
    else res += 2 * best[3];
   /* printf("oldG\n");
    Print(oldG);
    printf("G\n");
    Print(G);*/
  /*  Print(G);
    cout << "justtowait = " << justtowait << endl;
    cout << "res = " << res << endl;*/
    if (justtowait < 6)
        res = (6 + res) / (6 - justtowait);
    M.insert(make_pair(G.h, res));
    return res;
}

int main()
{
    arg1 = uniform_int_distribution<int>(1000000, 2000000)(rng);
    arg2 = uniform_int_distribution<int>(1000000, 2000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxm; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &n);
    node G;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        G.layers.push_back(layer(s));
        G.addLayer(i);
    }
    cout << fixed << setprecision(15) << Solve(G) << endl;
    return 0;
}