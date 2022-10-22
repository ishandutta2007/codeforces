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

int dp[555][555];
int t[555];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<int> v1;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		dp[i][1]=a;
	}
	for(i=2;i<=n;i++){
		for(j=0;i+j<=n;j++){
			for(k=1;k<i;k++){
				if(dp[j][k]==-1 || dp[j+k][i-k]==-1)continue;
				if(dp[j][k]==dp[j+k][i-k])dp[j][i]=dp[j][k]+1;
			}
		}
	}
	memset(t,-1,sizeof(t));
	t[0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			if(dp[i-j][j]==-1)continue;
			if(t[i]==-1)t[i]=t[i-j]+1;
			else t[i]=min(t[i],t[i-j]+1);
		}
	}
	cout<<t[n]<<endl;
}