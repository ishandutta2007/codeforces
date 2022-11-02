#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m;
int u[101010];
vector<int> uh[101010];

int getu(int a){
	if (u[a]==a) return a;
	return u[a]=getu(u[a]);
}

void un(int a, int b){
	a=getu(a);
	b=getu(b);
	if (a==b) return;
	if ((int)uh[a].size()<(int)uh[b].size()){
		for (int t:uh[a]){
			uh[b].push_back(t);
		}
		uh[a].clear();
		u[a]=b;
	}
	else{
		for (int t:uh[b]){
			uh[a].push_back(t);
		}
		uh[b].clear();
		u[b]=a;
	}
}

vector<int> gg[101010];
int col[101010];
vector<int> c1;
vector<int> c2;
int f=0;

void dfs(int x, int c){
	if (col[x]){
		if (col[x]!=c){
			f=1;
		}
		return;
	}
	col[x]=c;
	if (c==1) {
		for (int xx:uh[x]){
			c1.push_back(xx);
		}
	}
	else {
		for (int xx:uh[x]){
			c2.push_back(xx);
		}
	}
	for (int nx:gg[x]){
		dfs(nx, 3-c);
	}
}

vector<int> solve(vector<pair<pair<int, int>, char> > es){
	for (int i=1;i<=n;i++){
		u[i]=i;
		uh[i].clear();
		uh[i].push_back(i);
		gg[i].clear();
		col[i]=0;
	}
	for (int i=0;i<m;i++){
		if (es[i].S=='B'){
			un(es[i].F.F, es[i].F.S);
		}
	}
	for (int i=0;i<m;i++){
		if (es[i].S=='R'){
			gg[getu(es[i].F.F)].push_back(getu(es[i].F.S));
			gg[getu(es[i].F.S)].push_back(getu(es[i].F.F));
		}
	}
	vector<int> v;
	for (int i=1;i<=n;i++){
		if (col[i]==0){
			c1.clear();
			c2.clear();
			f=0;
			dfs(i, 1);
			if (f) return {-1};
			if ((int)c2.size()<(int)c1.size()) swap(c1, c2);
			for (int t:c1){
				v.push_back(t);
			}
		}
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<pair<pair<int, int>, char> > es(m);
	for (int i=0;i<m;i++){
		cin>>es[i].F.F>>es[i].F.S>>es[i].S;
	}
	auto v1=solve(es);
	if ((int)v1.size()==0){
		cout<<0<<endl;
		return 0;
	}
	for (int i=0;i<m;i++){
		if (es[i].S=='B') es[i].S='R';
		else es[i].S='B';
	}
	auto v2=solve(es);
	if ((int)v2.size()==0){
		cout<<0<<endl;
		return 0;
	}
	vector<int> v;
	if (v1[0]==-1) v=v2;
	else if(v2[0]==-1) v=v1;
	else if((int)v1.size()<(int)v2.size()) v=v1;
	else v=v2;
	if (v[0]==-1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<v.size()<<endl;
	for (int t:v){
		cout<<t<<" ";
	}
	cout<<endl;
}