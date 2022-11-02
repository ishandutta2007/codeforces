#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dg[1010];
vector<int> g[1010];

int qr=0;

void ask(int x){
	if (dg[x]) return;
	assert(x>0);
	qr++;
	cout<<"? "<<x<<endl;
	cin>>dg[x];
	if (dg[x]==0) {
		exit(0);
	}
	for (int i=0;i<dg[x];i++){
		int nx;
		cin>>nx;
		g[x].push_back(nx);
	}
}

void ans(int x){
	assert(x>0);
	cout<<"! "<<x<<endl;
}

void solve(){
	int h;
	cin>>h;
	qr=0;
	if (h==0){
		exit(0);
	}
	int n=(1<<h)-1;
	for (int i=0;i<=n;i++){
		dg[i]=0;
		g[i].clear();
	}
	
	ask(1);
	if (dg[1]==2){
		ans(1);
		return;
	}
	vector<int> path;
	path.push_back(1);
	int t=1;
	while (1){
		int ne=0;
		for (int nx:g[t]){
			if (dg[nx]==0){
				ne=nx;
				break;
			}
		}
		ask(ne);
		if (dg[ne]==2){
			ans(ne);
			return;
		}
		path.push_back(ne);
		if (dg[ne]==1){
			if (dg[path[0]]==1){
				break;
			}
			else{
				reverse(path.begin(), path.end());
				t=path.back();
			}
		}
		else{
			t=ne;
		}
	}
	assert(dg[path[0]]==1&&dg[path.back()]==1);
	
	int de=((int)path.size()+1)/2;
	int rs=path[de-1];
	while (de<h-3){
		path.resize(de);
		t=path.back();
		while (1){
			int ne=0;
			for (int nx:g[t]){
				if (dg[nx]==0){
					ne=nx;
					break;
				}
			}
			ask(ne);
			if (dg[ne]==2){
				ans(ne);
				return;
			}
			path.push_back(ne);
			if (dg[ne]==1){
				break;
			}
			t=ne;
		}
		assert(((int)path.size()+1)/2>de);
		de=((int)path.size()+1)/2;
		rs=path[de-1];
	}
	for (int nx:g[rs]){
		if (dg[nx]==0){
			rs=nx;
			break;
		}
	}
	ask(rs);
	if (dg[rs]==2){
		ans(rs);
		return;
	}
	de++;
	if (de==h-2){
		vector<int> d2;
		for (int nx:g[rs]){
			if (dg[nx]==0){
				ask(nx);
				if (dg[nx]==2){
					ans(nx);
					return;
				}
				for (int nxx:g[nx]){
					if (dg[nxx]==0){
						d2.push_back(nxx);
					}
				}
			}
		}
		int lol=d2.back();
		d2.pop_back();
		for (int x:d2){
			if (dg[x]==0){
				ask(x);
				if (dg[x]==2){
					ans(x);
					return;
				}
			}
		}
		ans(lol);
	}
	else if (de==h-1){
		vector<int> d2;
		for (int nx:g[rs]){
			if (dg[nx]==0){
				d2.push_back(nx);
			}
		}
		int lol=d2.back();
		d2.pop_back();
		for (int x:d2){
			if (dg[x]==0){
				ask(x);
				if (dg[x]==2){
					ans(x);
					return;
				}
			}
		}
		ans(lol);
	}
	else{
		assert(0);
	}
}

int main(){
	int tcs;
	cin>>tcs;
	for (int tc=1;tc<=tcs;tc++){
		solve();
	}
}