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

vector<LL> pri;
bool used[1100000];

void init(){
    LL i,j;
    for(i=2;i<=1e6;i++){
        if(used[i])continue;
        pri.push_back(i);
        for(j=i*i;j<=1e6;j+=i){
            used[j]=true;
        }
    }
}

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

void solve(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    a=n;
    vector<P> v1;
    for(auto num:pri){
        b=0;
        while(a%num==0){
            b++,a/=num;
        }
        if(b)v1.push_back(make_pair(num,b));
    }
    if(a>1){
        b=gcd(a,m);
        if(b==a/b)v1.push_back(make_pair(b,2));
        else{
            if(b>1)v1.push_back(make_pair(b,1));
            if(a/b>1)v1.push_back(make_pair(a/b,1));
        }
    }
    vector<LL> v2;
    v2.push_back(1);
    for(auto node:v1){
        for(i=v2.size()-1;i>=0;i--){
            a=v2[i];
            for(j=0;j<node.second;j++){
                a*=node.first;
                v2.push_back(a);
            }
        }
    }
    sort(v2.rbegin(),v2.rend());
    for(auto num:v2){
        if(num%m){
            cout<<num<<endl;
            return;
        }
    }
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}