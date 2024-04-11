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
typedef pair<LL,LL> P;
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
        LL n,m,l;
        LL i,j,k;
        LL a,b,c;
        cin>>n>>l>>m;
        LL N=n;
        map<LL,P> m1;
        vector<P> v1;
        for(i=0;i<n;i++){
            cin>>a;
            m1[a].first++;
            if(i<l%N)m1[a].second++;
        }
        for(auto node:m1){
            v1.push_back(node.second);
        }
        n=v1.size();
        vector<LL> cnt(n+10),cnt_last(n+10);
        for(i=0;i<n;i++){
            cnt[i]=v1[i].first;
            cnt_last[i]=v1[i].second;
        }
        LL s=0;
        for(i=0;i<m;i++){
            for(j=n-1;j>=0;j--){
                if(i<l/N)s+=(l/N-i)%MAX*cnt[j];
                if(i<=l/N)s+=cnt_last[j];
                s%=MAX;
                cnt[j]+=cnt[j+1];
                cnt_last[j]+=cnt_last[j+1];
            }
            for(j=0;j<n;j++){
                cnt[j]%=MAX;
                cnt[j]*=v1[j].first;
                cnt[j]%=MAX;
                cnt_last[j]%=MAX;
                cnt_last[j]*=v1[j].first;
                cnt_last[j]%=MAX;
            }
        }
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}