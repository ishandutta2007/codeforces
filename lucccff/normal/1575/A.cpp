#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

char a[1000010];
int b[1000010],c[1000010];
vector <int> e[26];

int main() {
    int i,j,k,l,m,n,t;
    cin>>n>>m;
    for(i=0;i<n;i++) {
        b[i]=i;
        c[i]=0;
        getchar();
        for(j=0;j<m;j++) {
            a[i*m+j]=getchar()-'A';
            if (j&1) {
                a[i*m+j]=25-a[i*m+j];
            }
        }
    }
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            for(k=0;k<26;k++) e[k].clear();
            k=j;
            while(k<n&&c[k++]==0);
            for(l=j;l<k;l++) {
                e[a[b[l]*m+i]].push_back(b[l]);
            }
            k=j;
            for(l=0;l<26;l++) {
                for(t=0;t<e[l].size();t++) {
                    b[k++]=e[l][t];
                }
                c[k-1]=1;
            }
            j=k-1;
        }
    }
    for(i=0;i<n;i++) {
        printf("%d ",b[i]+1);
    }
    return 0;
}