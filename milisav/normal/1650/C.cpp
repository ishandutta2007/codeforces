#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n,m;
long long w[maxn];
int x[maxn];
pair<int,int> val[maxn];
vector<pair<int,int> > ok;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++) {
            scanf("%d %lld",&x[i],&w[i]);
            val[i]={w[i],i};
        }
        sort(val,val+m);
        long long sum=0;
        for(int i=0;i<2*n;i++) {
            sum+=val[i].first;
            ok.push_back({x[val[i].second],val[i].second+1});
        }
        sort(ok.begin(),ok.end());
        printf("%lld\n",sum);
        for(int i=0;i<n;i++) {
            printf("%d %d\n",ok[i].second,ok[2*n-1-i].second);
        }
        ok.clear();
    }
    return 0;
}