#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define ll long long
#define maxn 100020
using namespace std;
int n;
int fir[maxn], en[maxn*2], nex[maxn*2], len[maxn*2];
int fa[maxn];
int tot;
int mxid[maxn][4];
ll f[maxn][2];
ll mx[maxn][4];
ll ans;
ll ret;
void tjb(int x,int y,int r){
	en[++tot] = y;
	len[tot] = r;
	nex[tot]=fir[x];
	fir[x] =tot;
}
void dfs_1(int x){
	f[x][0] = 0;
	for(int k=fir[x];k;k=nex[k]){
		int j = en[k];
		if(j == fa[x])continue;
		fa[j] = x;
		dfs_1(j);
		for(int i=0;i<4;++i){
			if(mxid[x][i] == 0 || mx[x][i] < mx[j][0] + len[k]){
				for(int z=3;z>i;--z){
					mxid[x][z] = mxid[x][z-1];
					mx[x][z] = mx[x][z-1];
				}
				mx[x][i] = mx[j][0] + len[k];
				mxid[x][i] = j;
				break;
			}
		}
		f[x][0] = max(f[x][0], f[j][0]);
	}
	f[x][0] = max(f[x][0], mx[x][0] + mx[x][1]);
	ans = max(ans, mx[x][0] + mx[x][1] + mx[x][2] + mx[x][3]);
}
void dfs_2(int x,ll mxdis){
	int mx1 = 0;
	int mx2 = 0;
	ans = max(ans, mxdis + mx[x][0] + mx[x][1] + mx[x][2]);
	for(int k=fir[x];k;k=nex[k]){
		int j=en[k];
		if(j == fa[x])continue;
		if(mx1 == 0 || f[j][0] > f[mx1][0]){
			mx2 = mx1;
			mx1 = j;
		}else if(mx2 == 0 || f[j][0] > f[mx2][0]){
			mx2 = j;
		}
		
	}
	for(int k=fir[x];k;k=nex[k]){
		int j=en[k];
		if(j == fa[x])continue;
		f[j][1] = f[x][1];
		for(int z1 = 0; z1 < 3; ++ z1){
			for(int z2 = z1 + 1; z2 < 3;++z2){
				if(mxid[x][z1] != 0 && mxid[x][z2] != 0 && mxid[x][z1] != j && mxid[x][z2] != j) f[j][1] = max(f[j][1], mx[x][z1] + mx[x][z2]);
			}
		}
		if(mx1 != j && mx1 != 0) f[j][1] = max(f[j][1], f[mx1][0]);
		if(mx2 != j && mx2 != 0) f[j][1] = max(f[j][1], f[mx2][0]);
		
		ll mxdisj = mxdis;
		f[j][1] = max(f[j][1], mxdis);
		for(int z1 = 0;z1 <2;++z1){
			if(mxid[x][z1] != 0 && mxid[x][z1] != j) {
				f[j][1] = max(f[j][1], mxdis + mx[x][z1]);
				mxdisj = max(mxdisj, mx[x][z1]);
			}
		}
		
		ans = max(ans, f[j][0] + f[j][1] + len[k] * 2);
	//	printf("debug: %d %lld %lld %lld\n",j, f[j][0], f[j][1], ans);
		dfs_2(j, mxdisj + len[k]);
		
	}	
}
int main()
{
    scanf("%d",&n);
    tot = 0;
    for(int i=1;i<=n;++i){
		fir[i] = 0;
		memset(mxid[i], 0,sizeof(mxid[i]));
		memset(mx[i],0,sizeof(mx[i]));
		mxid[i][0] = i;
		fa[i] = 0;
		f[i][0] = f[i][1] = 0;
	}
	ans = 0;
	ret = 0;
	for(int i=0;i<n-1;++i){
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		tjb(x,y,r);
		tjb(y,x,r);
		ret += r*2;
	}
	dfs_1(1);
	dfs_2(1,0);
	printf("%lld\n", ret-ans);
    return 0;
}