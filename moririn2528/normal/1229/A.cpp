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
        LL a,b,c;
        cin>>n;
        map<LL,LL> m1;
        vector<LL> v1(n),v2(n),v3;
        for(i=0;i<n;i++){
            cin>>v1[i];
            m1[v1[i]]++;
        }
        for(i=0;i<n;i++)cin>>v2[i];
        for(auto node:m1){
            if(node.second>1)v3.push_back(node.first);
        }
        LL s=0;
        for(i=0;i<n;i++){
            for(j=0;j<v3.size();j++){
                if((v1[i]&v3[j])==v1[i]){
                    s+=v2[i];
                    break;
                }
            }
        }
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}