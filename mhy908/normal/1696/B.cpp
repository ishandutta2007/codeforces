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

void solve(){
    scanf("%d", &n);
    int ans=0;
    bool flg=false;
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d", &a);
        if(a==0&&flg){
            ans++;
            flg=false;
        }
        if(a)flg=true;
    }
    if(flg)ans++;
    printf("%d\n", min(ans, 2));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}