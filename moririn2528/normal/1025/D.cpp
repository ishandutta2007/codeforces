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

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

char dp[770][770][2];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    vector<int> val(n);
    vector<vector<char>> path(n+2,vector<char>(n+2,0));
    for(i=0;i<n;i++){
        cin>>val[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            a=gcd(val[i],val[j]);
            if(a>1)path[i][j]=1,path[j][i]=1;
        }
        path[i][n]=1;
    }
    for(i=0;i<n;i++){
        dp[i][i][0]=1,dp[i][i][1]=1;
    }
    for(i=0;i<n;i++){
        for(j=0;i+j<n;j++){
            for(k=j;k<=i+j;k++){
                b=dp[j][k][1]&dp[k][i+j][0];
                if(j!=0)dp[j-1][i+j][0]|=b&path[j-1][k];
                dp[j][i+j+1][1]|=b&path[k][i+j+1];
            }
        }
    }
    if(dp[0][n][1])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}