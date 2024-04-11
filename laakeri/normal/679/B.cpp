#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll cb(ll x){
	return x*x*x;
}

const ll C=30e6;

char v[C+10];
char bv[C+10];
int bvi[C+10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll m;
	cin>>m;
	int vv=1;
	ll vvk=1;
	ll bx=0;
	for (ll i=1;i<=min(C, m);i++){
		while (i-cb(bx+1)>=0) bx++;
		v[i]=v[i-cb(bx)]+1;
		if (v[i]>vv||(v[i]==vv&&i>vvk)){
			vv=v[i];
			vvk=i;
		}
		bv[i]=bv[i-1];
		bvi[i]=bvi[i-1];
		if (v[i]>=bv[i]){
			bv[i]=v[i];
			bvi[i]=i;
		}
	}
	for (ll t1=1;cb(t1)<=m;t1++){
		if (2*cb(t1)<=m) continue;
		for (ll t2=1;cb(t1)+cb(t2)<=m&&t2<=6020;t2++){
			if (cb(t2)+cb(t1)>=cb(t1+1)) break;
			ll le = cb(t1+1)-cb(t2)-cb(t1)-1;
			le=min(le, m-cb(t2)-cb(t1));
			le=min(le, cb(t2+1)-cb(t2)-1);
			if (le>=C||le>=m||le<0) continue;
			if (bv[le]+2>vv || (bv[le]+2==vv&&(ll)bvi[le]+cb(t2)+cb(t1)>vvk)){
				//cout<<t1<<" "<<t2<<" "<<le<<endl;
				vv=bv[le]+2;
				vvk=(ll)bvi[le]+cb(t2)+cb(t1);
			}
		}
	}
	cout<<vv<<" "<<vvk<<endl;
	/*
	ll lol=0;
	while (2*cb(lol)<=m) lol++;
	ll e=1;
	for (ll i=1;i<=min(C, m);i++){
		if (v[i]>=e&&v[i]+2>=vv){
			ll t2=0;
			for (ll t1=lol-1;cb(t1)<=m;t1++){
				if (i+cb(t1)>=cb(t1+1)) continue;
				while (i+cb(t2+1)+cb(t1)<=m && i+cb(t2+1)+cb(t1)<cb(t1+1)) {
					t2++;
					if (cb(t2)>m) break;
				}
				if (i+cb(t2)>=cb(t2+1)) continue;
				if (i+cb(t2)+cb(t1)>m){
					break;
				}
				if (i+cb(t2)+cb(t1)>=cb(t1+1)) {
					break;
				}
				ll a=i+cb(t2)+cb(t1);
				if (v[i]+2>vv||(v[i]+2==vv&&a>vvk)){
					vv=v[i]+2;
					vvk=a;
				}
				ll mi=1;
				ll ma=t1;
				ll mk=0;
				while (mi<=ma){
					ll mid=(mi+ma)/2;
					if (i+cb(mid)+cb(t1)>m){
						ma=mid-1;
						continue;
					}
					if (i+cb(mid)+cb(t1)>=cb(t1+1)) {
						ma=mid-1;
						continue;
					}
					mi=mid+1;
					mk=max(mk, mid);
					if (i+cb(mid)>=cb(mid+1)) continue;
					ll a=i+cb(mid)+cb(t1);
					if (v[i]+2>vv||(v[i]+2==vv&&a>vvk)){
						vv=v[i]+2;
						vvk=a;
					}
				}
				cout<<mk<<endl;
			}
			//cout<<endl;
			//cout<<okmi<<" "<<okma<<endl;
			//f++;
		}
		e=max(e, v[i]);
	}
	*/
	//cout<<f<<endl;
	//cout<<v[C]<<endl;
}