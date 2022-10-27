#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 701212
#endif
const int maxn = 3e5+10;
int n, pa[maxn];
vector<pair<int,int>> a[maxn];
vector<int> cyc;
bool incyc[maxn],vis[maxn];
long long dep[maxn],r[maxn],l[maxn],ll[maxn],rr[maxn];
vector<int> w;
void fcycle(int nod,int P){
    pa[nod] = P;
    vis[nod] =true;
    for(auto i:a[nod]){
        if(!vis[i.first] && i.first!= P){
            fcycle(i.first,nod);
        }
        else if(cyc.empty() && i.first != P ){
            int x=nod;
            cyc.push_back(i.first);
            incyc[i.first] = true;
            while(x != i.first){
                for(auto j:a[cyc.back()]){
                    if(j.first == x)
                        w.push_back(j.second);
                }
                cyc.push_back(x);
                incyc[x] = true;
                x = pa[x];
            }
            for(auto j:a[cyc.back()])
                if(j.first == cyc[0])
                    w.push_back(j.second);
        }
    }
    return ;
}
///find depth of each tree
long long fdep(int nod,int P){
    long long cur = 0;
    for(auto i:a[nod]){
        if(i.first != P && !incyc[i.first]){
            cur = max(cur,i.second + fdep(i.first, nod));
        }
    }
    return cur;
}
pair<int,int> ban[2];
long long ans;
long long dfs(int nod,int P){
    long long cur = 0;
    for(auto i:a[nod]){
        if(i.first != P){
            auto mp = make_pair(i.first,nod);
            eprintf("%d %d\n",mp.first, mp.second);
            if(mp != ban[0] && mp != ban[1]){
                auto s = dfs(i.first, nod);
                ans = max(ans,s+i.second);
                ans = max(ans,cur + s + i.second);
                eprintf("In dfs at %d %d\n",nod, P);
                eprintf("%lld %lld %d\n",cur,s ,i.second);
                cur = max(cur, s + i.second);
            }
        }
    }
    return cur;
}
 
int main(){
    int u,v,ww;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&u,&v,&ww);
        a[u].push_back({v,ww});
        a[v].push_back({u,ww});
    }
    fcycle(1,0);
    ///enumerate
    assert(!cyc.empty());
    eprintf("%d\n",(int)cyc.size());
    for(int i:cyc){
        eprintf("%d ",i);
    }
    eprintf("\n");
    for(int i:w){
        eprintf("%d ",i);
    }
    eprintf("\n");
    int sz= cyc.size();
    for(int i=0 ;i<sz;i++){
        dep[i] = fdep(cyc[i],0);
    }
    ///do 1 first
    long long track = dep[0];
    r[0]=track;
    track = 0;
    ///we can classify path into two types
    ///1. Path pass through edge between 1,n
    ///2. not pass
    ///1. -> we can easily compute the maximum of left and right
    ///Pre compute maximum dep
    for(int i=1;i<sz;i++){
        r[i]= track + w[i-1] + dep[i];
        r[i] = max(r[i],r[i-1]);
        track += w[i-1];
    }
    eprintf("? maximum from 1 to x:\n");
    for(int i= 0 ;i<sz;i++)
        eprintf("%lld ",r[i]);
    eprintf("\n");
    l[sz-1]=dep[sz-1];
    track = 0;
    for(int i=sz-2;i>= 0 ;i--){
        l[i] = max(l[i+1],track + w[i] + dep[i]);
        track += w[i];
    }
    eprintf("? maximum from sz to 1:\n");
    for(int i=0;i<sz;i++)
        eprintf("%lld ",l[i]);
    eprintf("\n");
    track =dep[0];
    rr[0] = dep[0];
    for(int i=1;i<sz;i++){
        rr[i] = max(rr[i-1],track + w[i-1]+dep[i]);
        if(dep[i] > track+w[i-1])
            track =dep[i];
        else
            track += w[i-1];
    }
    eprintf("? maximum not necessary start at 1:\n");
    for(int i =0;i<sz;i++ )
        eprintf("%lld ",rr[i]);
    eprintf("\n");
    ll[sz-1] = dep[sz-1];
    track = dep[sz-1];
 
    for(int i= sz-2;i>=0;i--){
        ll[i] = max(ll[i+1],track + w[i]+dep[i]);
        if(dep[i]> track +w[i])
            track = dep[i];
        else
            track += w[i];
    }
    eprintf("? maximum not necessary start at n:\n");
    for(int i=0;i<sz;i++){
        eprintf("%lld ",ll[i]);
    }
    eprintf("\n");
 
    ///just hope to be correct
 
    /// check edge
    int best_edge = -1;
    long long cur = 0;
    const long long inf = 1e16;
    track = inf;
    ll[sz]=(-inf);
    rr[sz]=(-inf);
    l[sz]=(-inf);
    r[sz]=(-inf);
    for(int i=0;i< sz;i++){
        cur = max({r[i]+l[i+1] + w[sz-1], rr[i],ll[i+1]});
        eprintf("edge %d :%lld\n",i,cur);
        if(cur < track){
            track = cur;
            best_edge = i;
        }
    }
    eprintf("Deleted edge?\n");
    assert(best_edge != -1);
    eprintf("%d %lld\n",best_edge, track);
    ban[0] = (best_edge == sz-1) ? make_pair(cyc[sz-1],cyc[0]) : make_pair(cyc[best_edge],cyc[best_edge+1]);
    ban[1] = make_pair(ban[0].second,ban[0].first);
    eprintf("%d %d\n",ban[0].first , ban[0].second);
    eprintf("Finally answer ??\n");
    dfs(1,0);
    printf("%lld\n",ans);
}