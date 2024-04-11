#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},chk[111][111];
char mp[111][111],out[70]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",ans[111][111];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
		int cnt = 0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == 'R') cnt++;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) chk[i][j] = 0;

		int c = cnt / k, left = cnt % k, cur = 0;
		int x=1,y=1,d=0,ate=0;
		while(1){
			ans[x][y] = out[cur];
			chk[x][y] = 1;

			if(mp[x][y] == 'R'){
				ate++;
				if(ate == c + (left > cur) && cur < k-1){
					cur++;
					ate = 0;
				}
			}

			int fl = 0;
			while(1){
				int xx = x+dx[d], yy=y+dy[d];
				if(xx<1 || yy<1 || xx>n || yy>m || chk[xx][yy]){
					d=(d+1)%4;
					fl++;
					if(fl > 4) break;
					continue;
				}else break;
			}
			if(fl > 4) break;

			x += dx[d];
			y += dy[d];
		}

		for(int i=1;i<=n;i++) ans[i][m+1] = 0;
		for(int i=1;i<=n;i++) printf("%s\n",ans[i]+1);
	}

}