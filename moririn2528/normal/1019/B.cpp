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

int n,m;

int check(int pos){
    pos%=n;
    int a,b,c;
    cout<<"? "<<pos+1<<endl;
    cin>>a;
    cout<<"? "<<(pos+n/2)%n+1<<endl;
    cin>>b;
    if(a==b){
        cout<<"! "<<pos+1<<endl;
        return 0;
    }
    if((a+b)%2){
        cout<<"! -1"<<endl;
        return 0;
    }
    if(a>b)return 1;
    else return -1;
}

int main(){
    int i,j,k;
    int a,b,c;
    int z[3];
    cin>>n;
    a=check(0);
    if(a==0)return 0;
    if(a==-1)z[0]=0,z[1]=n/2;
    else z[0]=n/2,z[1]=n;
    while(z[1]-z[0]>1){
        z[2]=(z[0]+z[1])/2;
        a=check(z[2]);
        if(a==0)return 0;
        if(a==-1)z[0]=z[2];
        else z[1]=z[2];
    }
    check(z[0]);
    check(z[1]);
}