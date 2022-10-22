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
typedef pair<LL,LL> LP;
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
        LL a,b,c;
        LL x,y;
        cin>>n>>m;
        priority_queue<LP,vector<LP>,greater<LP>> q1,q2;
        vector<LL> v1(n-1);
        vector<LP> v2;
        for(i=0;i<n;i++){
            x=a,y=b;
            cin>>a>>b;
            if(i==0)continue;
            q1.push({a-y,i-1});
            v1[i-1]=b-x;
        }
        for(i=0;i<m;i++){
            cin>>a;
            v2.push_back({a,i});
        }
        sort(v2.begin(),v2.end());
        vector<int> vs(n-1,-1);
        for(i=0;i<m;i++){
            while(!q1.empty() && q1.top().first<=v2[i].first){
                j=q1.top().second;q1.pop();
                q2.push({v1[j],j});
            }
            for(;!q2.empty() && q2.top().first<v2[i].first;q2.pop());
            if(q2.empty())continue;
            j=q2.top().second;q2.pop();
            vs[j]=v2[i].second+1;
        }

        for(i=0;i<n-1;i++){
            if(vs[i]==-1){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        array_show(vs);
    }
}

int main(){
    sol::solve();
}