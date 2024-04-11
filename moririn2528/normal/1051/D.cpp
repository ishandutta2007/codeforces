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

int dp[1100][2200][4];
int add[5][5]={{0,1,1,1},{0,0,2,0},{0,2,0,0},{1,1,1,0}};

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	dp[1][1][0]=1;
	dp[1][2][1]=1;
	dp[1][2][2]=1;
	dp[1][1][3]=1;
	for(i=1;i<n;i++){
		for(j=0;j<=m;j++){
			for(a=0;a<4;a++){
				for(b=0;b<4;b++){
					c=add[a][b];
					dp[i+1][j+c][b]+=dp[i][j][a];
					if(dp[i+1][j+c][b]>=MAX)dp[i+1][j+c][b]-=MAX;
				}
			}
		}
	}
	a=0;
	for(i=0;i<4;i++){
		a+=dp[n][m][i];
	}
	a%=MAX;
	cout<<a<<endl;
}