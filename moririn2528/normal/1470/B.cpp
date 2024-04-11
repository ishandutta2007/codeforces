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

vector<int> pri;
void init(){
    vector<char> used(1e3+5);
    for(int i=2;i<1e3;i++){
        if(used[i])continue;
        pri.push_back(i);
        for(int j=2*i;j<=1e3;j+=i){
            used[j]=1;
        }
    }
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<int> v1;
    map<int,int> m1,m2;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        b=1;
        for(auto num:pri){
            for(j=0;a%num==0;j++,a/=num);
            if(j%2)b*=num;
        }
        if(a!=1)b*=a;
        m1[b]++;
    }
    a=0,b=0,c=0;
    for(auto node:m1){
        a=max(a,node.second);
        if(node.first==1 || node.second%2==0)c+=node.second;
        else b=max(b,node.second);
    }
    b=max(b,c);
    cin>>m;
    LL x;
    for(i=0;i<m;i++){
        cin>>x;
        if(x==0)cout<<a<<endl;
        else cout<<b<<endl;
    }
}

int main(){
    int n,i;
    init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}