#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<math.h>     
#include<queue>
using namespace std;
#define mp make_pair
#define fi first
#define se second

int n,t,k;

void solve() {
    int i,j,a,b,sum=0;
    map<int,vector<int>> m,ans;
    map<pair<int,int>,int> st;
    map<int,vector<int>>::iterator it,it1,it2;
    for(i=0;i<t;i++) {
        scanf("%d%d",&a,&b);
        m[a].push_back(b);
        m[b].push_back(a);
        st[mp(a,b)]=1;
        st[mp(b,a)]=1;
        st[mp(a,a)]=1;
        st[mp(b,b)]=1;
    }
    for(it=m.begin();it!=m.end();it++) {
        for(it1=m.begin();it1!=m.end();it1++) {
            if(st[mp(it->first,it1->first)]!=1) {
                sum=0;
                for(it2=m.begin();it2!=m.end();it2++) {
                    if(it2->first!=it->first&&it2->first!=it1->first) {
                        if(st[mp(it2->first,it->first)]==1&&st[mp(it2->first,it1->first)]) {
                            sum++;
                        }
                    }
                }
                if(sum*100>=k*m[it->first].size()) {
                    ans[it->first].push_back(it1->first);
                }
            }
        }
    }
    for(it=m.begin();it!=m.end();it++) {
        printf("%d: %d ",it->first,ans[it->first].size());
        for(i=0;i<ans[it->first].size();i++) {
            printf("%d ",ans[it->first][i]);
        }
        printf("\n");
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(scanf("%d%d",&t,&k)!=EOF) {
        solve();
    }
    return 0;
}