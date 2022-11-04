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
#define REPR(i, n) for (int i = (n - 1); i >= 0; --i)

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MAXN = 1000000;

namespace twosat {

int dfn[MAXN],low[MAXN],stack[MAXN], head[MAXN],next[MAXN],pot[MAXN],now[MAXN];
int opp[MAXN],pon[MAXN],bo[MAXN],thead[MAXN];
int indeg[MAXN],tnext[MAXN],tpot[MAXN],Q[MAXN];
bool instack[MAXN];
int tot,n,m,top,num,sign;

vector<int> adj[MAXN];

int head_backup[MAXN], tot_backup;

void save() {
    tot_backup = tot;
    REP(i, n + 1) head_backup[i] = head[i];
}

void restore() {
    tot = tot_backup;
    REP(i, n + 1) head[i] = head_backup[i];
}

int vis[MAXN];

void init(int size) {
    tot = 0;
    n = size * 2;
    REP(i, n + 1) head[i] = 0;

    for (int i=1;i<=n;i++) 
    if ((i&1)>0) 
        opp[i]=i+1; 
    else 
        opp[i]=i-1;
}

int rev(int x) {
    if (x & 1) return x + 1;
    return x - 1;
}

void do_connect(int a, int b) {
    pot[++tot]=b; next[tot]=head[a]; head[a]=tot;
}

void connect(int a,int b)
{
    do_connect(a, b);
    do_connect(rev(b), rev(a));
}
// 
void dfs(int v)
{
    dfn[v]=low[v]=++sign; stack[++top]=v; 
    instack[v]=true;
    for (int e=head[v];e!=0;e=next[e])
    {
        int u=pot[e];
        if ( dfn[u]==0 )
        {
            dfs(u);
            low[v]=min(low[v],low[u]);
        } else
        if (instack[u])
            low[v]=min(low[v],dfn[u]);
    }
    if (low[v]==dfn[v])
    {
        pon[++num] = v;    //
        while (stack[top+1]!=v)
        {
            int u=stack[top--];
            now[u]=num;
            instack[u]=false;
        }           
    }       
}

bool tsat() {
    sign=0; num=0; top=0; 
    REP(i, n + 1) dfn[i] = 0;
    for (int i=1;i<=n;i++) 
        if (dfn[i]==0) 
            dfs(i);
    for (int i=1;i<=n;i++) 
        if (now[i] == now[opp[i]]) 
            return false;   
    return true;
}

}

const int N = MAXN;

bool t[N];
int p1[N], t1[N], p2[N], t2[N];

char buf1[200], buf2[200];

int final_type[N];

string s;
int n, m;

bool go(int length) {
    twosat::restore();
    for (int i = 0; i < length; ++i) {
        if (final_type[i]) {
            twosat::connect(i * 2 + 2, i * 2 + 1);
        } else {
            twosat::connect(i * 2 + 1, i * 2 + 2);
        }
    }

    return twosat::tsat();
}

int main() {
    cin >> s;
    REP(i, s.size()) t[i] = (s[i] == 'V');
    int a_size = s.size();
    cin >> n >> m;
    REP(i, m) {
        scanf("%d%s%d%s", &p1[i], buf1, &p2[i], buf2);
        --p1[i];
        --p2[i];
        t1[i] = (buf1[0] == 'V');
        t2[i] = (buf2[0] == 'V');
    }

    twosat::init(n);
    for (int i = 0; i < m; ++i) {
        int delta1 = t1[i] ? 1 : 2;
        int delta2 = t2[i] ? 1 : 2;
        twosat::connect(p1[i] * 2 + delta1, p2[i] * 2 + delta2);
    }
    twosat::save();

    cin >> s;
    bool is_larger = false;
    string answer;
    for (int i = 0; i < n; ++i) {
        final_type[i] = t[s[i] - 'a'] ? 1 : 0;
    }

    for (int i = n - 1; i >= 0 && answer.size() == 0; --i) {
        int last_type = -1;
        int beg = s[i] - 'a';
        if (i != n - 1) {
            ++beg;
        }
        for (int j = beg; j < a_size; ++j) {
            int int_type = t[j] ? 1 : 0;
            if (last_type != int_type) {
                final_type[i] = int_type;
                if (go(i + 1)) {
                    answer = s.substr(0, i) + (char) (j + 'a');
                    break;
                }
                if (last_type != -1) {
                    break;
                }
                last_type = int_type;
            }
        }
    }
    // cout << "answer is " << answer << endl;
    if (answer.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = answer.size(); i < n; ++i) {
        int last_type = -1;
        int beg = 0;
        for (int j = beg; j < a_size; ++j) {
            int int_type = t[j] ? 1 : 0;
            if (last_type != int_type) {
                final_type[i] = int_type;
                if (go(i + 1)) {
                    answer += (char) (j + 'a');
                    break;
                }
                last_type = int_type;
            }
        }
    }
    if (answer.size() < n) {
        cout << -1 << endl;
        return 0;
    }
    cout << answer << endl;
    return 0;
}