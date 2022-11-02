#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define inf 987654321
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int dig[100010][70];
int cnt[110], ans=inf;
vector<int> wha[70];
vector<int> link[100010];
bool ch[100010];
int cyc=inf, n;
void dfs(int num, int d, int par, int st)
{
    if(ch[num])return;
    ch[num]=true;
    for(int i=0; i<link[num].size(); i++){
        if(link[num][i]==par)continue;
        dfs(link[num][i], d+1, num, st);
        if(link[num][i]==st)cyc=min(cyc, d+1);
    }
    ch[num]=false;
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        LL temp;
        scanf("%llu", &temp);
        for(int j=0; ; j++){
            dig[i][j]=(int)(temp%2);
            if(dig[i][j]){
                cnt[j]++;
                wha[j].pb(i);
            }
            temp/=2;
            if(!temp)break;
        }
    }
    for(int i=0; i<=66; i++){
        if(cnt[i]<=2)continue;
        ans=3;
        break;
    }
    if(ans==3){
        printf("3");
        return 0;
    }
    for(int i=0; i<=66; i++){
        if(cnt[i]!=2)continue;
        link[wha[i][0]].pb(wha[i][1]);
        link[wha[i][1]].pb(wha[i][0]);
    }
    for(int i=1; i<=n; i++){
        if(link[i].size()<=1)continue;
        memset(ch, 0, sizeof(ch));
        cyc=inf;
        dfs(i, 0, 0, i);
        ans=min(cyc, ans);
    }
    printf("%d", ans<inf-100?ans:-1);
}