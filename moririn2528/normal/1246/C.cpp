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
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

LL dp[2005][2005][2];
string sa[2005];
int num[2005];

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m;
	dp[0][0][0]=1,dp[0][0][1]=1;
	for(i=0;i<n;i++){
		cin>>sa[i];
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(sa[j][i]=='R')num[i]++;
		}
	}
	for(i=0;i<n;i++){
		a=0;
		for(j=0;j<m;j++){
			if(sa[i][j]=='R')a++;
		}
		for(j=0;j<m;j++){
			if(sa[i][j]=='R'){
				a--,num[j]--;
			}
			dp[i][j+1][1]+=dp[i][j][0],dp[i][m-a][1]+=-dp[i][j][0];
			if(i+j)dp[i][j+1][1]+=dp[i][j][1];
			dp[i+1][j][0]+=dp[i][j][1],dp[n-num[j]][j][0]+=-dp[i][j][1];
			if(i+j)dp[i+1][j][0]+=dp[i][j][0];

			if(dp[i+1][j][0]<0)dp[i+1][j][0]+=((-dp[i+1][j][0])/MAX+1)*MAX;
			if(dp[i+1][j][0]>=MAX)dp[i+1][j][0]%=MAX;
			if(dp[i][j+1][1]<0)dp[i][j+1][1]+=((-dp[i][j+1][1])/MAX+1)*MAX;
			if(dp[i][j+1][1]>=MAX)dp[i][j+1][1]%=MAX;
		}
	}
	if(n==1 || m==1){
		a=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(sa[i][j]=='R')a++;
			}
		}
		if(a==0)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	a=dp[n-1][m-1][0]+dp[n-1][m-1][1];
	if(a<0)a+=((-a)/MAX+1)*MAX;
	cout<<a%MAX<<endl;
}