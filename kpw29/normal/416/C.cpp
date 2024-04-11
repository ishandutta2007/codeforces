#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define e2 second
#define maxn 1010
#define e1 first
const int inf = 2e9;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
int n,a,b,c,m;
char s[1000100];
int t[maxn];
vector <int> stolik[maxn];
int hajs[maxn];
vector <BONG> oczekujace[maxn];
priority_queue <BONG> q;
typedef unsigned int ui;
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        int kasa, ile;
        scanf("%d%d", &ile, &kasa);
        oczekujace[ile].push_back(mp(kasa, i));
    }
    scanf("%d", &m);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d", &a);
        stolik[a].push_back(i);
    }
    
    vector <BONG> wyn;
    wyn.clear();
    int HAJS  =0;
    for (int i=1; i<maxn; ++i)
    {
        for (ui j=0; j<oczekujace[i].size(); ++j) q.push(oczekujace[i][j]);
        for (ui j=0; j<stolik[i].size(); ++j)
        {
            if (q.empty()) continue;
            BONG tp = q.top();
            q.pop();
            HAJS += tp.first;
            wyn.push_back(mp(tp.second, stolik[i][j]));
        }
    }
    printf("%d %d\n", wyn.size(), HAJS);
    for (int i=0; i<wyn.size(); ++i) printf("%d %d\n", wyn[i].e1, wyn[i].e2);
    
}