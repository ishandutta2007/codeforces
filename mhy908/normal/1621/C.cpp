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

int n, ans[10010];

int ask(int x){
    printf("? %d\n", x);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

void func(int x){
    while(1){
        if(ask(x)==x)break;
    }
    vector<int> vc;
    while(1){
        int tmp=ask(x);
        vc.eb(tmp);
        if(tmp==x)break;
    }
    ans[x]=vc[0];
    if(vc.size()>1){
        for(int i=1; i<vc.size(); i++)ans[vc[i-1]]=vc[i];
    }
}

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(ans[i])continue;
        func(i);
    }
    printf("! ");
    for(int i=1; i<=n; i++)printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    for(int i=1; i<=n; i++)ans[i]=0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}