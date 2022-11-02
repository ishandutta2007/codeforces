#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> dvs[202020];

int a[202020];
ll mi[202020];
ll ma[202020];

vector<pair<ll, ll> > iv[202020];
vector<ll> pos[202020];

set<pair<ll, ll> > vv;
ll x=-1;
ll s=0;
ll n;

void adv(){
	x++;
	if ((int)vv.size()>0){
		auto it=vv.begin();
		s-=(*it).S;
		if ((*it).F==x){
			vv.erase(it);
		}
	}
}

void add(pair<ll, ll> t){
	if (t.F<=x) return;
	auto it=vv.lower_bound({t.F, 0});
	if (it!=vv.end()&&((*it).S>=t.S)) return;
	vector<pair<ll, ll> > er;
	if (it==vv.end()&&(int)vv.size()>0) it--;
	while (1){
		if ((int)vv.size()==0) break;
		if ((*it).F<=t.F&&(*it).S<=t.S){
			er.push_back(*it);
		}
		else if((*it).F<=t.F){
			break;
		}
		if (it==vv.begin()) break;
		it--;
	}
	auto itt=vv.lower_bound({t.F, 999999});
	if (itt!=vv.end()){
		ll ek=x;
		if (itt!=vv.begin()){
			itt--;
			ek=(*itt).F;
			itt++;
		}
		s-=(t.F-ek)*(*itt).S;
		//cout<<"ek "<<ek<<" "<<(ek-t.F)*(*itt).S<<endl;
	}
	
	for (auto e:er){
		auto asd=vv.lower_bound(e);
		//cout<<"er "<<e.F<<" "<<e.S<<endl;
		if (asd==vv.begin()){
			//cout<<((*asd).F-x)*e.S<<endl;
			s-=((*asd).F-x)*e.S;
		}
		else{
			asd--;
			//cout<<(e.F-(*asd).F)*e.S<<endl;
			s-=(e.F-(*asd).F)*e.S;
		}
	}
	for (auto e:er){
		vv.erase(e);
	}
	//cout<<"s "<<s<<endl;
	vv.insert(t);
	auto asd=vv.lower_bound(t);
	if (asd==vv.begin()){
		s+=((*asd).F-x)*(*asd).S;
	}
	else{
		asd--;
		s+=(t.F-(*asd).F)*t.S;
	}
}

const int C=200000;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=C;i++){
		for (int j=i;j<=C;j+=i){
			dvs[j].push_back(i);
		}
		mi[i]=n+1;
		ma[i]=-1;
	}
	for (int i=0;i<n;i++){
		cin>>a[i];
		for (int d:dvs[a[i]]){
			pos[d].push_back(i);
		}
	}
	for (ll i=C;i>=1;i--){
		sort(pos[i].begin(), pos[i].end());
		if ((int)pos[i].size()>1){
			int sz=pos[i].size();
			iv[pos[i][0]+1].push_back({pos[i][sz-1], i});
			iv[0].push_back({pos[i][sz-2], i});
			iv[pos[i][1]+1].push_back({n, i});
		}
	}
	ll v=0;
	for (int i=0;i<n;i++){
		adv();
		//cout<<s<<endl;
		//cout<<"i "<<i<<endl;
		for (auto t:iv[i]){
			/*
			cout<<s<<endl;
			for (auto tt:vv){
				cout<<tt.F<<" "<<tt.S<<endl;
			}
			cout<<endl;
			*/
			add(t);
			/*
			cout<<"added "<<t.F<<" "<<t.S<<endl;
			cout<<s<<endl;
			for (auto tt:vv){
				cout<<tt.F<<" "<<tt.S<<endl;
			}
			cout<<endl;
			*/
		}
		v+=s;
		//cout<<"v "<<v<<endl;
	}
	cout<<v<<endl;
}