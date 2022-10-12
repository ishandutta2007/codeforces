#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<set>
using namespace std;

const int Z = 32000;
bool f[Z];
int p[Z],lp;
map<long long int, int> pp;
void pre() {
	for (int i = 2; i < Z; i++) {
		if (!f[i]) p[lp++] = i;
		for (int j = 0; j < lp; j++) {
			int x = i * p[j];
			if (x >= Z)break;
			f[x] = true;
			if (i % p[j] == 0)break;
		}
	}
	for (int i = 0; i < lp; i++) {
		long long int cur = p[i];
		while (1) {
			pp[cur] = p[i];
			if (cur > 1e18 / p[i])break;
			cur *= p[i];
		}
	}
}
bool isprime(int x) {
	if (x < 2)return false;
	for (int i = 0; i < lp; i++) {
		if (p[i] * p[i] > x)return true;
		if (x % p[i] == 0)return false;
	}
	return true;
}

int N, K;
long long int a[1111];
vector<long long int> b[1111];
map<long long int,vector<int> > mp;

bool g[1111];
void init() {
	memset(g, 0, sizeof(g));

	set<long long int> lis;
	for (int i = 0; i < N; i++) {
		g[i] = false;
		if (pp.count(a[i])) {
			mp[pp[a[i]]].push_back(i);
			b[i].push_back(pp[a[i]]);
			lis.insert(pp[a[i]]);
			g[i] = true;
			continue;
		}

		int lo = 1, hi = 1000000;
		while (lo != hi) {
			int mi = (lo + hi) / 2;
			if ((long long int)mi * mi * mi < a[i])
				lo = mi + 1;
			else
				hi = mi;
		}
		if ((long long int)lo * lo * lo == a[i] && isprime(lo)) {
			mp[lo].push_back(i);
			b[i].push_back(lo);
			g[i] = true;
			lis.insert(lo);
			continue;
		}

		lo = 1, hi = 1000000000;
		while (lo != hi) {
			int mi = (lo + hi) / 2;
			if ((long long int)mi * mi < a[i])
				lo = mi + 1;
			else
				hi = mi;
		}
		if ((long long int)lo * lo == a[i] && isprime(lo)) {
			mp[lo].push_back(i);
			b[i].push_back(lo);
			g[i] = true;
			lis.insert(lo);
			continue;
		}
	}

	for (int i = 0; i < N; i++)if (!g[i]) {
		long long int cur = a[i];
		for (auto X : lis) {
			if (cur % X == 0) {
				while (cur % X == 0)cur /= X;
				b[i].push_back(X);
			}
			if (cur == 1)break;
		}
		if (cur > 1)b[i].push_back(cur);
		if (b[i].size() == 1)mp[b[i][0]].push_back(i);
	}
}

bool sol(){
	if(K == 1)return false;
	mp.clear();
	for (int i = 0; i < N; i++)b[i].clear();
	init();
	int tot = 0;
	set<long long int> good_base;
	bool f3 = false;
	for(auto P : mp){
		int sz = P.second.size();
		if(sz == 1)continue;
		if(sz >= 3)f3 = true;
		tot += sz;
		good_base.insert(P.first);
	}
	if(tot <= K){
		vector<long long int> res;
		for(int i=0; i<N; i++)if(b[i].size() == 1 && good_base.count(b[i][0]))
			res.push_back(i);
		for(int i=0; i<N; i++){
			if(res.size() == K)break;
			if(b[i].size() == 1)continue;
			bool good = true;
			for(auto X : b[i])if(!good_base.count(X)){
				good = false;
				break;
			}
			if(good)res.push_back(i);
		}
		if(res.size() < K)return false;
		for(int i=0; i<K; i++)
			cout << a[res[i]] << (i<K-1?' ':'\n');
		return true;
	}
	if(K % 2 == 0 || f3){
		vector<pair<int,vector<int> > > e;
		for(auto P : mp){
			int sz = P.second.size();
			if(sz == 1)continue;
			e.push_back(make_pair(-sz, P.second));
		}
		sort(e.begin(), e.end());
		vector<long long int> res;
		for(int i=0; i<e.size(); i++){
			if(res.size() + 2 <= K){
				res.push_back(e[i].second[0]);
				res.push_back(e[i].second[1]);
			}else
				break;
		}
		for(int i=0; i<e.size(); i++){
			if(res.size() == K)break;
			for(int j=2; j<e[i].second.size(); j++){
				if(res.size() == K)break;
				res.push_back(e[i].second[j]);
			}
		}
		for(int i=0; i<K; i++)
			cout << a[res[i]] << (i<K-1?' ':'\n');
		return true;
	}

	for(int i=0; i<N; i++){
		if(b[i].size() == 1)continue;
		bool good = true;
		for(auto X : b[i])if(!good_base.count(X)){
			good = false;
			break;
		}
		if(!good)continue;
		if((int)b[i].size() * 2 + 1 > K)continue;

		vector<long long int> res;
		res.push_back(i);
		for(auto X : b[i]){
			for(auto Y : mp[X])
				res.push_back(Y);
			mp.erase(X);
		}
		for(auto P : mp){
			if(res.size() == K)break;
			for(auto Y : P.second)
				res.push_back(Y);
		}
		for(int i=0; i<K; i++)
			cout << a[res[i]] << (i<K-1?' ':'\n');
		return true;
	}
	return false;
}

int main()
{
	pre();
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> a[i];
	
	if(!sol())cout << 0 << endl;

	return 0;
}