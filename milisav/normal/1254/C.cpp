#include<bits/stdc++.h>
using namespace std;
int n;
int s=1,p,q;
long long r;
int t;
pair<int,pair<long long,int> > ar[5000];
int main() {
    scanf("%d",&n);
    p=2;
    for(int i=3;i<=n;i++) {
        printf("2 %d %d %d\n",s,p,i);
        fflush(stdout);
        int o;
        scanf("%d",&o);
        if(o<0) p=i;
    }
    ar[1]={-5,{-1,1}};
    ar[p]={-5,{-1,p}};
    q=-1;
    for(int i=2;i<=n;i++) {
        if(i!=p) {
            printf("1 %d %d %d\n",s,p,i);
            fflush(stdout);
            long long surf;
            scanf("%lld",&surf);
            if(q==-1 || surf>r) {
                q=i;
                r=surf;
            }
            ar[i]={0,{surf,i}};
        }
    }
    for(int i=2;i<=n;i++) {
        if(i!=p && i!=q) {
            long long surf;
            surf=ar[i].second.first;
            printf("2 %d %d %d\n",s,q,i);
            fflush(stdout);
            int o;
            scanf("%d",&o);
            ar[i].first=o;
            ar[i].second.first=-o*surf;
        }
    }
    sort(ar+1,ar+n+1);
    printf("0 ");
    for(int i=1;i<n;i++) printf("%d ",ar[i].second.second);
    printf("%d\n",ar[n].second.second);
    fflush(stdout);
    return 0;
}