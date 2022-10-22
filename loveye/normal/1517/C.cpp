#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 505;
int n,p[N],ans[N][N];
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",p+i),ans[i][i] = p[i];
	fr(i,1,n) {
		bool fl = 1;
		fr(j,1,n-i) if(fl) {
			if(ans[j+i-1][j] == i) {
				fl = 0;
				ans[j+i][j] = ans[j+i][j+1];
			}
			else ans[j+i][j] = ans[j+i-1][j];
		} else {
			ans[j+i][j] = ans[j+i][j+1];
		}
	}
	fr(i,1,n) fr(j,1,i) printf("%d%c",ans[i][j]," \n"[j == i]);
	return 0;
}