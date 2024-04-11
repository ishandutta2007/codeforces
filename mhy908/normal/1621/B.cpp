#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n;
pll l, r;

void solve(){
    scanf("%d", &n);
    l=mp(LLINF, 0);
    r=mp(-LLINF, 0);
    map<pll, LL> ch;
    for(int i=1; i<=n; i++){
        LL a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        l=min(l, mp(a, c));
        r=max(r, mp(b, -c));
        if(!ch[mp(a, b)])ch[mp(a, b)]=LLINF;
        ch[mp(a, b)]=min(ch[mp(a, b)], c);
        printf("%lld\n", min(l.S-r.S, ch[mp(l.F, r.F)]?ch[mp(l.F, r.F)]:LLINF));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}