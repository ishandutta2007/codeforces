#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=1<<11;

vector<pair<int, ll> > h[N][N];

int g[2020][2020];
int val[2020][2020];

void add(int i, int j, int stu, int sta, int stl, int str, int y, int x, int k, ll w){
	if (y<stu||y>sta||x<stl||x>str) return;
	if (stu==sta){
		g[y][x]=k;
		val[y][x]=w;
		return;
	}
	if ((int)h[i][j].size()>0&&h[i][j].back().F==k) h[i][j].back().S+=w;
	else h[i][j].push_back({k, w});
	if (stu<sta){
		int ym=(stu+sta)/2;
		int xm=(stl+str)/2;
		add(i*2, j*2, stu, ym, stl, xm, y, x, k, w);
		add(i*2+1, j*2, ym+1, sta, stl, xm, y, x, k, w);
		add(i*2, j*2+1, stu, ym, xm+1, str, y, x, k, w);
		add(i*2+1, j*2+1, ym+1, sta, xm+1, str, y, x, k, w);
	}
}

int is[2020];

ll sum(int i, int j, int stu, int sta, int stl, int str, int y1, int y2, int x1, int x2){
	if (y2<stu||y1>sta||x2<stl||x1>str) return 0;
	if (y1<=stu&&sta<=y2&&x1<=stl&&str<=x2){
		if (stu==sta){
			if (is[g[stu][stl]]) return val[stu][stl];
			else return 0;
		}
		ll r=0;
		for (auto t:h[i][j]){
			if (is[t.F]) r+=t.S;
		}
		return r;
	}
	else{
		int ym=(stu+sta)/2;
		int xm=(stl+str)/2;
		ll r=0;
		r+=sum(i*2, j*2, stu, ym, stl, xm, y1, y2, x1, x2);
		r+=sum(i*2+1, j*2, ym+1, sta, stl, xm, y1, y2, x1, x2);
		r+=sum(i*2, j*2+1, stu, ym, xm+1, str, y1, y2, x1, x2);
		r+=sum(i*2+1, j*2+1, ym+1, sta, xm+1, str, y1, y2, x1, x2);
		return r;
	}
}

char sr[22];

int main(){
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1;i<=k;i++){
		int len;
		scanf("%d", &len);
		for (int j=0;j<len;j++){
			int y,x,w;
			scanf("%d %d %d", &y, &x, &w);
			add(1, 1, 0, N-1, 0, N-1, y, x, i, w);
		}
		is[i]=1;
	}
	int q;
	scanf("%d", &q);
	for (int i=0;i<q;i++){
		scanf("%s", sr);
		if (sr[0]=='S'){
			int j;
			scanf("%d", &j);
			is[j]^=1;
		}
		else{
			int x1,y1,x2,y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%I64d\n", sum(1, 1, 0, N-1, 0, N-1, x1, x2, y1, y2));
		}
	}
}