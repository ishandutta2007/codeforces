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

typedef long long int d2_type;
typedef pair<d2_type,d2_type> d2_pair_type;
d2_pair_type ext_gcd(d2_type d2_a,d2_type d2_b,d2_type d2_bef2,d2_type d2_bef,d2_type d2_mod){
    // define a >= b
    if(d2_a % d2_b == 0)return make_pair(d2_b,d2_bef);
    d2_type d2_t=d2_bef2-d2_a/d2_b*d2_bef;
    if(d2_t<0)d2_t+=((-d2_t-1)/d2_mod+1)*d2_mod;
    else if(d2_t>=d2_mod)d2_t%=d2_mod;
    return ext_gcd(d2_b,d2_a%d2_b,d2_bef,d2_t,d2_mod);
}

d2_type divide2(d2_type d2_a,d2_type d2_b,d2_type d2_p=1e9+7){
    // a/b mod p (good for prime or not)  O(log p)
    if(d2_a>=d2_p)d2_a%=d2_p;
    if(d2_a<0)d2_a+=d2_p;
    if(d2_b>=d2_p)d2_b%=d2_p;
    if(d2_b<0)d2_b+=d2_p;
    if(d2_a==0)return 0;
    if(d2_b==0)return -1;
    d2_pair_type d2_pa=ext_gcd(d2_p,d2_b,0,1,d2_p);
    if(d2_a%d2_pa.first)return -1;
    d2_type d2_s=d2_a/d2_pa.first*d2_pa.second;
    d2_s%=d2_p;
    return d2_s;
}

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

namespace sol{
    int n,m;

    LP calc(LL h,LL x,LL y,LL g){
        vector<int> used(m,-1);
        LL pos=h;
        LL a=-1,b=-1;
        for(int i=0;i<m+10;i++){
            if(used[pos]!=-1){
                b=i-used[pos];
                if(a<used[pos])a=-1;
                break;
            }
            if(pos==g)a=i;
            used[pos]=i;
            pos=(x*pos+y)%m;
        }
        return {a,b};
    }

    void solve(){
        int i,j,k;
        LL a,b,c,d;
        LL H[2],X[2],Y[2],A[2];
        LP t[2];
        cin>>m;
        for(i=0;i<2;i++){
            cin>>a>>b>>c>>d;
            H[i]=a,A[i]=b;
            X[i]=c,Y[i]=d;
            t[i]=calc(a,c,d,b);
        }
        for(i=1;i<=2*m;i++){
            for(j=0;j<2;j++){
                H[j]=(H[j]*X[j]+Y[j])%m;
            }
            if(H[0]==A[0] && H[1]==A[1]){
                cout<<i<<endl;
                return;
            }
        }
        for(i=0;i<2;i++){
            if(t[i].first==-1){
                cout<<-1<<endl;
                return;
            }
        }
        a=t[0].first;
        for(i=0;i<2*m;i++){
            if(a%t[1].second==t[1].first%t[1].second)break;
            a+=t[0].second;
        }
        if(i==2*m){
            cout<<-1<<endl;
            return;
        }
        b=t[0].second*t[1].second/gcd(t[0].second,t[1].second);
        a%=b;
        for(i=0;i<2;i++){
            if(a<t[i].first)a+=((t[i].first-a-1)/b+1)*b;
        }
        cout<<a<<endl;
    }
}

int main(){
    sol::solve();
}