#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e5+9;
int n,id[N],c[N],l[N],r[N],b[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}
void unite(int u,int v) {id[find(u)]=find(v);}
vi st[N],ed[N];
set<int>s[2];

signed main() {
    int T=read();
    while(T--) {
        n=read();
        rep(i,1,n) id[i]=i; s[0].clear(), s[1].clear();
        rep(i,1,2*n) st[i].clear(), st[i].shrink_to_fit(), ed[i].clear(), ed[i].shrink_to_fit();
        rep(i,1,n) c[i]=read(), l[i]=read(), r[i]=read();
        int tot=0;
        rep(i,1,n) b[++tot]=l[i], b[++tot]=r[i];
        sort(b+1,b+tot+1);
        int cc=unique(b+1,b+tot+1)-b-1;
        rep(i,1,n) l[i]=lower_bound(b+1,b+cc+1,l[i])-b;
        rep(i,1,n) r[i]=lower_bound(b+1,b+cc+1,r[i])-b;
        rep(i,1,n) st[l[i]].emplace_back(i);
        rep(i,1,n) ed[r[i]].emplace_back(i);
        rep(i,1,cc) {
            //cout<<i<<endl;
            for(auto v:st[i]) {
                //cout<<"IN "<<v<<endl;
                int x=c[v],y=c[v]^1, rem=-1;
                for(auto p:s[y]) {
                    unite(v,p);
                    //cout<<"ADD "<<v<<" "<<p<<endl;
                    if(rem==-1||r[p]>r[rem]) rem=p;
                }
                if(s[y].size()>1) s[y].clear(), s[y].insert(rem);
                s[x].insert(v);
            }
            for(auto v:ed[i]) {
                //cout<<"OUT "<<v<<endl;
                int x=c[v];
                if(s[x].find(v)!=s[x].end()) s[x].erase(s[x].find(v));
            }
        }
        int ans=0;
        rep(i,1,n) if(find(i)==i) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}