#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[101010];

int isp2(ll x){
	if (x<=2) return 1;
	if (x%2==1) return 0;
	return isp2(x/2);
}

int ct[111];

vector<ll> fr;

int can(int x){
	int u=x;
	multiset<ll> tt;
	vector<ll> ff=fr;
	for (int i=0;i<100;i++){
		int tu=min(u, ct[i]);
		if (tu<u){
			if (i==0) return 0;
			for (int ii=0;ii<u-tu;ii++){
				tt.insert((1ll<<(ll)(i-1)));
			}
		}
		u=tu;
		int nu=ct[i]-u;
		for (int ii=0;ii<nu;ii++){
			ff.push_back((1ll<<(ll)i));
		}
	}
	sort(ff.rbegin(), ff.rend());
	for (ll t:ff){
		auto it=tt.upper_bound(t/2);
		if (it==tt.end()) return 0;
		tt.erase(it);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	map<ll, int> cnt;
	for (int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i=n-1;i>=0;i--){
		if (!isp2(a[i])){
			/*
			assert(cnt[a[i]]>0);
			cnt[a[i]]--;
			ll t=1;
			while (t<a[i]){
				if (cnt[t]<=0){
					cout<<-1<<endl;
					return 0;
				}
				cnt[t]--;
				t*=2;
			}
			*/
			cnt[a[i]]=0;
			fr.push_back(a[i]);
		}
	}
	for (int i=0;i<n;i++){
		if (!isp2(a[i])){
			assert(cnt[a[i]]==0);
		}
		else{
			if (cnt[a[i]]>0){
				int l2=0;
				ll t=1;
				while (t<a[i]){
					l2++;
					t*=2;
				}
				ct[l2]=cnt[a[i]];
				cnt[a[i]]=0;
			}
		}
	}
	if (!can(ct[0])){
		cout<<-1<<endl;
	}
	else{
		int mi=0;
		int ma=ct[0];
		int v=ct[0];
		while (mi<=ma){
			int mid=(mi+ma)/2;
			if (can(mid)){
				v=mid;
				ma=mid-1;
			}
			else{
				mi=mid+1;
			}
		}
		for (int i=v;i<=ct[0];i++){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}