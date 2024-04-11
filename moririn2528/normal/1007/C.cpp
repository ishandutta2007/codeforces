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
    LL rest_count=600;

    int ques(LL x,LL y){
        rest_count--;
        if(rest_count<0)assert(false);
        cout<<x+1<<" "<<y+1<<endl;
        int s;
        cin>>s;
        if(s==0)exit(0);
        return s;
    }

    LL x[3],y[3];

    void solve(){
        LL n,m;
        LL i,j,k;
        LL a,b,c;
        cin>>n;
        a=0;
        x[1]=n,x[2]=n;
        y[1]=n,y[2]=n;
        long double da,db,dc;
        while(1){
            for(i=0;i<2;i++){
                x[i+1]=max(x[i+1],x[i]);
                y[i+1]=max(y[i+1],y[i]);
            }
            if(x[0]==x[1])x[1]=x[2],y[2]=y[1];
            if(y[0]==y[1])y[1]=y[2],x[2]=x[1];
            if(x[2]-x[0]<MAX && y[2]-y[0]<MAX && (x[2]-x[0])*(y[2]-y[0])<rest_count)break;
            if(x[2]-x[0]<=1){
                a=(y[0]+y[2])/2;
                b=ques(x[0],a);
                if(b==2)y[0]=a+1;
                else y[1]=y[2]=a;
                continue;
            }
            if(y[2]-y[0]<=1){
                a=(x[0]+x[2])/2;
                b=ques(a,y[0]);
                if(b==1)x[0]=a+1;
                else x[1]=x[2]=a;
                continue;
            }
            da=(long double)(x[1]-x[0])*(y[1]-y[0]);
            db=(long double)(x[1]-x[0])*(y[2]-y[1]);
            dc=(long double)(x[2]-x[1])*(y[1]-y[0]);
            if(db>da+dc){
                a=(x[0]+x[1])/2;
                b=ques(a,y[1]);
                if(b==1)x[0]=a+1;
                if(b==2){
                    y[0]=y[1]+1;
                    y[1]=y[2],x[2]=x[1];
                }
                if(b==3)x[1]=a;
                continue;
            }
            if(dc>da+db){
                a=(y[0]+y[1])/2;
                b=ques(x[1],a);
                if(b==2)y[0]=a+1;
                if(b==1){
                    x[0]=x[1]+1;
                    x[1]=x[2],y[2]=y[1];
                }
                if(b==3)y[1]=a;
                continue;
            }
            a=(x[0]+x[1])/2,b=(y[0]+y[1])/2;
            c=ques(a,b);
            if(c==1)x[0]=a+1;
            if(c==2)y[0]=b+1;
            if(c==3)x[1]=a,y[1]=b;
        }
        for(i=x[0];i<x[2];i++){
            for(j=y[0];j<y[2];j++){
                ques(i,j);
            }
        }
        assert(false);
    }
}

int main(){
    sol::solve();
}