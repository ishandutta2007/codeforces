#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5,K = 20;
int n,m,ans[N];
int a[N],l1[N],r1[N],l2[N],r2[N],s[N][2];
int sl1[K][N],sl2[K][N],sr1[K][N],sr2[K][N];
int from[N][2];
int chkl(int l,int r) {
	return r-l+1 == s[r][0]-s[l-1][0];
}
int chkr(int l,int r) {
	return r-l+1 == s[r][1]-s[l-1][1];
}
int main() {
	cin >> n >> m;
	fr(i,1,n) {
		cin >> a[i];
		cin >> sl1[0][i] >> sr1[0][i] >> sl2[0][i] >> sr2[0][i];
		s[i][0] = (sl1[0][i] <= a[i] && a[i] <= sr1[0][i]);
		s[i][1] = (sl2[0][i] <= a[i] && a[i] <= sr2[0][i]);
		s[i][0] += s[i-1][0];
		s[i][1] += s[i-1][1];
	}
	fr(k,1,17) fr(i,1,n-(1<<k)+1) {
		sl1[k][i] = max(sl1[k-1][i],sl1[k-1][i+(1<<k-1)]);
		sr1[k][i] = min(sr1[k-1][i],sr1[k-1][i+(1<<k-1)]);
		sl2[k][i] = max(sl2[k-1][i],sl2[k-1][i+(1<<k-1)]);
		sr2[k][i] = min(sr2[k-1][i],sr2[k-1][i+(1<<k-1)]);
	}
	int idl = 0,idr = 0;
	int frl = 0,frr = 0;
	memset(from,-1,sizeof from);
	fr(i,0,n) {
		int posl = -1,posr = -1;
		if(i <= idl) {
			from[i][0] = frl;
			posl = i+1;
			rf(j,17,0) if(posl + (1<<j) - 1 <= n && chkr(posl,posl+(1<<j)-1) && sl1[j][posl] <= a[i] && a[i] <= sr1[j][posl])
				posl += 1 << j;
		}
		if(i <= idr) {
			from[i][1] = frr;
			posr = i+1;
			rf(j,17,0) if(posr + (1<<j) - 1 <= n && chkl(posr,posr+(1<<j)-1) && sl2[j][posr] <= a[i] && a[i] <= sr2[j][posr])
				posr += 1 << j;
		}
		if(posl-1 > idr) idr = posl-1,frr = i;
		if(posr-1 > idl) idl = posr-1,frl = i;
	}
	if(from[n][0] != -1) {
		cout << "Yes" << endl;
		int pos = n,flag = 0;
		while(pos) {
			rf(i,pos,from[pos][flag])
				ans[i] = flag;
			pos = from[pos][flag];
			flag ^= 1;
		}
		fr(i,1,n) cout << ans[i] << ' ';
	} else if(from[n][1] != -1) {
		cout << "Yes" << endl;
		int pos = n,flag = 1;
		while(pos) {
			rf(i,pos,from[pos][flag])
				ans[i] = flag;
			pos = from[pos][flag];
			flag ^= 1;
		}
		fr(i,1,n) cout << ans[i] << ' ';
	} else cout << "No" << endl;
	return 0;
}