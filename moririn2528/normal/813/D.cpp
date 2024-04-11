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

int bef[115555],bef2[10];
int dp[5555][5555];
int t[5555];

int main(){
	int n;
	int i,j,k;
	int a,b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	memset(bef,-1,sizeof(bef));
	b=0;
	for(i=0;i<=n;i++){
		memset(bef,-1,sizeof(bef));
		memset(bef2,-1,sizeof(bef2));
		for(j=1;j<i;j++){
			bef[t[j-1]]=max(bef[t[j-1]],dp[j][i]);
			bef2[t[j-1]%7]=max(bef2[t[j-1]%7],dp[j][i]);
		}
		for(j=i+1;j<=n;j++){
			dp[i][j]=max(dp[i][j],bef[t[j-1]-1]+1);
			dp[i][j]=max(dp[i][j],bef[t[j-1]+1]+1);
			dp[i][j]=max(dp[i][j],bef2[t[j-1]%7]+1);
			dp[i][j]=max(dp[i][j],dp[0][i]+1);

			bef[t[j-1]]=max(bef[t[j-1]],dp[i][j]);
			bef2[t[j-1]%7]=max(bef2[t[j-1]%7],dp[i][j]);
			b=max(b,dp[i][j]);
		}
	}

	
	cout<<b<<endl;
}