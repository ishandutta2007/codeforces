#include <bits/stdc++.h>
#define maxn 15
double f[maxn][maxn];
int h[maxn][maxn],n=10;

std::pair<int,int> advance(int x,int y,int k){
	int d=x%2;
	if (d==0){
		if (y+k<=10)return std::make_pair(x,y+k);
		else return std::make_pair(x-1,10-(y+k-10-1));
	}else {
		if (y-k>=1)return std::make_pair(x,y-k);
		else {
			if (x==1)return std::make_pair(x,y);
			else return std::make_pair(x-1,1-(y-k));
		}
	}
}

double dfs(int x,int y){
	if (x==1&&y==1)return 0;
	if (f[x][y]!=-1)return f[x][y];
	f[x][y]=0;
	int cnt=0;
	for(int d=1;d<=6;++d){
		std::pair<int,int>pos=advance(x,y,d);
		int x1=pos.first,y1=pos.second;
		if (x1==x&&y==y1){cnt++;continue;}
		double min=1e9;
		if (h[x1][y1])min=std::min(min,dfs(x1-h[x1][y1],y1));
		min=std::min(min,dfs(x1,y1));
		f[x][y]+=(min+1);
	}if (cnt==0)f[x][y]/=6;
	else {
		f[x][y]/=(6-cnt);
		double q=(double)cnt/6;
		f[x][y]+=1/(1-q)-1;
	}
	return f[x][y];
}
		

int main(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&h[i][j]);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=-1;
	printf("%.8f\n",dfs(10,1));
	return 0;
}