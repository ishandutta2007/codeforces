#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 50000000001LL;
const int Maxn = 50005;

string s;
priority_queue <pair <ll, int> > Q;
bool has[Maxn];
int nxt[Maxn];
ll res;

bool getOnes(int v, int col)
{
     if (col == 2) return true;
     if (v == 0) return false;
     if (has[nxt[v]]) return getOnes(nxt[v], col + 1);
     bool res = getOnes(nxt[v], col);
     if (res) nxt[v] = nxt[nxt[v]];
     return res;
}

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        ll a, b;
        if (s[i] == '(') { a = 0; b = Inf; }
        else if (s[i] == ')') { a = Inf; b = 0; }
        else cin >> a >> b;
        res += a;
        Q.push(make_pair(a - b, i));
        s[i] = '('; has[i] = true;
        nxt[i + 1] = i;
    }
    for (int i = 0; i < s.length() / 2; i++) {
        pair <ll, int> v;
        while (!Q.empty()) {
              v = Q.top(); Q.pop();
              if (getOnes(v.second + 1, 0)) break; 
        }
        res -= v.first;
        s[v.second] = ')';
        has[nxt[nxt[v.second + 1]]] = has[nxt[v.second + 1]] = false;
    }
    if (res >= Inf) cout << "-1\n";
    else cout << res << endl << s << endl;
    return 0;
}