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

int n,m;
int ques(int pos){
    if(pos<n)pos+=((pos/n)+1)*n;
    pos%=n;
    cout<<"? "<<pos+1<<endl;
    int s;
    cin>>s;
    return s;
}
int ans(int pos){
    if(pos<n)pos+=((pos/n)+1)*n;
    pos%=n;
    cout<<"! "<<pos+1<<endl;
}

void check(int pos,bool flag){
    int a=1;
    int s;
    int sn=1;
    if(flag)sn=-1;
    while(1){
        s=ques(pos+sn*a);
        if(s==m){
            ans(pos+sn*a);
            return;
        }
        if((flag!=(s>m)))break;
        a*=2;
    }
    while(a>=1){
        a/=2;
        s=ques(pos+sn*a);
        if(s==m){
            ans(pos+sn*a);
            return;
        }
        if(flag==(s>m))pos+=sn*a;
    }
    ans(pos+sn);
}

int main(){
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    int pos=0;
    ques(pos);
    for(i=0;i<900;i++){
        pos+=i;
        a=ques(pos);
        if(m!=a){
            check(pos,(a>m));
            return 0;
        }
    }
}