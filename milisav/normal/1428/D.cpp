#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int a[maxn];
int oo[maxn];
vector<int> tg[maxn];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) oo[i]=i;
    int nk=1;
    int nb=1;
    for(int i=1;i<=n;i++) {
        if(a[i]==0) continue;
        if(a[i]==1) {
            if(tg[i].size()>0) continue;
            else tg[i].push_back(oo[i]);
        }
        if(a[i]==2) {
            while(nk<=i) nk++;
            while(nk<=n && a[nk]!=1) nk++;
            if(nk>n) {
                printf("-1");
                return 0;
            }
            if(tg[i].size()==0) tg[i].push_back(oo[i]);
            oo[nk]=oo[i];
            tg[nk].push_back(oo[nk]);
            nk++;
        }
        if(a[i]==3) {
            while(nb<=i) nb++;
            while(nb<=n && (a[nb]!=3 && a[nb]!=2 && (a[nb]!=1 || tg[nb].size()>0))) nb++;
            if(nb>n) {
                printf("-1");
                return 0;
            }
            if(tg[i].size()==0) tg[i].push_back(oo[i]);
            tg[nb].push_back(oo[i]);
            tg[nb].push_back(oo[nb]);
            nb++;
        }
    }
    int t=0;
    for(int i=1;i<=n;i++) t+=tg[i].size();
    printf("%d\n",t);
    for(int i=1;i<=n;i++) {
        for(auto j:tg[i]) printf("%d %d\n",j,i);
    }
    return 0;
}