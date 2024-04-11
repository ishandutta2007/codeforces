#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=9000000000000000000;
const int inf=2000000000;
int n, ans=inf;
LL arr[100010];
int bit[100010][70];
vector<int> link[100010];
pii que[100010];
int l, r;
int bfs(int u, int v){

    unordered_set<int> ch;
    l=r=0;
    que[++r]=mp(u, 0);
    while(l<r){
        pii t=que[++l];
        if(t.F==v)return t.S+1;
        if(ch.count(t.F))continue;
        ch.insert(t.F);
        for(auto i:link[t.F]){
            if(t.F==u&&i==v)continue;
            que[++r]=mp(i, t.S+1);
        }
    }
    return inf;
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
        LL temp=arr[i];
        int num=0;
        while(temp){
            bit[i][num++]=temp%2;
            temp/=2;
        }
    }
    for(int i=0; i<=65; i++){
        int num=0;
        for(int j=1; j<=n; j++){
            if(bit[j][i])num++;
        }
        if(num>=3){
            puts("3");
            return 0;
        }
    }
    for(int i=0; i<=65; i++){
        int temp=0;
        for(int j=1; j<=n; j++){
            if(bit[j][i]&&temp){
                link[temp].pb(j);
                link[j].pb(temp);
            }
            else if(bit[j][i])temp=j;
        }
    }
    for(int i=1; i<=n; i++){
        sort(all(link[i]));
        link[i].erase(unique(all(link[i])), link[i].end());
    }
    for(int i=1; i<=n; i++){
        for(auto j:link[i]){
            ans=min(ans, bfs(i, j));
        }
    }
    printf("%d", ans==inf?-1:ans);
}