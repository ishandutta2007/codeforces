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

int n, m, k;
int arr[50010], tar[50010];

pil gen(int num){
    if(num%m)return mp(num, 1ll);
    pil ans=gen(num/m);
    ans.S*=(LL)m;
    return ans;
}

void solve(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)scanf("%d", &arr[i]);
    scanf("%d", &k);
    for(int i=1; i<=k; i++)scanf("%d", &tar[i]);
    vector<pil> vc1, vc2;
    vc1.eb(gen(arr[1]));
    for(int i=2; i<=n; i++){
        pil tmp=gen(arr[i]);
        if(vc1[vc1.size()-1].F==tmp.F)vc1[vc1.size()-1].S+=tmp.S;
        else vc1.eb(tmp);
    }
    vc2.eb(gen(tar[1]));
    for(int i=2; i<=k; i++){
        pil tmp=gen(tar[i]);
        if(vc2[vc2.size()-1].F==tmp.F)vc2[vc2.size()-1].S+=tmp.S;
        else vc2.eb(tmp);
    }
    if(vc1.size()!=vc2.size()){
        puts("No");
        return;
    }
    for(int i=0; i<vc1.size(); i++){
        if(vc1[i]!=vc2[i]){
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}