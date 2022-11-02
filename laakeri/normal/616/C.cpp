#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

string s[1010];
int cc[1010][1010];
int ccs[1010101];

int i2=1;

int n,m;

int dfs(int i, int j, int c){
	if (i<0||j<0||i>=n||j>=m) return -1;
	if (s[i][j]=='*') return -1;
	if (cc[i][j]) return cc[i][j];
	cc[i][j]=c;
	ccs[c]++;
	dfs(i+1, j, c);
	dfs(i-1, j, c);
	dfs(i, j+1, c);
	dfs(i, j-1, c);
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			dfs(i, ii, i2++);
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (s[i][ii]=='*'){
				set<int> f;
				f.insert(dfs(i-1, ii, 0));
				f.insert(dfs(i+1, ii, 0));
				f.insert(dfs(i, ii-1, 0));
				f.insert(dfs(i, ii+1, 0));
				int su=1;
				for (int x:f){
					if (x>-1){
						su+=ccs[x];
					}
				}
				cout<<(char)('0'+(su%10));
			}
			else{
				cout<<'.';
			}
		}
		cout<<'\n';
	}
}