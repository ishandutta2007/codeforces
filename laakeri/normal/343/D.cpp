#include <bits/stdc++.h>
using namespace std;

vector<int> g[505050];
int l[505050];
int r[505050];
const int N=1<<20;
int st1[2*N];
int st2[2*N];
void setmax1(int i, int v){
	for (i+=N;i;i/=2){
		st1[i]=max(st1[i], v);
	}
}
int getmax1(int a, int b){
	a+=N;
	b+=N;
	int m=0;
	while (a<=b){
		if (a%2) m=max(m, st1[a++]);
		if (!(b%2)) m=max(m, st1[b--]);
		a/=2;
		b/=2;
	}
	return m;
}
void setmax2(int a, int b, int v){
	a+=N;
	b+=N;
	while (a<=b){
		if (a%2){
			st2[a]=max(st2[a], v);
			a++;
		}
		if (!(b%2)) {
			st2[b]=max(st2[b], v);
			b--;
		}
		a/=2;
		b/=2;
	}
}
int getmax2(int i){
	int m=0;
	for (i+=N;i;i/=2){
		m=max(m, st2[i]);
	}
	return m;
}
int i2=0;
void dfs(int x, int p){
	l[x]=i2++;
	for (int nx:g[x]){
		if (nx!=p){
			dfs(nx, x);
		}
	}
	r[x]=i2++;
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
	dfs(1, 0);
	int q;
	cin>>q;
	for (int i=1;i<=q;i++){
		int c,v;
		cin>>c>>v;
		if (c==1){
			setmax2(l[v], r[v], i);
		}
		if (c==2){
			setmax1(l[v], i);
		}
		if (c==3){
			int a=getmax2(l[v]);
			if (a>0){
				if (getmax1(l[v], r[v])<a){
					cout<<"1\n";
				}
				else{
					cout<<"0\n";
				}
			}
			else{
				cout<<"0\n";
			}
		}
	}
}