#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<17;

int st[2*N];

void setv(int i, int v){
	for (i+=N;i;i/=2){
		st[i]=min(st[i], v);
	}
}

const int inf=1e9;

int getmin(int a, int b){
	a+=N;
	b+=N;
	int mi=2*inf;
	while (a<=b){
		if (a%2) mi=min(mi, st[a++]);
		if (!(b%2)) mi=min(mi, st[b--]);
		a/=2;
		b/=2;
	}
	return mi;
}

int n;
int a[101010];
int ans[303030];
int ok[303030];
int l[303030];
int r[303030];

int b[303030];
int e[303030];
unordered_map<int, vector<int> > bp;

void solve(int x, vector<pair<pair<int, int>, int> >& qq, int ofs){
	bp.clear();
	int i2=0;
	for (int i=0;i<2*N;i++){
		st[i]=2*inf;
	}
	for (int i=1;i<=n;i++){
		b[i]=(a[i]+ofs)/x;
		bp[b[i]].push_back(i);
		vector<int>& t=bp[b[i]];
		for (int j=(int)t.size()-2;j>=max(0, (int)t.size()-3);j--){
			setv(t[j], abs(a[i]-a[t[j]]));
		}
		while (i2<(int)qq.size()&&qq[i2].F.S<=i){
			if (ok[qq[i2].S]==0||ok[qq[i2].S]*2>=x){
				int asd=getmin(qq[i2].F.F, qq[i2].F.S);
				if (asd<=inf){
					if (ok[qq[i2].S]==0) ok[qq[i2].S]=x;
					ans[qq[i2].S]=min(ans[qq[i2].S], asd);
				}
			}
			i2++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	vector<pair<pair<int, int>, int> > qqq;
	for (int i=0;i<m;i++){
		cin>>l[i]>>r[i];
		ans[i]=(int)1e9;
		qqq.push_back({{l[i], r[i]}, i});
	}
	auto cmp=[](pair<pair<int, int>, int> aa, pair<pair<int, int>, int> bb){
		return aa.F.S<bb.F.S;
	};
	sort(qqq.begin(), qqq.end(), cmp);
	for (int bs=1;bs<=(int)1e9;bs*=2){
		vector<pair<pair<int, int>, int> > qq;
		for (int i=0;i<m;i++){
			if (ok[qqq[i].S]==0||ok[qqq[i].S]==bs/2){
				qq.push_back(qqq[i]);
			}
		}
		solve(bs, qqq, 0);
		solve(bs, qqq, bs/2);
	}
	vector<pair<pair<int, int>, int> > qq;
	for (int i=0;i<m;i++){
			qq.push_back(qqq[i]);
	}
	solve((int)1e9+2, qq, 0);
	for (int i=0;i<m;i++){
		cout<<ans[i]<<'\n';
	}
}