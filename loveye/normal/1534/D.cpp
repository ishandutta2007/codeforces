#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2005;
int n,a[N],b[N];
vector<pair<int,int> > ans;
int main() {
	cin >> n;
	cout << "? 1" << endl;
	int cnt[2] = {0};
	fr(i,1,n) {
		cin >> a[i];
		cnt[a[i] & 1] += 1;
	}
	--cnt[0];
	int flag = (cnt[0] < cnt[1] ? 0 : 1);
	if(!flag) {
		fr(i,1,n) if(a[i] == 1) ans.push_back(make_pair(1,i));
	}
	fr(i,1,n) if((a[i] & 1) == flag) {
		if(flag == 0 && i == 1) continue;
		cout << "? " << i << endl;
		fr(j,1,n) {
			cin >> b[j];
			if(b[j] == 1) ans.push_back(make_pair(i,j));
		}
	}
	cout << "!" << endl;
	fo(i,0,n-1) cout << ans[i].first << ' ' << ans[i].second << endl;
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