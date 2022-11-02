#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll v[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> ips;
	vector<pair<int, int> > ps;
	for (int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		ps.push_back({x, y});
		ips.push_back(x-k+1);
		ips.push_back(x+1);
	}
	sort(ips.begin(), ips.end());
	ips.erase(unique(ips.begin(), ips.end()), ips.end());
	sort(ps.begin(), ps.end());
	int i1=0;
	int i2=0;
	map<int, int> ct;
	set<int> yips;
	multiset<int> yp;
	for (int i=0;i<(int)ips.size();i++){
		int tx=ips[i];
		while (i2<(int)ps.size()&&ps[i2].F<tx+k){
			ct[ps[i2].S-k+1]++;
			if (ct[ps[i2].S-k+1]==1){
				yips.insert(ps[i2].S-k+1);
			}
			ct[ps[i2].S+1]++;
			if (ct[ps[i2].S+1]==1){
				yips.insert(ps[i2].S+1);
			}
			yp.insert(ps[i2].S);
			i2++;
		}
		while (i1<i2&&ps[i1].F<tx){
			ct[ps[i1].S-k+1]--;
			if (ct[ps[i1].S-k+1]==0){
				yips.erase(ps[i1].S-k+1);
			}
			ct[ps[i1].S+1]--;
			if (ct[ps[i1].S+1]==0){
				yips.erase(ps[i1].S+1);
			}
			yp.erase(yp.find(ps[i1].S));
			i1++;
		}
		if ((int)yp.size()>0){
			ll ke=ips[i+1]-ips[i];
			auto ii1=yp.begin();
			auto ii2=yp.begin();
			int cc=0;
			for (auto it=yips.begin();it!=yips.end();it++){
				int ty=(*it);
				while(ii2!=yp.end()&&(*ii2)<ty+k){
					cc++;
					ii2++;
				}
				while (ii1!=ii2&&(*ii1)<ty){
					cc--;
					ii1++;
				}
				if (cc>0){
					auto oit=it;
					oit++;
					v[cc]+=ke*(ll)((*oit)-(*it));
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}