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

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        string sa;
        cin>>n;
        vector<vector<int>> v1(n,vector<int>(n));
        for(k=0;k<2;k++){
            for(i=0;i<n;i++){
                cin>>sa;
                for(j=0;j<n;j++){
                    if(sa[j]=='1')v1[i][j]^=1;
                }
            }
        }
        for(k=0;k<2;k++){
            vector<int> va(n),vb(n);
            va[0]=k;
            for(i=0;i<n;i++){
                vb[i]=v1[0][i]^va[0];
            }
            for(i=0;i<n;i++){
                va[i]=v1[i][0]^vb[0];
            }
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(v1[i][j]!=va[i]^vb[j])break;
                }
                if(j<n)break;
            }
            if(i==n){
                cout<<"YES"<<endl;
                return ;
            }
        }
        cout<<"NO"<<endl;
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