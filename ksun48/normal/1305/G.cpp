#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int K = 18;
const int N = 1 << K;

bool has[N];
bool seen[N];
int freq[N];

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
    	a = find(a);
    	b = find(b);
    	if(a == b) return false;
    	par[a] = b;
    	return true;
    }
};
UF uf(N);

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 0; i < n; i++) cin >> a[i];
	a[n] = 0;
	ll ans = 0;
	for(int x : a) ans -= x;
	for(int x : a){
		has[x] = true;
		freq[x]++;
	}
	for(int j = N - 1; j >= 0; j--){
		int c = j;
		int cnt = 0;
		while(true){
			int b = j ^ c;
			if(has[b] && has[c] && uf.join(b, c)){
				cnt += 1;
				if(!seen[b]){
					cnt += freq[b] - 1;
					seen[b] = true;
				}
				if(!seen[c]){
					cnt += freq[c] - 1;
					seen[c] = true;
				}
			}
			if(!c) break;
			c = (c-1) & j;
		}
		ans += 1ll * cnt * j;
	}
	cout << ans << '\n';
}