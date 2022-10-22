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

set<int> s1;
vector<int> v1;
vector<P> vt;

void get_prime(int t){
    int a,b;
    for(int i=1;i<1e5 && i<t;i++){
        if(t%i)continue;
        if(t/i<i)break;
        s1.insert(i);
        if(t/i!=i)s1.insert(t/i);
    }
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        vt.push_back(make_pair(a,b));
    }
    get_prime(a);
    get_prime(b);
    for(auto num:s1)v1.push_back(num);
    for(auto num:v1){
        if(num==1)continue;
        for(i=0;i<n;i++){
            if(vt[i].first%num && vt[i].second%num)break;
        }
        if(i==n){
            cout<<num<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}