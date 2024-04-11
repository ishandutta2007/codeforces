#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<17;
pair<int, int> st[2*N];

pair<int, int> getmax(int a, int b){
	a+=N;
	b+=N;
	pair<int, int> ma={0, 0};
	while (a<=b){
		if (a%2) ma=max(ma, st[a++]);
		if (!(b%2)) ma=max(ma, st[b--]);
		a/=2;
		b/=2;
	}
	return ma;
}

ll qr(int a, int b){
	if (a>b) return 0;
	pair<int, int> t=getmax(a, b);
	//cout<<a<<" "<<b<<" "<<t.F<<" "<<t.S<<endl;
	if (t.F==0) return 0;
	ll le=t.S-a;
	ll ri=b-t.S;
	return (ll)t.F*(ll)(le*ri+ri+le+1ll)+qr(a, t.S-1)+qr(t.S+1, b);
}

int a[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=1;i<n;i++){
		st[i+N]={abs(a[i]-a[i-1]), i};
	}
	for (int i=N-1;i>0;i--){
		st[i]=max(st[i*2], st[i*2+1]);
	}
	for (int qq=0;qq<q;qq++){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		l++;
		cout<<qr(l, r)<<'\n';
	}
}