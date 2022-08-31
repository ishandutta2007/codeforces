#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    int n, m, p;
    cin >> n >> m >> p;

    int thresh = (n+1) / 2;

    vector<ll> a(n, 0);
    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		if(s[j] == '1') a[i] ^= (1ll << j);
    	}
    }
    shuffle(a.begin(), a.end(), mt);
    ll best = 0;
    for(int z = 0; z < n && z < 50; z++){
    	map<ll, int> freq;
    	for(ll x : a){
    		freq[x & a[z]]++;
    	}
    	map<ll, int> sfreq;
    	for(auto [r, f] : freq){
    		ll b = r;
    		while(true){
    			sfreq[b] += f;
    			if(b == 0) break;
    			b = (b-1) & r;
    		}
    	}
    	for(auto [r, f] : sfreq){
    		if(f >= thresh){
    			if(__builtin_popcountll(r) > __builtin_popcountll(best)){
    				best = r;
    			}
    		}
    	}
    }
    for(int j = 0; j < m; j++){
    	cout << (1 & (best >> j));
    }
    cout << '\n';
}