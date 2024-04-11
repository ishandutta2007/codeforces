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
int n;
vector<pii> link[100010];
bool flag=true;
int num, ans[100010];
int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        link[a].pb(mp(b, i));
        link[b].pb(mp(a, i));
    }
    for(int i=1; i<=n; i++){
        if(link[i].size()>=3){
            flag=false;
            num=i;
        }
    }
    if(flag){
        for(int i=1; i<n; i++)printf("%d\n", i-1);
        return 0;
    }
    for(int i=0; i<3; i++){
        ans[link[num][i].S]=i+1;
    }
    int temp=3;
    for(int i=1; i<n; i++){
        if(!ans[i])ans[i]=++temp;
        printf("%d\n", ans[i]-1);
    }
}