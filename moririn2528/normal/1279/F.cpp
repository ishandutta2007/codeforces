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

LL n,m,p;
int t[1100000];
LL dp[1100000][2];

void check(LL a, int ma=1e9){
	int i;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0,dp[0][1]=0;
	for(i=0;i<n;i++){
		if(dp[i+1][0]==-1 || make_pair(dp[i][0]+t[i],dp[i][1])<make_pair(dp[i+1][0],dp[i+1][1])){
			dp[i+1][0]=dp[i][0]+t[i];
			dp[i+1][1]=dp[i][1];
		}
		if(i+p<=n && dp[i][1]<ma){
			if(dp[i+p][0]==-1 || make_pair(dp[i][0],dp[i][1]+a)<make_pair(dp[i+p][0],dp[i+p][1])){
				dp[i+p][0]=dp[i][0]+a;
				dp[i+p][1]=dp[i][1]+1;
			}
		}
	}
}

LL solve(){
	int i,j,k;
	LL a,b,c;
	LL z[3]={-1,n};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;

		check(z[2]);

		if(dp[n][1]<=m)z[1]=z[2];
		else z[0]=z[2];
	}
	check(z[1],m);
	a=dp[n][0]-m*z[1];
	return a;
}

int main(){
	int i,j,k;
	int a,b,c;
	string sa;
	cin>>n>>m>>p;
	if(m*p>=n){
		cout<<0<<endl;
		return 0;
	}
	cin>>sa;
	for(i=0;i<n;i++){
		if('A'<=sa[i] && sa[i]<='Z')t[i]=1;
	}
	LL s=solve();
	for(i=0;i<n;i++){
		t[i]=1-t[i];
	}
	s=min(s,solve());
	cout<<s<<endl;
	return 0;
}