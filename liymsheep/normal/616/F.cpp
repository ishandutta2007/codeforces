#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;


using namespace std;

const int MAXN = 1500007;

struct SAM
{
    struct Node
    {
        int suf, ch[26];
        int maxi, dan;
        Node() : suf(-1), maxi(0), dan(0)
        {
            memset(ch, -1, sizeof(ch));
        }
    };

    SAM()
    {
        init();
    }

    void init()
    {
        total = 1;
        tree[0] = Node();
        root = last = 0;
    }

    int extend(int w, int rear = -1)
    {
     //   cout << "extend("<<w<<","<<rear<<");\n";
        int p = (rear == -1 ? last : rear);
        int np = total++;
        tree[np].maxi = tree[p].maxi + 1;
        tree[np].dan = 1;
        while (-1 != p && -1 == tree[p].ch[w])
            tree[p].ch[w] = np, p = tree[p].suf;
        if (-1 == p)
            tree[np].suf = root;
        else
        {
            int q = tree[p].ch[w];
            if (tree[p].maxi+1 == tree[q].maxi)
                tree[np].suf = q;
            else
            {
                int nq = total++;
                memcpy(tree[nq].ch, tree[q].ch, sizeof(tree[q].ch));
                tree[nq].maxi = tree[p].maxi + 1;
                tree[nq].suf = tree[q].suf;
                tree[q].suf = nq;
                tree[np].suf = nq;
                while (p != -1 && tree[p].ch[w] == q)
                    tree[p].ch[w] = nq, p = tree[p].suf;
            }
        }
        last = np;
        return last;
    }
    int root, last;
    Node tree[MAXN];
    int total;

    //extend
    vector<int> to[MAXN];

    LL answer;

    void dp()
    {
        REP(i, total) {
            if (tree[i].suf >= 0) {
                to[tree[i].suf].PB(i);
            }
        }
        answer = 0;
        dfs(root);
    }

    LL sum[MAXN];

    void dfs(int node) {
        TR(it, to[node]) {
            dfs(*it);
            sum[node] += sum[*it];
        }

        if (node != root) {
            answer = max(answer, tree[node].maxi * sum[node]);
        }
    }
};

int where[MAXN];
int ch[MAXN][26];

int last;

int nextNode() {
    FILL(ch[last], -1);
    return last++;
}

int append(const char* c, int len) {
    int cur = 0;
    REP(i, len) {
        int nc = c[i] - 'a';
        if (ch[cur][nc] < 0) {
            ch[cur][nc] = nextNode();
        }
        cur = ch[cur][nc];
    }
    return cur;
}

char c[2000007];
SAM* sam;
int n, m;

void go()
{
    //cout << "u = " << u << " ch = " << c[u] << " have = " << have << endl;
    queue<int> Q;
    Q.push(0);

    where[0] = sam->root;
    while (Q.size())
    {
        int u = Q.front();
        Q.pop();

        REP(i, 26)
            if (ch[u][i] >= 0) {
                int nc = ch[u][i];
                where[nc] = sam->extend(i, where[u]);
                Q.push(nc);
            }
    }
}

int cost[MAXN];
char buf[MAXN];

int main() {
    cin >> n;
    vector<string> s;

    last = 0;
    nextNode(); // root
    REP(i, n) {
        scanf("%s", buf);
        append(buf, strlen(buf));
        s.PB(string(buf));
    }

    REP(i, n) scanf("%d", &cost[i]);

    sam = new SAM();
    go();

    REP(i, n) {
        int cur = 0;
        REP(j, s[i].size()) {
            int nc = s[i][j] - 'a';
            cur = ch[cur][nc];
            sam->sum[where[cur]] += cost[i];
        }
    }

    sam->dp();

    cout << sam->answer << endl;

    return 0;
}