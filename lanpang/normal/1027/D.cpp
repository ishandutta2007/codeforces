#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double pi = acos(-1.0);
const int maxn = 2e5+38;
const int mod = 1e9+7;

int n;
int a[maxn],c[maxn];
int v[maxn];
vector<int>huan[maxn];
int ok ;
void dfs(int x,int col){
    v[x] = col;
    if(v[a[x]]==col){
        huan[col].push_back(a[x]);
        ok = 1;
    }
    else if(v[a[x]]==0){
        dfs(a[x],col);
    }
    else if(v[a[x]]<0){
        return;
    }
    if(ok==1){
        if(x!=huan[col][0]) huan[col].push_back(x);
        else ok = 0;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(v[i]==0){
            ok = 0;
            dfs(i,++cnt);
        }
    int ans = 0;
    for(int i=1;i<=cnt;i++)
        if(huan[i].size()>0){
            int m = 10000;
            //printf("!! ");
            for(int j=0;j<huan[i].size();j++){
               // printf("%d ",huan[i][j]);
                m = min(m,c[huan[i][j]]);
            }//cout<<endl;
            ans += m;
        }
    printf("%d",ans);
}