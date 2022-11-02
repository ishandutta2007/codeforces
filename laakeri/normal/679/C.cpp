#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string s[555];
set<int> ccs[555][555];
int cs[555*555];
int has[555*555];

int u[555][555];

int n;

void mk(int y, int x, int cc){
	if (y<0||y>=n||x<0||x>=n) return;
	ccs[y][x].insert(cc);
}

void dfs(int y, int x, int cc) {
	if (y<0||y>=n||x<0||x>=n) return;
	if (s[y][x]=='X') return;
	if (u[y][x]) return;
	u[y][x]=1;
	cs[cc]++;
	for (int i=-1;i<=1;i++){
		for (int ii=-1;ii<=1;ii++){
			if ((i==0)^(ii==0)){
				mk(y+i, x+ii, cc);
				dfs(y+i, x+ii, cc);
			}
		}
	}
}

int v=0;

int k;

int co=1;

int xc=0;
int hc=0;

void add(int y, int x){
	if (s[y][x]=='X') xc++;
	for (int c:ccs[y][x]){
		has[c]++;
		if (has[c]==1){
			hc+=cs[c];
		}
	}
}

void rm(int y, int x){
	if (s[y][x]=='X') xc--;
	for (int c:ccs[y][x]){
		has[c]--;
		if (has[c]==0){
			hc-=cs[c];
		}
	}
}

void go(int i){
	xc=0;
	hc=0;
	for (int j=0;j<=co;j++){
		has[j]=0;
	}
	for (int j=0;j<k;j++){
		for (int jj=0;jj<k;jj++){
			add(i+j, jj);
		}
	}
	v=max(v, hc+xc);
	for (int ii=1;ii+k<=n;ii++){
		for (int j=0;j<k;j++){
			rm(i+j, ii-1);
		}
		for (int j=0;j<k;j++){
			add(i+j, ii+k-1);
		}
		v=max(v, hc+xc);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	v=k*k;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			if (u[i][ii]==0&&s[i][ii]=='.') dfs(i, ii, co++);
		}
	}
	for (int i=0;i+k<=n;i++){
		go(i);
	}
	cout<<v<<endl;
}