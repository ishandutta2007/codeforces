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

int dp[555][555];
int num[555];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++)dp[i][j]=1e9;
		dp[i][0]=1,dp[i][1]=1;
	}
	for(j=2;j<=n;j++){
		for(i=0;i<n;i++){
			if(i+j>n)break;
			for(k=1;k<j;k++){
				if(dp[i][k]<=n && dp[i+k][j-k]<=n)dp[i][j]=min(dp[i][j],dp[i][k]+dp[i+k][j-k]);
			}
			if(num[i]==num[i+j-1])dp[i][j]=min(dp[i][j],dp[i+1][j-2]);
		}
	}
	cout<<dp[0][n]<<endl;
}