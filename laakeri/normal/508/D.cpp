// Finds Euler tour of graph in O(E) time

// Parameters are the adjacency list, number of nodes, 
// return value vector, and d=1 if the graph is directed
// Return array contains E+1 elements, the first and last
// elements are same

// Undefined behavior if Euler tour doesn't exist

// Note that Eulerian path can be reduced to Euler tour
// by adding an edge from the last vertex to the first

// In bidirectional graph edges must be in both direction
// Be careful to not add loops twice in case of bidirectional graph
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct EulerTour {
	int dir;
	vector<vector<pair<int, int> > > g;
	vector<int> used;
	
	void dfs(int x, vector<int>& ret) {
		int t=x;
		vector<int> c;
		while (1) {
			while (used[g[t].back().S]) g[t].pop_back();
			auto nx=g[t].back();
			g[t].pop_back();
			used[nx.S]=1;
			t=nx.F;
			c.push_back(t);
			if (t==x) break;
		}
		for (int a:c) {
			ret.push_back(a);
			while (g[a].size()>0&&used[g[a].back().S]) g[a].pop_back();
			if (g[a].size()>0) dfs(a, ret);
		}
	}
	
	EulerTour(vector<int>* og, int n, vector<int>& ret, int d=0) : dir(d), g(n+1) {
		int i2=0;
		for (int i=1;i<=n;i++) {
			for (int nx:og[i]) {
				if (d==1||nx<=i) {
					if (d==0&&nx<i) {
						g[nx].push_back({i, i2});
					}
					g[i].push_back({nx, i2++});
				}
			}
		}
		used.resize(i2);
		for (int i=1;i<=n;i++) {
			if (g[i].size()>0) {
				ret.push_back(i);
				dfs(i, ret);
				break;
			}
		}
	}
};

void nie(){
	cout<<"NO"<<endl;
	exit(0);
}

vector<int> g[101010];
int from[101010];
int to[101010];

int main() {
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		int a=s[0]*300+s[1];
		int b=s[1]*300+s[2];
		g[a].push_back(b);
		from[a]++;
		to[b]++;
	}
	int sv=0;
	int ev=0;
	for (int i=1;i<=100000;i++){
		if (from[i]<to[i]){
			if (from[i]==to[i]-1){
				if (ev>0) nie();
				ev=i;
			}
			else{
				nie();
			}
		}
		if (to[i]<from[i]){
			if (to[i]==from[i]-1){
				if (sv>0) nie();
				sv=i;
			}
			else{
				nie();
			}
		}
	}
	if (sv==0&&ev==0){
		vector<int> t;
		EulerTour(g, 100000, t, 1);
		if (t.size()!=n+1) nie();
		cout<<"YES\n";
		for (int tt:t){
			cout<<(char)(tt/300);
		}
		cout<<(char)(t.back()%300);
	}
	else if(sv>0&&ev>0){
		g[ev].push_back(sv);
		vector<int> t;
		EulerTour(g, 100000, t, 1);
		if (t.size()!=n+2) nie();
		t.pop_back();
		int sk=0;
		//cout<<ev<<" "<<sv<<endl;
		for (int i=0;i<(int)t.size();i++){
			//cout<<i<<" "<<(char)(t[i]/300)<<" "<<(char)(t[i]%300)<<endl;
			if (t[i]==ev&&t[(i+1)%(int)t.size()]==sv){
				sk=(i+1)%(int)t.size();
				//break;
			}
		}
		cout<<"YES\n";
		//cout<<sk<<" "<<t.size()<<endl;
		for (int i=0;i<(int)t.size();i++){
			cout<<(char)(t[(i+sk)%(int)t.size()]/300);
		}
		cout<<(char)(ev%300);
	}
	else{
		nie();
	}
	cout<<endl;
}