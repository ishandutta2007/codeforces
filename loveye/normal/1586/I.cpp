#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2005;
int n;
char s[N][N],ops[128];
void output() {
	cout << endl;
	rf(i,n,1) {
		fr(j,1,n) if(i + j & 1) cout << s[i][j];
		else cout << ' ';
		cout << endl;
	}
	cout << endl;
	rf(i,n,1) {
		fr(j,1,n) if(~(i + j) & 1) cout << s[i][j];
		else cout << ' ';
		cout << endl;
	}
	cout << endl;
}
void upd1() {
	fr(x,2,n) fr(y,1,n-1) if((~(x + y) & 1) && s[x][y] == '.' && s[x-1][y+1] != '.')
		s[x][y] = ops[s[x-1][y+1]];
}
void upd2() {
	rf(x,n-1,1) rf(y,n,2) if((~(x + y) & 1) && s[x][y] == '.' && s[x+1][y-1] != '.')
		s[x][y] = ops[s[x+1][y-1]];
}
void upd3() {
	fr(x,2,n) fr(y,2,n) if((x + y & 1) && s[x][y] == '.' && s[x-1][y-1] != '.')
		s[x][y] = ops[s[x-1][y-1]];
}
void upd4() {
	rf(x,n-1,1) rf(y,n-1,1) if((x + y & 1) && s[x][y] == '.' && s[x+1][y+1] != '.')
		s[x][y] = ops[s[x+1][y+1]];
}
int upd5() {
	for(int i = 1;i <= n;i += 2) if(s[1][i] != s[1][i+1]) {
		if(s[1][i] == '.') s[1][i] = s[1][i+1];
		else if(s[1][i+1] == '.') s[1][i+1] = s[1][i];
		else return 0;
	}
	for(int i = 1;i <= n;i += 2) if(s[i][n] != s[i+1][n]) {
		if(s[i][n] == '.') s[i][n] = s[i+1][n];
		else if(s[i+1][n] == '.') s[i+1][n] = s[i][n];
		else return 0;
	}
	for(int i = 1;i <= n;i += 2) if(s[n][i] != s[n][i+1]) {
		if(s[n][i] == '.') s[n][i] = s[n][i+1];
		else if(s[n][i+1] == '.') s[n][i+1] = s[n][i];
		else return 0;
	}
	for(int i = 1;i <= n;i += 2) if(s[i][1] != s[i+1][1]) {
		if(s[i][1] == '.') s[i][1] = s[i+1][1];
		else if(s[i+1][1] == '.') s[i+1][1] = s[i][1];
		else return 0;
	}
	return 1;
}
int work(int job) {
	if(!upd5()) return 0;
	if(job) upd1();
	if(!upd5()) return 0;
	if(job) upd3();
	if(!upd5()) return 0;
	if(job) upd2();
	if(!upd5()) return 0;
	if(job) upd4();
	if(!upd5()) return 0;
	return 1;
}
const int gox[] = {0,1,0,-1},goy[] = {1,0,-1,0};
int solve() {
	upd1(); upd2(); upd3(); upd4();
	if(!work(1)) return 0;
	if(!work(1)) return 0;
	if(!work(1)) return 0;
	if(!work(1)) return 0;
	fr(x,2,n) fr(y,1,n-1) if((~(x + y) & 1) && s[x][y] != '.' && s[x-1][y+1] == s[x][y])
		return 0;
	fr(x,2,n) fr(y,2,n) if((x + y & 1) && s[x][y] != '.' && s[x-1][y-1] == s[x][y])
		return 0;
	if(!work(0)) return 0;
	fr(x,1,n) fr(y,1,n) if(s[x][y] == '.') return 2;
	fr(x,1,n) fr(y,1,n) {
		int cnt = 0;
		fo(i,0,4) if(s[x][y] == s[x+gox[i]][y+goy[i]])
			++cnt;
		if(cnt != 2) {
			cout << x << ' ' << y << ' ' << s[x][y] << ' ';
			fo(i,0,4) cout << x+gox[i] << ' ' << y+goy[i] << ' ' << s[x+gox[i]][y+goy[i]] << ' ';
			cout << endl;
			exit(0);
		}
	}
	return 1;
}
int main() {
	ops['S'] = 'G'; ops['G'] = 'S';
	cin >> n;
	fr(i,1,n) cin >> &s[i][1];
	if(n & 1) return cout << "NONE" << endl,0;
	int ans = solve();
	if(ans == 1) {
		cout << "UNIQUE" << endl;
		fr(i,1,n) cout << &s[i][1] << endl;
	} else cout << (ans ? "MULTIPLE" : "NONE") << endl;
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}