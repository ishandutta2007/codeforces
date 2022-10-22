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
        int n,m;
        int i,j,k;
        int a,b,c;
        vector<int> v1;
        cin>>n;
        vector<int> v2(n+10,INF);
        v2[0]=0;
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        int p=0;
        priority_queue<P,vector<P>,greater<P>> q1;
        q1.push(make_pair(0,0));
        int bef=0;
        for(i=0;i<n;bef=v1[i],i++){
            a=q1.top().second;
            while(a==v1[i] || q1.top().first!=v2[a]){
                q1.pop();
                a=q1.top().second;
            }
            if(bef!=v1[i]){
                b=min(v2[a]+1,v2[v1[i]])-1;
                v2[bef]=min(v2[bef],b);
                p++;
            }else{
                b=min(v2[a]+1,v2[v1[i]]);
                v2[bef]=min(v2[bef],b);
            }
            q1.push(make_pair(v2[bef],bef));
            q1.push(make_pair(v2[v1[i]],v1[i]));
        }
        a=INF;
        for(i=0;i<=n;i++){
            a=min(a,v2[i]);
        }
        cout<<a+p<<endl;
    }
}

int main(){
    sol::solve();
}