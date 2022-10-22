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

    bool solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<int> v1;
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        a=0,b=v1[0];
        for(i=0;i<n;i++){
            if(b!=v1[i])break;
        }
        if(i>n/2)return false;
        a=i;
        for(;i<n;i++){
            if(v1[i-1]!=v1[i] && i-a>a)break;
        }
        if(i>n/2)return false;
        b=i,c=-1;
        for(;i<n;i++){
            if(v1[i-1]!=v1[i]){
                if(i>n/2)break;
                c=i;
            }
        }
        if(c==-1 || c-b<=a)return false;
        cout<<a<<" "<<b-a<<" "<<c-b<<endl;
        return true;
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        if(!sol::solve()){
            cout<<"0 0 0"<<endl;
        }
    }
}