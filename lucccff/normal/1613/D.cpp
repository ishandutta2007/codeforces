#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[500010];
int b[500010],c[500010],d[500010],f[500010];
int p[500010];
pair <int,int> q[500010];
vector <int> e[500010];

void init(int l) {
    for(int i=1;i<=l;i++) {
        p[i]=0;
    }
}

void add(int x,int l,int k) {
    while(x<=l) {
        p[x]+=k;
        if (p[x]>=MOD) p[x]-=MOD;
        x+=x&(-x);
    }
}

int gets(int x) {
    int ans=0;
    while(x>=1) {
        ans+=p[x];
        if (ans>=MOD) ans-=MOD;
        x-=x&(-x);
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,l,m,t,k1,k,n;
    cin>>t;
    while(t--) {
        cin>>n;
        init(n);
        for(i=0;i<=n;i++) e[i].clear();
        for(i=1;i<=n;i++) {
            cin>>a[i];
            e[a[i]].push_back(i);
            b[i]=c[i]=d[i]=0;
        }
        add(1,n,1);
        for(j=0;j<e[1].size();j++) {
            c[e[1][j]]=gets(e[1][j]);
            add(e[1][j],n,c[e[1][j]]);
        }
        for(j=0;j<e[1].size();j++) {
            add(e[1][j],n,MOD-c[e[1][j]]);
        }
        for(i=0;i<=n;i++) {
            if (i<=n-2) {
                for(j=0;j<e[i+2].size();j++) {
                    f[e[i+2][j]]=gets(e[i+2][j]);
                }
            }
            for(j=0;j<e[i].size();j++) {
                b[e[i][j]]=gets(e[i][j]);
                add(e[i][j],n,b[e[i][j]]);
            }
            k=0;
            if (i<=n-2) {
                m=0;
                for(j=0;j<e[i].size();j++) {
                    q[m++]=make_pair(e[i][j],i);
                }
                for(j=0;j<e[i+2].size();j++) {
                    q[m++]=make_pair(e[i+2][j],i+2);
                }
                sort(q,q+m);
                for(j=0;j<m;j++) {
                    if (q[j].second==i) {
                        d[q[j].first]=gets(q[j].first)-2*b[q[j].first];
                        if (d[q[j].first]<0) d[q[j].first]+=MOD;
                        if (d[q[j].first]<0) d[q[j].first]+=MOD;
                        add(q[j].first,n,d[q[j].first]);
                    }
                    else {
                        c[q[j].first]=gets(q[j].first)-f[q[j].first];
                        if (c[q[j].first]<0) c[q[j].first]+=MOD;
                        add(q[j].first,n,c[q[j].first]);
                    }
                }
                for(j=0;j<m;j++) {
                    if (q[j].second==i) {
                        add(q[j].first,n,MOD-d[q[j].first]);
                    }
                    else {
                        add(q[j].first,n,MOD-c[q[j].first]);
                    }
                }
            }
            if (i==0) add(1,n,MOD-1);
            if (i>0) {
                for(j=0;j<e[i-1].size();j++) {
                    add(e[i-1][j],n,MOD-b[e[i-1][j]]);
                }
            }
        }
        int ans=0;
        for(i=1;i<=n;i++) {
            ans+=b[i];
            if (ans>=MOD) ans-=MOD;
            ans+=c[i];
            if (ans>=MOD) ans-=MOD;
            ans+=d[i];
            if (ans>=MOD) ans-=MOD;
        }
        cout<<ans%MOD<<endl;
    }
    return 0;
}