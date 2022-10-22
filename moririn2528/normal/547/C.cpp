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

namespace sol{
    const int M=5e5+5;

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        LL x,y;
        cin>>n>>m;
        vector<int> v1;
        vector<vector<int>> v2(n);
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
            for(j=2;j<1000;j++){
                for(k=0;a%j==0;k++)a/=j;
                if(k)v2[i].push_back(j);
            }
            if(a!=1)v2[i].push_back(a);
        }
        LL s=0;
        vector<int> cnt(M);
        vector<char> used(n);
        for(k=0;k<m;k++){
            cin>>a;
            a--;
            b=0;
            x=v2[a].size();
            used[a]=!used[a];
            for(i=0;i<(1<<x);i++){
                c=1;
                for(j=0;j<x;j++){
                    if(i&1<<j)c*=v2[a][j];
                }
                if(!used[a])cnt[c]--;
                if(__builtin_popcount(i)%2)b-=cnt[c];
                else b+=cnt[c];
                if(used[a])cnt[c]++;
            }
            if(used[a])s+=b;
            else s-=b;
            cout<<s<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}