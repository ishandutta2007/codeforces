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
const LL MAX=998244353;

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

LL dp[3333][3333];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    string sa,sb;
    cin>>sa>>sb;
    n=sa.size(),m=sb.size();
    for(i=0;i<n;i++){
        if(i>=m || sb[i]==sa[0])dp[i][1]=2;
    }
    for(i=1;i<n;i++){
        for(j=0;i+j<=n;j++){
            dp[j][i]%=MAX;
            if(i+j>=m || sb[i+j]==sa[i])dp[j][i+1]+=dp[j][i];
            if(j>m || (j>0 && sb[j-1]==sa[i]))dp[j-1][i+1]+=dp[j][i];
        }
    }
    LL s=0;
    for(i=m;i<=n;i++){
        s+=dp[0][i];
    }
    cout<<s%MAX<<endl;
}