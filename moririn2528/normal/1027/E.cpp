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

LL dp[555][555];

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        dp[i][0]=1;
        for(j=0;j<n;j++){
            for(k=1;k<=i && j+k<=n;k++){
                dp[i][j+k]+=dp[i][j];
                if(dp[i][j+k]>=MAX)dp[i][j+k]-=MAX;
            }
        }
    }
    LL s=0;
    for(i=0;i<n;i++){
        a=dp[i+1][n]-dp[i][n];
        if(a<0)a+=MAX;
        b=min(n,(m-1)/(i+1));
        a=a*dp[b][n]%MAX;
        s+=a;
    }
    s*=2;
    cout<<s%MAX<<endl;
}