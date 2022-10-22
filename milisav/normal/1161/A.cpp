#include<bits/stdc++.h>
using namespace std;
int n,k;
int x[200000];
bool p[200000];
bool pos[200000][3];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) {
		pos[i][0]=pos[i][1]=pos[i][2]=true;
	}
	pos[1][2]=false;
	pos[n][1]=false;
	for(int i=1;i<=k;i++) {
		scanf("%d",&x[i]);
		p[x[i]]=true;
		if(p[x[i]-1]) pos[x[i]][2]=false;
		if(p[x[i]+1]) pos[x[i]][1]=false;
		if(p[x[i]]) pos[x[i]][0]=false;
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<3;j++) {
			if(pos[i][j]) {
				//printf("%d %d\n",i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}