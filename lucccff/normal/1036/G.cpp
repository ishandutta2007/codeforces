#include <bits/stdc++.h>
using namespace std;

int n,a[1000010],b[1000010],s[30],t[30],x,c[1000010],d[1000010],ma[30][30],p[30];
vector <int> ine[1000010],oute[1000010];

void dfs(int k) {
    c[k]=1;
    for(int i=0;i<a[k];i++) {
        if (c[oute[k][i]]==0) {
            dfs(oute[k][i]);
        }
    }
}

int main(){
    int i,j,k,l,m;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<m;i++) {
        cin>>k>>l;
        a[k]++;
        b[l]++;
        oute[k].push_back(l);
        ine[l].push_back(k);
    }
    k=0;
    l=0;
    for(i=1;i<=n;i++) {
        if (a[i]==0) t[k++]=i;
        if (b[i]==0) s[l++]=i;
    }
    x=k;

    memset(c,0,sizeof(c));
    for(i=0;i<x;i++) {
        memset(c,0,sizeof(c));
        dfs(s[i]);
        for(j=0;j<x;j++) {
            ma[i][j]=c[t[j]];
        }
        for(j=1;j<=n;j++) {
            d[j]+=c[j];
        }
    }
    for(i=1;i<=n;i++) {
        if (d[i]==0) {
            cout<<"NO";
            return 0;
        }
    }

    int q=1<<x;
    for(i=1;i<q-1;i++) {
        memset(p,0,sizeof(p));
        m=i;
        l=0;
        for(j=0;j<x;j++) {
            if (m&1) {
                for(k=0;k<x;k++) {
                    if (ma[k][j]==1) p[k]=1;
                }
                l++;
            }
            m>>=1;
        }
        for(j=0;j<x;j++) l-=p[j];
        if (l==0) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}