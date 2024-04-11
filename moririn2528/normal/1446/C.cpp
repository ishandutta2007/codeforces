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

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<P> v1,v2;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(make_pair(a,1));
    }
    sort(v1.begin(),v1.end());
    for(i=0;i<=30;i++){
        v2.clear();
        for(j=0;j<v1.size();j++){
            a=v1[j].first/2;
            if(v2.empty() || v2.back().first!=a)v2.push_back(make_pair(a,v1[j].second));
            else v2.back().second=max(v1[j].second,v2.back().second)+1;
        }
        swap(v1,v2);
    }
    cout<<n-v1[0].second<<endl;
    
}