#include<bits/stdc++.h>
#define inf 2000000001
#define maxn 500000
using namespace std;
int n,x;
map<int,int> mp;
vector<pair<int,pair<int,int> > > ev;
int ans;
int l[maxn];
int r[maxn];
int c[maxn];
int main() {
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++) {
        scanf("%d %d %d",&l[i],&r[i],&c[i]);
        ev.push_back({l[i],{0,i}});
        ev.push_back({r[i],{1,i}});
    }
    sort(ev.begin(),ev.end());
    ans=inf;
    for(auto t:ev) {
        int i=t.second.second;
        if(t.second.first==0) {
            if(mp[x-(r[i]-l[i]+1)]!=0) {
                ans=min(ans,c[i]+mp[x-(r[i]-l[i]+1)]);
            }
        }
        else {
            if(mp[r[i]-l[i]+1]!=0) {
                mp[r[i]-l[i]+1]=min(mp[r[i]-l[i]+1],c[i]);
            }
            else mp[r[i]-l[i]+1]=c[i];
        }
    }
    if(ans==inf) ans=-1;
    printf("%d",ans);
    return 0;
}