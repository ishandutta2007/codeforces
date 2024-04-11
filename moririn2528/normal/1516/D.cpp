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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<vector<int>> pri(n);
        for(i=0;i<n;i++){
            cin>>a;
            for(j=2;j<400;j++){
                for(k=0;a%j==0;k++)a/=j;
                if(k)pri[i].push_back(j);
            }
            if(a!=1)pri[i].push_back(a);
        }
        const int N=1e5+7,M=20;
        vector<vector<int>> nx(n+10,vector<int>(M+2,n+1));//next
        vector<int> v1(N);
        int cnt=0;
        for(i=0,j=0;i<n;i++){
            for(;j<n && cnt==0;j++){
                for(auto num:pri[j]){
                    if(v1[num])cnt++;
                    v1[num]++;
                }
            }
            if(j==n && cnt==0)j=n+2;
            nx[i][0]=j-1;//end point of max subarray
            for(auto num:pri[i]){
                v1[num]--;
                if(v1[num])cnt--;
            }
        }
        //doubling
        for(i=0;i<M;i++){
            for(j=0;j<n;j++){
                nx[j][i+1]=nx[nx[j][i]][i];
            }
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            int s=0;
            for(j=M-1;j>=0;j--){
                if(nx[a][j]>=b)continue;
                s+=1<<j;
                a=nx[a][j];
            }
            cout<<s+1<<endl;
        }
    }
}

int main(){
    sol::solve();
}