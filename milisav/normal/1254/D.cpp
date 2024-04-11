#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long step(long long a,long long b) {
    if(b==0) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
long long invs[500000];
long long n,q;
long long h;
long long t[500000];
long long pr[2000000];
long long pu[2000000];
vector<long long> a[500000];
long long s[500000];
long long d[500000];
long long par[500000];
long long tot;
void dfs(long long u,long long p) {
    s[u]=1;
    long long v;
    for(long long i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v!=p) {
            d[v]=d[u]+1;
            par[v]=u;
            dfs(v,u);
            s[u]+=s[v];
        }
    }
}
int nd[500000];
vector<pair<int,int> > qur[500000];
int tk[10000000];
inline void lca_ans(int u,int p) {
    int v;
    nd[d[u]]=u;
    for(int i=0;i<qur[u].size();i++) {
        tk[qur[u][i].second]=nd[qur[u][i].first];
    }
    qur[u].clear();
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v!=p) {
            lca_ans(v,u);
        }
    }
}
inline void prop(long long u,long long p) {
    long long v;
    t[u]=(t[u]+pu[u]+tot+(n-s[u])*pr[u]+mod);
    for(long long i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v!=p) {
            pu[v]+=pu[u];
            pu[v]=(pu[v]+pr[u]*(n-s[v])-(s[u]*pr[u])+mod);
            prop(v,u);
        }
    }
    pr[u]=pu[u]=0;
}
vector<pair<int,pair<long long,long long> > > ques;
int main() {
    long long g;
    scanf("%lld %lld",&n,&q);
    long long u,v;
    for(long long i=0;i<n-1;i++) {
        scanf("%lld %lld",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,-1);
    g=2000;
    h=g;
    invs[n]=inverse(n);
    while(q>0) {
        int k=0;
        while(h>0 && q>0) {
            long long x;
            scanf("%lld",&x);
            if(x==2) {
                scanf("%lld",&v);
                long long ans=t[v];
                for(auto tr:ques) {
                    if(tr.first==2) continue;
                    long long u=tr.second.first;
                    long long pv=tr.second.second;
                    long long c=d[u]+1;
                    if(u==v) {
                        ans=(ans+n*pv);
                    }
                    else {
                        if(c>d[v]) ans=(ans+s[u]*pv);
                        else {
                            qur[v].push_back({c,k++});
                        }
                    }
                }
                ques.push_back({2,{v,-1}});
            }
            else {
                scanf("%lld %lld",&u,&v);
                long long pv=v;
                tot=(tot+((pv*invs[n])%mod)*s[u])%mod;
                pr[u]=(pr[u]+pv*invs[n])%mod;
                ques.push_back({1,{u,(pv*invs[n])%mod}});
            }
            q--;
            h--;
        }
        k=0;
        lca_ans(1,-1);
        for(int i=0;i<ques.size();i++) {
            if(ques[i].first==2) {
                v=ques[i].second.first;
                long long ans=t[v];
                for(int j=0;j<i;j++) {
                    pair<int,pair<long long,long long> > tr=ques[j];
                    if(tr.first==2) continue;
                    long long u=tr.second.first;
                    long long pv=tr.second.second;
                    long long c=d[u]+1;
                    //cout<<v<<" "<<u<<endl;
                    if(u==v) {
                        ans=(ans+n*pv);
                    }
                    else {
                        if(c>d[v]) ans=(ans+s[u]*pv);
                        else {
                            long long w=tk[k];
                            k++;
                            if(par[w]==u) ans=(ans+(n-s[w])*pv);
                            else ans=(ans+s[u]*pv);
                        }
                    }
                }
                printf("%lld\n",(ans%mod+mod)%mod);
            }
        }
        prop(1,-1);
        tot=0;
        ques.clear();
        h=g;
    }
    return 0;
}