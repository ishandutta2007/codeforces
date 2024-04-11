#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int n, m;
#define N_  110

int P[N_], w[N_], tw[N_], T[N_], vis[N_], Num[N_];

void Calc(int x, int a){
	int r = 0;
	int s=  0;
	for(int i=x;i<=a;i++){
		s += w[i];
		r = min(r,s);
	}
	s = 0;
	for(int i=x;i>=a;i--){
		s += w[i];
		r = min(r,s);
	}
	T[x] = r;
}


bool Solve(int a){
	int i, j;
	vector<int>res;
	for(i=1;i<=n;i++){
		w[i] = tw[i];
		vis[i] = 0;
	}
	while(1){
		for(i=1;i<=n;i++)Calc(i, a);
		int Mn = 1e9, pv = -1;
		for(i=1;i<=n;i++){
			if(!vis[i] && P[i] && P[i] + T[i] >= 0){
				if(T[i] < Mn)Mn = T[i], pv = i;
			}
		}
		if(pv==-1)break;
		for(i=pv;i<=a;i++)w[i] = 0;
		for(i=pv;i>=a;i--)w[i] = 0;
		vis[pv] = 1;
		res.push_back(pv);
	}
	for(i=1;i<=n;i++)if(P[i]>0 && !vis[i])return false;
	printf("%d\n",a);
	for(auto &x : res)printf("%d ",Num[x]);
	puts("");
	return true;
}

int main(){
	int i, a, h;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&h);
		P[a] = h;
		Num[a] = i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		tw[i] = w[i];
	}
	for(i=1;i<=n;i++){
		if(Solve(i))return 0;
	}
	puts("-1");
}