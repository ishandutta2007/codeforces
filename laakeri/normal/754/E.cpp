#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;
const ld PI=atan2((ld)0, (ld)-1);
void fft(vector<co>&a, int n, int k) {
	vector<co> ww(n);
	ww[1]=co(1, 0);
	for (int t=0;t<k-1;t++) {
		co c=polar((ld)1, PI/n*(1<<(k-1-t)));
		int p2=(1<<t),p3=p2*2;
		for (int j=p2;j<p3;j++) ww[j*2+1]=(ww[j*2]=ww[j])*c;
	}
	for (int i=0;i<n;i++) {
		int u=0;
		for (int j=1;j<n;j*=2) {u*=2;if (i&j) u++;}
		if (i<u) swap(a[i], a[u]);
	}
	for (int l=1;l<n;l*=2) {
		for (int i=0;i<n;i+=l) {
			for (int it=0,j=i+l,w=l;it<l;it++,i++,j++) {
				co t=a[j]*ww[w++];
				a[j]=a[i]-t;
				a[i]=a[i]+t;
			}
		}
	}
}
vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {
	int as=a.size(), bs=b.size();
	if (as*bs==0) return {};
	int k=0;
	while ((1<<k)<as+bs-1) k++;
	int n=1<<k;
	vector<co> c(n+1);
	for (int i=0;i<n;i++) {
		if (i<as) c[i]=a[i];
		if (i<bs) c[i]={c[i].real(), (ld)b[i]};
	}
	fft(c, n, k);
	c[n]=c[0];
	for (int i=0;i<=n-i;i++) {
		c[i]=conj(c[i]*c[i]-conj(c[n-i]*c[n-i]))*co(0,(ld)1/n/4);
		c[n-i]=conj(c[i]);
	}
	fft(c, n, k);
	vector<ll> r(as+bs-1);
	for (int i=0;i<as+bs-1;i++) r[i]=round(c[i].real());
	return r;
}

int n,m;
int r,c;

string t[844];
string p[444];

ll v[444];

vector<int> get(){
	vector<ll> tt(n*m);
	vector<ll> pt(n*m);
	for (int cc='a';cc<='z';cc++){
		v[cc]=rand()%50000;
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			tt[i*m+ii]=v[t[i][ii]];
		}
	}
	ll h=0;
	for (int i=0;i<r;i++){
		for (int ii=0;ii<c;ii++){
			if (p[i][ii]!='?') {
				pt[i*m+ii]=v[p[i][ii]];
				h+=v[p[i][ii]]*v[p[i][ii]];
			}
		}
	}
	reverse(tt.begin(), tt.end());
	auto ct=conv(tt, pt);
	vector<int> ret(n*m);
	for (int i=0;i<(int)ct.size();i++){
		if (ct[i]==h) {
			int c0=(int)ct.size()-i-n*m;
			int y=c0/m;
			int x=c0%m;
			if (y>=0&&x>=0&&y+r<=n&&x+c<=m){
				ret[y*m+x]=1;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>t[i];
	}
	int n0=n;
	int m0=m;
	n=800;
	m=800;
	for (int i=0;i<n;i++){
		t[i].resize(m);
		for (int ii=0;ii<m;ii++){
			t[i][ii]=t[i%n0][ii%m0];
		}
	}
	cin>>r>>c;
	for (int i=0;i<r;i++){
		cin>>p[i];
	}
	vector<int> ans(n*m);
	for (int i=0;i<(int)ans.size();i++) ans[i]=1;
	for (int tc=0;tc<2;tc++){
		auto nans=get();
		for (int i=0;i<(int)ans.size();i++){
			ans[i]=ans[i]&&nans[i];
		}
	}
	vector<int> rans(n0*m0);
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (ans[i*m+ii]){
				rans[(i%n0)*m0+(ii%m0)]=1;
			}
		}
	}
	for (int i=0;i<n0;i++){
		for (int ii=0;ii<m0;ii++){
			cout<<rans[i*m0+ii];
		}
		cout<<'\n';
	}
}