#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];
int apl[202020];

void dfs1(int x, int p){
	for (int nx:g[x]){
		if (nx!=p){
			dfs1(nx, x);
			apl[x]=max(apl[x], apl[nx]+1);
		}
	}
}

int di=0;
vector<int> dv;

void dfs2(int x, int p, int pl){
	int ma1=pl;
	int mav=0;
	int ma2=0;
	for (int nx:g[x]){
		if (nx!=p){
			if (apl[nx]+1>ma1){
				ma2=ma1;
				ma1=apl[nx]+1;
				mav=nx;
			}
			else if(apl[nx]+1>ma2){
				ma2=apl[nx]+1;
			}
		}
	}
	if (ma1+ma2>di){
		di=ma1+ma2;
		dv.clear();
	}
	if (ma1+ma2==di&&abs(ma1-ma2)<=1){
		dv.push_back(x);
	}
	for (int nx:g[x]){
		if (nx!=p){
			if (nx==mav){
				dfs2(nx, x, ma2+1);
			}
			else{
				dfs2(nx, x, ma1+1);
			}
		}
	}
}

int ans;

int dfs3(int x, int p, int d, int r){
	if ((int)g[x].size()==1){
		return d;
	}
	set<int> le;
	for (int nx:g[x]){
		if (nx!=p){
			int asd=dfs3(nx, x, d+1, r);
			if (asd==-1) return -1;
			le.insert(asd);
		}
	}
	assert((int)le.size()>0);
	if (x==r){
		if ((int)le.size()>2){
			return -1;
		}
		else if((int)le.size()==2){
			int t=(*le.begin())+(*le.rbegin());
			while (t%2==0){
				t/=2;
			}
			ans=min(ans, t);
		}
		else if((int)le.size()==1){
			int t=(*le.begin());
			while (t%2==0){
				t/=2;
			}
			ans=min(ans, t);
		}
		return 0;
	}
	else{
		if ((int)le.size()>1){
			return -1;
		}
		return (*le.begin());
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int f=0;
	for (int i=1;i<=n;i++){
		if ((int)g[i].size()>2){
			f=i;
			break;
		}
	}
	if (f==0){
		int le=n-1;
		while (le%2==0){
			le/=2;
		}
		cout<<le<<endl;
		return 0;
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	ans=3*n;
	if (di%2==0){
		assert((int)dv.size()==1);
		dfs3(dv[0], 0, 0, dv[0]);
	}
	else{
		assert((int)dv.size()==2);
		dfs3(dv[0], 0, 0, dv[0]);
		dfs3(dv[1], 0, 0, dv[1]);
	}
	if (ans==3*n){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
}