#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;
typedef pair <ii, int> iii;

const int Maxn = 400005;
const int Maxl = 1000005;

int m;
map <string, int> ID;
string rstr[Maxn];
int txt[Maxn];
int n;
vector <int> neigh[Maxn];
ii dist[Maxn];
priority_queue <iii> Q;
char tmp[Maxl];
ll res1, res2;

int GetID(string s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    if (ID.find(s) == ID.end()) {
        int cur = ID.size();
        ID[s] = cur;
        rstr[cur] = s;
        return cur;
    } else return ID[s];
}

int getString()
{
    scanf("%s", tmp);
    return GetID(tmp);
}

ii getCost(const string &s)
{
    int rs = 0;
    for (int i = 0; i < s.length(); i++)
        rs += s[i] == 'r';
    return ii(rs, s.length());
}

ii Neg(ii p) { return ii(-p.first, -p.second); }

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        txt[i] = getString();
    scanf("%d", &n);
    while (n--) {
        int a = getString();
        int b = getString();
        neigh[b].push_back(a);
    }
    for (int i = 0; i < ID.size(); i++) {
        dist[i] = getCost(rstr[i]);
        Q.push(iii(Neg(dist[i]), i));
    }
    while (!Q.empty()) {
        int v = Q.top().second;
        ii d = Neg(Q.top().first); Q.pop();
        if (d != dist[v]) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (d < dist[u]) { dist[u] = d; Q.push(iii(Neg(dist[u]), u)); }
        }
    }
    for (int i = 0; i < m; i++) {
        res1 += dist[txt[i]].first;
        res2 += dist[txt[i]].second;
    }
    printf("%I64d %I64d\n", res1, res2);
    return 0;
}