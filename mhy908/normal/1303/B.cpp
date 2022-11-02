#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t;
LL n, g, b;
int main(){
    scanf("%d", &t);
    for(int u=1; u<=t; u++){
        scanf("%lld %lld %lld", &n, &g, &b);
        LL good=(n+1)/2, bad=n-(n+1)/2;
        LL ans=0;
        if(good%g){
            ans+=good/g*(g+b)+good%g;
            bad-=good/g*b;
            ans+=max(0ll, bad);
        }
        else{
            ans+=good/g*(g+b)-b;
            bad-=good/g*b-b;
            ans+=max(0ll, bad);
        }
        printf("%lld\n", ans);
    }
}