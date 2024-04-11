#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll st[101010];
ll a[101010];
ll oa[101010];

int n;

ll test(ll ms){
	int mi=0;
	int ma=n-1;
	int f=-1;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (a[mid]<ms){
			f=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	if (f==-1) return 0;
	return (ll)(f+1)*ms-st[f];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll A,cf,cm,m;
	cin>>n>>A>>cf>>cm>>m;
	ll om=m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		oa[i]=a[i];
	}
	sort(a, a+n);
	for (int i=0;i<n;i++){
		st[i]=a[i];
		if (i) st[i]+=st[i-1];
	}
	pair<ll, ll> v={0, 0};
	ll pc=0;
	ll mii=0;
	ll maa=A;
	while (mii<=maa){
		ll mid=(mii+maa)/2;
		if (test(mid)<=m){
			//cout<<pc<<" c "<<mid<<endl;
			v=max(v, {pc*cf+mid*cm, mid});
			mii=mid+1;
		}
		else{
			maa=mid-1;
		}
	}
	for (int i=n-1;i>=0;i--){
		m-=A-a[i];
		if (m<0) break;
		a[i]=A;
		pc++;
		ll mi=0;
		ll ma=A;
		while (mi<=ma){
			ll mid=(mi+ma)/2;
			if (test(mid)<=m){
				//cout<<pc<<" c "<<mid<<endl;
				v=max(v, {pc*cf+mid*cm, mid});
				mi=mid+1;
			}
			else{
				ma=mid-1;
			}
		}
	}
	cout<<v.F<<endl;
	vector<pair<ll, int> > lol;
	for (int i=0;i<n;i++){
		if (oa[i]<v.S){
			om-=v.S-oa[i];
			oa[i]=v.S;
		}
		lol.push_back({oa[i], i});
	}
	sort(lol.rbegin(), lol.rend());
	for (int i=0;i<n;i++){
		int t=lol[i].S;
		if (om-(A-oa[t])>=0){
			om-=(A-oa[t]);
			oa[t]=A;
		}
	}
	for (int i=0;i<n;i++){
		cout<<oa[i]<<" ";
	}
	cout<<endl;
}