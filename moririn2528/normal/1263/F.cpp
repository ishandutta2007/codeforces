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

int par[2][3005];
int bot[2][1005];
int lef[2][3005];
int dp[1005][1005];

void lef_init(int a,int b,int c){
	if(b==-1)return;
	if(lef[a][b]!=-1)return;
	lef[a][b]=c;
	lef_init(a,par[a][b],c);
}

int calc_parent(int a,int b,int c,bool flag=true){
	if(par[a][b]==-1)return 0;
	if(flag && lef[a][b]!=c)return 0;
	return calc_parent(a,par[a][b],c,flag)+1;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int p,q;
	memset(par,-1,sizeof(par));
	memset(lef,-1,sizeof(lef));
	cin>>n;
	cin>>p;
	for(i=1;i<p;i++){
		cin>>a;
		a--;
		par[0][i]=a;
	}
	for(i=0;i<n;i++){
		cin>>bot[0][i];
		bot[0][i]--;
	}

	cin>>q;
	for(i=1;i<q;i++){
		cin>>a;
		a--;
		par[1][i]=a;
	}
	for(i=0;i<n;i++){
		cin>>bot[1][i];
		bot[1][i]--;
	}
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			lef_init(i,bot[i][j],j);
		}
	}
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)dp[i][j]=1e8;
	dp[0][0]=0;
	dp[1][0]=calc_parent(0,bot[0][0],0);
	dp[0][1]=calc_parent(1,bot[1][0],0);

	for(i=1;i<n;i++){
		a=calc_parent(0,bot[0][i],i);
		for(j=0;j<i;j++){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a);
		}
		a=bot[0][i],b=0;
		for(j=i-2;j>=0;j--){
			while(lef[0][a]>j)a=par[0][a],b++;
			dp[i+1][i]=min(dp[i+1][i],dp[j+1][i]+b);
		}
		dp[i+1][i]=min(dp[i+1][i],dp[0][i]+calc_parent(0,bot[0][i],i,false));

		a=calc_parent(1,bot[1][i],i);
		for(j=0;j<i;j++){
			dp[j][i+1]=min(dp[j][i+1],dp[j][i]+a);
		}
		a=bot[1][i],b=0;
		for(j=i-2;j>=0;j--){
			while(lef[1][a]>j)a=par[1][a],b++;
			dp[i][i+1]=min(dp[i][i+1],dp[i][j+1]+b);
		}
		dp[i][i+1]=min(dp[i][i+1],dp[i][0]+calc_parent(1,bot[1][i],i,false));
	}
	int s=min(p-1,q-1);
	for(j=1;j<n;j++)s=min(s,dp[j][n]);
	for(j=1;j<n;j++)s=min(s,dp[n][j]);
	cout<<p+q-2-s<<endl;
	//for(i=0;i<=n;i++){
	//	array_show(dp[i],n+1);
	//}
}