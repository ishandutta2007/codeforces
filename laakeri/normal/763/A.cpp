#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int c[101010];
vector<int> g[101010];

int cv=0;
int f=0;

int dfs(int x, int p){
	int tc=c[x];
	for (int nx:g[x]){
		if (nx!=p){
			int asd=dfs(nx, x);
			if (asd!=tc){
				if (f==0){
					cv=x;
					f=1;
				}
			}
		}
	}
	return tc;
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
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1, 0);
	if (cv==0){
		cout<<"YES"<<endl;
		cout<<1<<endl;
		return 0;
	}
	int r=cv;
	for (int nx:g[r]){
		cv=0;
		f=0;
		dfs(nx, r);
		if (f){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	cout<<r<<endl;
}