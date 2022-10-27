#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define all(x) x.begin(),x.end()
#define Unique(x)  sort(all(x)),x.erase(unique(all(x)),x.end())
int n,m,a[maxn],b[maxn],c[maxn],ma;
long long sum;
map<int,int> f;
map<int,int> q;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=(1ll*a[i]*m);
        ma=max(ma,a[i]);
        f[a[i]]+=(m-1);
        q[a[i]]++;
        }
        vector<int> g;
        for(int i=1;i<=n;i++)
            g.push_back(a[i]);
        Unique(g);
        int pt=g.size();
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        }
        sort(b+1,b+1+m);
    for(int i=m;i>=1;i--){
        if(b[i]<ma){
            printf("-1");
            return 0;
        }
        if(q.count(b[i])){
            q[b[i]]--;
            if(q[b[i]]==0){
                q.erase(q.find(b[i]));
            }
            continue;
        }
        if(f.count(g[pt-1])){
            sum+=(b[i]-g[pt-1]);
            f[g[pt-1]]--;
            if(f[g[pt-1]]==0){
                f.erase(f.find(g[pt-1]));
                pt--;
            }
        }
        }
    printf("%lld\n",sum);
}