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

    void init(){
        
    }

    void print(vector<vector<int>>& v1){
        int n=v1.size();
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(v1[i][j]==-1)cout<<'.';
                if(v1[i][j]==0)cout<<'O';
                if(v1[i][j]==1)cout<<'X';
            }
            cout<<endl;
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        string sa;
        vector<vector<int>> v1(n,vector<int>(n,-1));
        int su=0;
        for(i=0;i<n;i++){
            cin>>sa;
            for(j=0;j<n;j++){
                if(sa[j]=='O')v1[i][j]=0,su++;
                if(sa[j]=='X')v1[i][j]=1,su++;
            }
        }
        for(a=0;a<3;a++){
            for(b=0;b<3;b++){
                if(a==b)continue;
                c=0;
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        if((i+j)%3==a && v1[i][j]==1)c++;
                        if((i+j)%3==b && v1[i][j]==0)c++;
                    }
                }
                if(c>su/3)continue;
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        if((i+j)%3==a && v1[i][j]!=-1)v1[i][j]=0;
                        if((i+j)%3==b && v1[i][j]!=-1)v1[i][j]=1;
                    }
                }
                print(v1);
                return;
            }
        }
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}