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

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    LL x1,x2,y1,y2;
    cin>>n;
    cin>>x1>>y1;
    cin>>x2>>y2;
    if(x1*y2-x2*y1==0){
        cout<<"NO"<<endl;
        return 0;
    }
    a=gcd(abs(x1),abs(x2));
    b=abs(y1*x2/a-y2*x1/a);
    if(a*b==n)cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            cout<<i<<" "<<j<<endl;
        }
    }
}