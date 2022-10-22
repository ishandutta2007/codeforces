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

int dp[111][111][2];

int main(){
	int n,m;
	int i,j,k,l;
	int a,b,c;
	cin>>n;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<2;k++){
				dp[i][j][k]=MAX;
			}
		}
	}
	dp[0][0][0]=0,dp[0][0][1]=0;
	for(i=0;i<n;i++){
		cin>>a;
		for(j=0;j<=i;j++){
			k=i-j;
			for(l=0;l<2;l++){
				if(dp[j][k][l]==MAX)continue;
				if(a==0){
					dp[j+1-l][k+l][l]=min(dp[j+1-l][k+l][l],dp[j][k][l]);
					dp[j+l][k+1-l][1-l]=min(dp[j+l][k+1-l][1-l],dp[j][k][l]+1);
				}else if(a%2==0){
					dp[j+1][k][0]=min(dp[j+1][k][0],dp[j][k][l]+l);
				}else{
					dp[j][k+1][1]=min(dp[j][k+1][1],dp[j][k][l]+1-l);
				}
			}
		}
	}
	a=min(dp[n/2][n-n/2][0],dp[n/2][n-n/2][1]);
	cout<<a<<endl;
}