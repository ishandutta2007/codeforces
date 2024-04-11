#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

namespace sol{

    void solve(){
        const LL N=1e5;
        LL n,m;
        LL i,j,k;
        LL a,b,c;
        cin>>n>>m;
        vector<int> vs(m+10,-1);
        vs[0]=0;
        for(i=0;i<n;i++){
            cin>>a>>b>>c;
            vector<LL> cnt(m+10,-1);
            for(j=0;j<=m;j++){
                if(vs[j]==-1)continue;
                if(vs[j]<=i)cnt[j]=max(cnt[j],c);
                if(cnt[j]==0)continue;
                if(a==1)k=j+(b-1)/N+1;
                else if(j>0)k=(j*b-1)/N+1;
                else k=0;
                if(k>m)continue;
                cnt[k]=max(cnt[k],cnt[j]-1);
                if(vs[k]==-1)vs[k]=i+1;
            }
        }
        for(i=1;i<=m;i++){
            if(i>1)cout<<" ";
            cout<<vs[i];
        }
        cout<<endl;
    }
}

int main(){
    sol::solve();
}