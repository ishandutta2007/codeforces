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

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

template<typename T>T ext_gcd(T a,T b,T& x,T& y){
    //ax+by=gcd(a,b)
    if(a<b)return ext_gcd(b,a,y,x);
    if(b==0){
        x=1,y=0;
        return a;
    }
    T gcd_val=ext_gcd(b,a%b,x,y);
    swap(x,y);
    y-=x*(a/b);
    if(x>b)y+=(x/b)*a,x%=b;
    if(y>a)x+=(y/a)*b,y%=a;
    return gcd_val;
}

namespace sol{

    int t[1100000];

    void solve(){
        LL n,m,p;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m>>p;
        LL day=n*m/gcd(n,m);
        vector<LL> v1;
        memset(t,-1,sizeof(t));
        for(i=0;i<n;i++){
            cin>>a;
            t[a]=i;
        }
        LL g=gcd(n,m);
        LL x,y;
        for(i=0;i<m;i++){
            cin>>b;
            if(t[b]==-1)continue;
            j=t[b];
            if(abs(i-j)%g)continue;
            day--;
            ext_gcd<LL>(n/g,m/g,x,y);
            x*=(i-j)/g;
            if(x<0)x+=((-x)/m+1)*m;
            x%=m;
            v1.push_back((n*x+j)%(n*m/g));
        }
        sort(v1.begin(),v1.end());
        //array_show(v1);
        LL s=(p-1)/day*(n*m/g);
        p%=day;
        if(p==0)p+=day;
        //cout<<s<<endl;
        LL bef=-1;
        for(auto num:v1){
            a=num-bef-1;
            if(p<=a){
                s+=bef+1+p,p=0;
                break;
            }
            p-=a;
            bef=num;
        }
        if(p)s+=bef+1+p;
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}