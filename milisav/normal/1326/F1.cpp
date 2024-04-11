#include<bits/stdc++.h>
#define maxn 20000
using namespace std;
int n;
int a,b;
char s[20][20];
vector<pair<int,pair<long long,int> > > f[maxn];
vector<pair<int,pair<long long,int> > > g[maxn];
vector<int> h;
int pos[maxn][20];
vector<pair<int,int> > fec;
void fil(int i) {
    int k=0;
    while(i>0) {
        if(i&1) h.push_back(k);
        i>>=1;
        k++;
    }
}
long long ans[maxn];
int main() {
    scanf("%d",&n);
    a=n/2;
    b=n-a;
    for(int i=0;i<n;i++) {
        scanf("%s",s[i]);
    }
    int tc=(1<<n);
    for(int i=0;i<tc;i++) {
        if(__builtin_popcount(i)==a) {
            fil(i);
            do {
                int t=0;
                for(int i=0;i+1<h.size();i++) {
                    t<<=1;
                    if(s[h[i]][h[i+1]]=='1') t++;
                }
                int l=h.back();
                if(pos[t][l]==0) fec.push_back({t,l});
                pos[t][l]++;
            } while(next_permutation(h.begin(),h.end()));
            for(auto t:fec) {
                f[i].push_back({t.first,{pos[t.first][t.second],t.second}});
                pos[t.first][t.second]=0;
            }
            fec.clear();
            h.clear();
        }
        if(__builtin_popcount(i)==b) {
            fil(i);
            do {
                int t=0;
                for(int i=0;i+1<h.size();i++) {
                    t<<=1;
                    if(s[h[i]][h[i+1]]=='1') t++;
                }
                int l=h.front();
                if(pos[t][l]==0) fec.push_back({t,l});
                pos[t][l]++;
            } while(next_permutation(h.begin(),h.end()));
            for(auto t:fec) {
                g[i].push_back({t.first,{pos[t.first][t.second],t.second}});
                pos[t.first][t.second]=0;
            }
            fec.clear();
            h.clear();
        }
    }
    int c=(1<<(b-1));
    for(int i=0;i<tc;i++) {
        if(__builtin_popcount(i)==a) {
            int j=((tc-1)^i);
            for(auto x:f[i]) {
                int fa=x.first;
                long long wa=x.second.first;
                fa=fa*2*c;
                for(auto y:g[j]) {
                    int r=0;
                    if(s[x.second.second][y.second.second]=='1') r=c;
                    int fb=y.first;
                    long long wb=y.second.first;
                    ans[fa+r+fb]+=wa*wb;
                }
            }
        }
    }
    tc>>=1;
    for(int i=0;i<tc;i++) printf("%lld ",ans[i]);
    return 0;
}