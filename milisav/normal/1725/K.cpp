#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
set<int> st[4*maxn];
int hs[4*maxn];
int h[maxn];
int sn[maxn];
int n;
set<pair<int,int> > s;
map<int,int> mp;
int q;
void mrg(int* i,int j) {
    int vi=(*i);
    if(st[(*i)].size()>st[j].size()) {
        for(auto val:st[j]) {
            st[(*i)].insert(val);
            sn[val]=(*i);
        }
        st[j].clear();
    }
    else {
        hs[j]=hs[(*i)];
        for(auto val:st[(*i)]) {
            st[j].insert(val);
            sn[val]=j;
        }
        st[(*i)].clear();
        *i=j;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
        s.insert({h[i],-1});
    }
    int cnt=1;
    for(auto vl:s) {
        mp[vl.first]=cnt;
        hs[cnt]=vl.first;
        cnt++;
    }
    for(int i=1;i<=n;i++) {
        sn[i]=mp[h[i]];
        st[sn[i]].insert(i);
    }
    s.clear();
    for(auto vl:mp) {
        s.insert(vl);
    }
    scanf("%d",&q);
    while(q--) {
        int tp;
        scanf("%d",&tp);
        if(tp==1) {
            int k,w;
            scanf("%d %d",&k,&w);
            s.insert({w,cnt});
            st[sn[k]].erase(k);
            sn[k]=cnt;
            st[sn[k]].insert(k);
            hs[cnt]=w;
            cnt++;
        }
        if(tp==2) {
            int k;
            scanf("%d",&k);
            printf("%d\n",hs[sn[k]]);
        }
        if(tp==3) {
            int l,r;
            scanf("%d %d",&l,&r);
            hs[cnt]=l-1;
            hs[cnt+1]=r+1;
            int m=(l+r)/2;
            set<pair<int,int> >::iterator it;
            set<pair<int,int> >::iterator jt;
            it=s.lower_bound({l,-1});
            int s1=cnt,s2=cnt+1;
            bool fn=false;
            while(it!=s.end() && (*it).first<=r) {
                if((*it).first<=m) {
                    int cur=(*it).second;
                    mrg(&s1,cur);
                } else {
                    int cur=(*it).second;
                    mrg(&s2,cur);
                }
                jt=it;
                it++;
                s.erase(jt);
            }
            s.insert({l-1,s1});
            s.insert({r+1,s2});
            cnt+=2;
        }
    }
    return 0;
}