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
    int dis[33][33];
    int n,m;

    void ans(){
        int i,j;
        vector<tuple<int,int,int>> vs;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(dis[i][j]!=-1)vs.push_back(make_tuple(i+1,j+1,dis[i][j]));
            }
        }
        cout<<"YES"<<endl;
        cout<<"32 "<<vs.size()<<endl;
        int a,b,c;
        for(auto node:vs){
            tie(a,b,c)=node;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }

    void solve(){
        int i,j,k;
        int a,b,c,d;
        int x,y;
        cin>>x>>y;
        memset(dis,-1,sizeof(dis));
        n=32;
        if(y-x<30){
            dis[0][n-1]=x;
            for(i=1;i<=y-x;i++){
                dis[0][i]=x;
                dis[i][n-1]=i;
            }
            ans();
            return;
        }
        for(i=1;i<=6;i++){
            dis[n-1-i][n-1]=1;
            dis[n-1-i][n-i]=1;
        }
        vector<int> v1;
        int p=0;
        v1.push_back(0);
        for(i=0;i<8;i++){
            a=y-x+1;
            b=a%7;
            if(b==0)b=7;
            for(auto pos:v1){
                dis[pos][n-b]=x;
                dis[pos][n-1]=x;
            }
            a-=b;
            if(a==0)break;
            x+=b;
            a/=7;
            for(auto pos:v1){
                dis[pos][p+1]=x-1+a;
                dis[pos][p+2]=x-1+3*a;
                dis[pos][p+3]=x-1;
            }
            dis[p+1][p+2]=4*a;
            dis[p+1][p+3]=a;
            dis[p+2][p+3]=a;
            v1=vector<int>({p+1,p+2,p+3});
            p+=3;
            x=1,y=a;
        }
        ans();
    }
}

int main(){
    sol::solve();
}