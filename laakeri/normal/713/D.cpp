#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int tt[10][10][1010][1010];

int l2[1010];

int getmax(int x1, int y1, int x2, int y2){
	if (x2<x1) return 0;
	if (y2<y1) return 0;
	int xx=l2[x2-x1+1];
	int yy=l2[y2-y1+1];
	int r=0;
	r=max(r, tt[xx][yy][x1][y1]);
	r=max(r, tt[xx][yy][x2-(1<<xx)+1][y1]);
	r=max(r, tt[xx][yy][x1][y2-(1<<yy)+1]);
	r=max(r, tt[xx][yy][x2-(1<<xx)+1][y2-(1<<yy)+1]);
	return r;
}

vector<pair<int, int> > ps[1010];

int ma[1010][1010];
int dp[1010][1010];

vector<int> qr[1010];

int main(){
	for (int i=0;i<=1000;i++){
		while ((1<<(l2[i]+1))<=i) l2[i]++;
	}
	int n,m;
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			scanf("%d", &ma[i][ii]);
		}
	}
	for (int i=n-1;i>=0;i--){
		for (int ii=m-1;ii>=0;ii--){
			if (ma[i][ii]==0) dp[i][ii]=0;
			else {
				dp[i][ii]=min(dp[i+1][ii+1], dp[i+1][ii]);
				dp[i][ii]=min(dp[i][ii], dp[i][ii+1]);
				dp[i][ii]++;
				tt[0][0][i][ii]=dp[i][ii];
			}
		}
	}
	for (int xx=1;xx<10;xx++){
		for (int i=0;i<n;i++){
			for (int ii=0;ii<m;ii++){
				tt[xx][0][i][ii]=tt[xx-1][0][i][ii];
				int px=(1<<(xx-1));
				if (i+px<n) tt[xx][0][i][ii]=max(tt[xx][0][i][ii], tt[xx-1][0][i+px][ii]);
			}
		}
	}
	for (int yy=1;yy<10;yy++){
		for (int i=0;i<n;i++){
			for (int ii=0;ii<m;ii++){
				tt[0][yy][i][ii]=tt[0][yy-1][i][ii];
				int py=(1<<(yy-1));
				if (ii+py<m) tt[0][yy][i][ii]=max(tt[0][yy][i][ii], tt[0][yy-1][i][ii+py]);
			}
		}
	}
	for (int xx=1;xx<10;xx++){
		for (int yy=1;yy<10;yy++){
			for (int i=0;i<n;i++){
				for (int ii=0;ii<m;ii++){
					int px=(1<<(xx-1));
					int py=(1<<(yy-1));
					int v=tt[xx-1][yy-1][i][ii];
					if (i+px<n) v=max(v, tt[xx-1][yy-1][i+px][ii]);
					if (ii+py<m) v=max(v, tt[xx-1][yy-1][i][ii+py]);
					if (i+px<n&&ii+py<m) v=max(v, tt[xx-1][yy-1][i+px][ii+py]);
					tt[xx][yy][i][ii]=v;
				}
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int i=0;i<t;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		y1--;
		x1--;
		y2--;
		x2--;
		int mii=1;
		int maa=min(n, m);
		int v=0;
		while (mii<=maa){
			int mid=(mii+maa)/2;
			int ttt=getmax(x1, y1, x2-mid+1, y2-mid+1);
			if (ttt>=mid){
				v=mid;
				mii=mid+1;
			}
			else{
				maa=mid-1;
			}
		}
		printf("%d\n", v);
	}
}