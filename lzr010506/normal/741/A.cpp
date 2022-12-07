#include<bits/stdc++.h>

#define maxn 110
#define MAX 1000000010

using namespace std;

int n;

int dis[maxn][maxn];

long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}

void Work(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	long long ans=1;
	for(int i=1;i<=n;i++)
		if(dis[i][i]>n){
			puts("-1");
			return;
		}
		else{
			if(dis[i][i]%2==0)dis[i][i]/=2;
			ans=ans/gcd(ans,dis[i][i])*dis[i][i];
		}
	cout<<ans<<endl;
}

void Init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dis[i][j]=MAX;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		dis[i][x]=1;
	}
}

int main(){
	Init();
	Work();
	return 0;
}