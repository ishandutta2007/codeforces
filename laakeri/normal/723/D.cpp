#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

string s[55];
int n,m;

int u[55][55];

int go(int y, int x, vector<pair<int, int> >&ps){
	if (y<0||y>=n||x<0||x>=m) return 1;
	if (s[y][x]=='*') return 0;
	if (u[y][x]) return 0;
	u[y][x]=1;
	ps.push_back({y, x});
	int r=0;
	for (int i=-1;i<=1;i++){
		for (int ii=-1;ii<=1;ii++){
			if ((i==0)^(ii==0)){
				r|=go(y+i, x+ii, ps);
			}
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	vector<pair<int, vector<pair<int, int> > > > ls;
	int la=0;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (u[i][ii]) continue;
			vector<pair<int, int> > ps;
			int asd=go(i, ii, ps);
			if (asd==0){
				la++;
				ls.push_back({ps.size(), ps});
			}
		}
	}
	sort(ls.begin(), ls.end());
	int v=0;
	for (int i=0;i<la-k;i++){
		for (auto t:ls[i].S){
			v++;
			s[t.F][t.S]='*';
		}
	}
	cout<<v<<endl;
	for (int i=0;i<n;i++){
		cout<<s[i]<<endl;
	}
}