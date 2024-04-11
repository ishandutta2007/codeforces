#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<18;
ll o[N];
ll st1[2*N];
ll st2[2*N];

void add(ll*st, int i, ll x){
	for (i+=N;i;i/=2){
		st[i]+=x;
	}
}

ll sum(ll*st, int a, int b){
	a+=N;
	b+=N;
	ll s=0;
	while (a<=b){
		if (a%2) s+=st[a++];
		if (!(b%2)) s+=st[b--];
		a/=2;
		b/=2;
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	ll a,b;
	int q;
	cin>>n>>k>>a>>b>>q;
	for (int i=0;i<q;i++){
		int ty;
		cin>>ty;
		if (ty==1){
			ll d,t;
			cin>>d>>t;
			ll na=min(b-o[d], t);
			ll nb=min(a-o[d], t);
			if (na<0) na=0;
			if (nb<0) nb=0;
			add(st1, d, na);
			add(st2, d, nb);
			o[d]+=t;
		}
		else{
			int p;
			cin>>p;
			cout<<sum(st1, 0, p-1)+sum(st2, p+k, N-1)<<'\n';
		}
	}
}