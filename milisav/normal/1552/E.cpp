#include<bits/stdc++.h>
#define maxn 50000
using namespace std;
int n,k;
int c[maxn];
int tot[maxn];
int pv[maxn];
int a[maxn];
int b[maxn];
bool us[maxn];
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n*k;i++) {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n*k;i++) {
        tot[c[i]]++;
        if(tot[c[i]]>=2 && !us[c[i]]) {
            int s=(c[i]-1)/(k-1);
            int l=s*(k-1)+1;
            int r=min(n,l+k-2);
            for(int j=l;j<=r;j++) tot[j]=0;
            us[c[i]]=true;
            a[c[i]]=pv[c[i]];
            b[c[i]]=i;
        }
        pv[c[i]]=i;
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
    return 0;
}