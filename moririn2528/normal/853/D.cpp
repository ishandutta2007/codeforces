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

LL dp[300005][55];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<n;i++){
		cin>>a;
		s+=a;
		a/=1000;
		for(j=53-a;j>=0;j--){
			if(dp[i][j]==-1)continue;
			dp[i+1][j+a]=max(dp[i][j],dp[i+1][j+a]);
		}
		a*=10;
		for(j=0;j<53;j++){
			if(dp[i][j]==-1)continue;
			if(j>=a)dp[i+1][j-a]=max(dp[i+1][j-a],dp[i][j]+a);
			else dp[i+1][0]=max(dp[i+1][0],dp[i][j]+j);
		}
	}
	a=0;
	for(i=0;i<55;i++){
		a=max(a,dp[n][i]);
	}
	s-=a*100;
	cout<<s<<endl;
}