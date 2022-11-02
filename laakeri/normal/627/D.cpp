#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];
int a[202020];

int cnt[202020];
int can[202020];
int aps[202020];

int k;

int gg=0;

void dfs1(int x, int p, int v){
	aps[x]=1;
	cnt[x]=0;
	can[x]=0;
	int cs=0;
	int mact=0;
	int f=0;
	for (int nx:g[x]){
		if (nx!=p){
			dfs1(nx, x, v);
			aps[x]+=aps[nx];
			if (can[nx]){
				cs+=aps[nx];
			}
			else{
				f=1;
				mact=max(mact, cnt[nx]);
			}
		}
	}
	if (a[x]<v){
		can[x]=0;
		cnt[x]=0;
	}
	else{
		if (!f){
			can[x]=1;
			cnt[x]=cs+1;
		}
		else{
			can[x]=0;
			cnt[x]=cs+mact+1;
		}
	}
	if (cnt[x]>=k){
		gg=1;
	}
}

void dfs2(int x, int p, int v, int ycs, int yct, int ycan){
	int cs=0;
	int mact=yct;
	int mact2=0;
	int f=0;
	for (int nx:g[x]){
		if (nx!=p){
			if (can[nx]){
				cs+=aps[nx];
			}
			else{
				f++;
				if (cnt[nx]>mact){
					mact2=mact;
					mact=cnt[nx];
				}
				else if(cnt[nx]>mact2){
					mact2=cnt[nx];
				}
			}
		}
	}
	if (a[x]>=v){
		if (cs+ycs+mact+1>=k){
			gg=1;
		}
		if (cs+yct+1>=k){
			gg=1;
		}
		for (int nx:g[x]){
			if (nx!=p){
				if (can[nx]){
					cs-=aps[nx];
				}
				else{
					f--;
				}
				if (ycan==0||f>0){
					if (mact==cnt[nx]) dfs2(nx, x, v, 0, ycs+cs+mact2+1, 0);
					else dfs2(nx, x, v, 0, ycs+cs+mact+1, 0);
				}
				else{
					if (mact==cnt[nx]) dfs2(nx, x, v, ycs+cs+1, 0, 1);
 					else dfs2(nx, x, v, ycs+cs+1, 0, 1);
				}
				if (can[nx]){
					cs+=aps[nx];
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		for (int nx:g[x]){
			if (nx!=p){
				dfs2(nx, x, v, 0, 0, 0);
			}
		}
	}
}

int test(int x){
	gg=0;
	dfs1(1, 0, x);
	dfs2(1, 0, x, 0, 0, 1);
	return gg;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>k;
	int v=2e6;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		v=min(v, a[i]);
	}
	for (int i=0;i<n-1;i++){
		int aa,b;
		cin>>aa>>b;
		g[aa].push_back(b);
		g[b].push_back(aa);
	}
	int mi=0;
	int ma=1e6+1;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (test(mid)){
			v=max(v, mid);
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	cout<<v<<endl;
}