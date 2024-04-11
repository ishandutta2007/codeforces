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
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=1e9+7){
    //p_a^p_n mod p_p
    long long int p_b=1,p_t=1;
    for(;p_b<=p_n;p_b<<=1);
    for(p_b>>=1;p_b>0;p_b>>=1){
        p_t*=p_t;
        if(p_t>=p_p)p_t%=p_p;
        if(p_n&p_b)p_t*=p_a;
        if(p_t>=p_p)p_t%=p_p;
    }
    return p_t;
}

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    a=pow_mod(2,m)-1;
    if(a<0)a+=MAX;
    cout<<pow_mod(a,n)<<endl;
}