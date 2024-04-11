#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=209;

int T,n,cnt[2][2];
char c[N][N];
bool f[N][N][2];
vector<pair<int,int> >ans;

void chp(int x,int y,int val) {
	if(c[x][y]!=val+'0') ans.push_back(make_pair(x,y));
}

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		rep(i,1,n) scanf("%s",c[i]+1);
		f[1][1][0]=f[1][1][1]=1;
		rep(i,1,n) rep(j,1,n) if(i!=1||j!=1) {
			f[i][j][1]=(f[i-1][j][1]&&c[i-1][j]!='0')||(f[i][j-1][1]&&c[i][j-1]!='0');
			f[i][j][0]=(f[i-1][j][0]&&c[i-1][j]!='1')||(f[i][j-1][0]&&c[i][j-1]!='1');
		}
		memset(cnt,0,sizeof(cnt));
		cnt[0][c[1][2]-'0']++, cnt[0][c[2][1]-'0']++, cnt[1][c[n][n-1]-'0']++, cnt[1][c[n-1][n]-'0']++;
		ans.clear();
		if(f[n][n][0]&&f[n][n][1]||cnt[0][0]==1&&cnt[0][1]==1&&cnt[1][0]==1) chp(n,n-1,0), chp(n-1,n,0), chp(1,2,1), chp(2,1,1);
		else if(f[n][n][1]&&!f[n][n][0]) {
			if(c[1][2]!='0'&&c[2][1]!='0') chp(n,n-1,0), chp(n-1,n,0);
			else chp(1,2,0), chp(2,1,0);
		} else if(f[n][n][0]&&!f[n][n][1]) {
			if(c[1][2]!='1'&&c[2][1]!='1') chp(n,n-1,1), chp(n-1,n,1);
			else chp(1,2,1), chp(2,1,1);
		}
		printf("%d\n",(int)(ans.size()));
		if(ans.size()) rep(i,0,ans.size()-1) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}