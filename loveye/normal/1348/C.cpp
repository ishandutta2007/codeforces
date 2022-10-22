#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,k;
char s[N];
typedef pair<char,int> mt;
#define fi first
#define se second
vector<mt> v;
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		cin >> n >> k >> s+1;
		sort(s+1,s+n+1);
		if(k == 1) {
			cout << s+1 <<endl;
			continue;
		}
		int last = 0;v.clear();
		for(int i = 2;i <= n;++i)
			if(s[i] != s[i-1]) v.push_back(make_pair(s[i-1],i-1-last)),last = i-1;
		v.push_back(make_pair(s[n],n-last));
		if(v[0].se < k) {
			cout << s[k] << endl;
			continue;
		}
		else {
			v[0].se -= k;cout << v[0].fi;
			if(!v[0].se) v.erase(v.begin());
			if(v.empty() || v.size() > 1) {
				for(int i = 0;i < v.size();++i)
					for(int j = 1;j <= v[i].se;++j)
						cout << v[i].fi;
				cout << endl;
			}
			else {
				int sx = ceil((double)(v[0].se) / k);
				for(int i = 1;i <= sx;++i)
					cout << v[0].fi;
				cout << endl;
			}
		}
	}
	return 0;
}