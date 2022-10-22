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

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        map<LL,vector<int>> m1;
        vector<LL> v1;
        cin>>n;
        b=0;
        for(i=0;i<n;i++){
            cin>>a;
            if(m1.find(a)==m1.end()){
                m1[a]=vector<int>();
                v1.push_back(a);
            }
            m1[a].push_back(i+1);
            b+=a;
        }
        vector<int> vs;
        sort(v1.rbegin(),v1.rend());
        for(auto num:v1){
            for(auto id:m1[num]){
                vs.push_back(id);
            }
            b-=m1[num].size()*num;
            if(num>b)break;
        }
        cout<<vs.size()<<endl;
        sort(vs.begin(),vs.end());
        for(i=0;i<vs.size();i++){
            if(i)cout<<" ";
            cout<<vs[i];
        }
        cout<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}