#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;	
using namespace std;

ll cur;
set<pair<int, int> > ss;

void init(ll n, ll m) 
{
    cur = n * m;
    ss.insert(make_pair(0, m));
    ss.insert(make_pair(n, 0));
}

void add(int x, int y) 
{
    auto it = ss.lower_bound(make_pair(x + 1, 0));
    it --;
    if (it -> second <= y)
        return;
    ll crl = it -> second;
    ll pr = x;
    if (it -> first < x) it ++;
    while (it != ss.end() && it -> second >= y) 
    {
        cur -= (it -> first - pr) * (crl - y);
        pr = it -> first;
        crl = it -> second;
        ss.erase(it ++);
    }
    if (it != ss.end()) 
        cur -= (it -> first - pr) * (crl - y);
    ss.insert(make_pair(x, y));
}

int n, p, q, r;

vector<pair<int, int> > go[510000];

int main() 
{
    scanf("%d%d%d%d", &n, &p, &q, &r);
    init(q, r);
	for (int i = 0; i < n; i ++) 
	{
	    int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b, --c;
        b = q - 1 - b;
        c = r - 1 - c;
        add(b, c);
        go[a].push_back(make_pair(b, c));
    }
    ll ans = 0;
    for (int i = p - 1; i >= 0; i --) 
    {
        for (auto e: go[i]) 
        {
            add(e.first, 0);
            add(0, e.second);
        }
        ans += cur;
    }
    cout << ans << "\n";
    return 0;
}