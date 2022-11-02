#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string s[55];

int n,m;

int test(vector<pair<int, int> > dirs, string st){
	int y,x;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (s[i][ii]=='S'){
				y=i;
				x=ii;
			}
		}
	}
	for (char c:st){
		y+=dirs[c-'0'].F;
		x+=dirs[c-'0'].S;
		if (y<0||x<0||y>=n||x>=m) return 0;
		if (s[y][x]=='E') return 1;
		if (s[y][x]=='#') return 0;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	string st;
	cin>>st;
	vector<pair<int, int> > dirs={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	sort(dirs.begin(), dirs.end());
	int v=0;
	while (1){
		v+=test(dirs, st);
		if (!next_permutation(dirs.begin(), dirs.end())) break;
	}
	cout<<v<<endl;
}