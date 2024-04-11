#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

map<int, vector<pair<int, int> > > qs[303030];
ll v[303030];
ll w[303030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>w[i];
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--;
		qs[b][a%b].push_back({a, i});
	}
	for (int i=1;i<=n;i++){
		for (auto&r:qs[i]){
			sort(r.S.begin(), r.S.end());
			int i2=r.S.size()-1;
			int t=r.F;
			while (t+i<n) t+=i;
			ll s=0;
			for (;t>=0;t-=i){
				s+=w[t];
				while (i2>=0&&r.S[i2].F==t){
					v[r.S[i2].S]=s;
					i2--;
				}
			}
		}
	}
	for (int i=0;i<q;i++){
		cout<<v[i]<<'\n';
	}
}