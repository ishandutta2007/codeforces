#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI=atan2(0, -1);

const int N=1<<17;
ll st[2*N];

ll getmax(int a, int b){
	a+=N;
	b+=N;
	ll m=0;
	while (a<=b){
		if (a%2) m=max(m, st[a++]);
		if (!(b%2)) m=max(m, st[b--]);
		a/=2;
		b/=2;
	}
	return m;
}

void setmax(int i, ll v){
	for (i+=N;i;i/=2){
		st[i]=max(st[i], v);
	}
}

ll r[101010];
int o[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> cc;
	for (int i=0;i<n;i++){
		ld a,b;
		cin>>a>>b;
		r[i]=b*a*a;
		cc.push_back(r[i]);
	}
	sort(cc.begin(), cc.end());
	cc.erase(unique(cc.begin(), cc.end()), cc.end());
	ll v=0;
	for (int i=0;i<n;i++){
		int k=lower_bound(cc.begin(), cc.end(), r[i])-cc.begin();
		ll tv=getmax(0, k-1)+r[i];
		v=max(v, tv);
		setmax(k, tv);
	}
	cout<<setprecision(15)<<(ld)PI*v<<endl;
}