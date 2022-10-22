#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int f[105][105][2][2];
string s;
int main(){
	scanf("%d",&T);
	f[0][0][0][0]=f[0][0][1][1]=1;
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			if(i>0||j>0)
				for(int c=0;c<=1;c++)
					for(int d=0;d<=1;d++){
						if(i>0&&f[i-1][j][c][d^1]==0)
							f[i][j][c][d]=1;
						if(j>0&&f[i][j-1][c^(d==0)][d^1]==0)
							f[i][j][c][d]=1;
					}
	while(T--){
		scanf("%d",&n);
		int cnt[2]={0,0};
		for(int i=1,x;i<=n;i++)
			scanf("%d",&x),cnt[x&1]++;
		puts(f[cnt[0]][cnt[1]][0][0]? "Alice":"Bob");
	}
	return 0;
}