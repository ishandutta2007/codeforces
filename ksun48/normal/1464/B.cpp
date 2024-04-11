#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	string s;
	cin >> s;
	ll x, y;
	cin >> x >> y;
	ll best = 1e18;
	for(int j = 0; j < 2; j++){
		ll cost = 0;
		string t = s;
		for(char& c : t) if(c == '?') c = '0';
		int n0 = 0;
		int n1 = 0;
		{
			for(char c : t){
				if(c == '0'){
					n0++; cost += y * n1;
				}
				if(c == '1'){
					n1++; cost += x * n0;
				}
			}
			best = min(best, cost);
		}
		int s0 = n0;
		int s1 = n1;
		int p0 = 0;
		int p1 = 0;
		for(char c : s){
			if(c == '0' || c == '?'){
				s0--;
			} else if(c == '1'){
				s1--;
			}
			if(c == '?'){
				cost -= y * p1;
				cost -= x * s1;
				cost += x * p0;
				cost += y * s0;
				best = min(best, cost);
			}
			if(c == '0'){
				p0++;
			} else if(c == '1' || c == '?'){
				p1++;
			}
		}
		swap(x, y);
		reverse(s.begin(), s.end());
	}
	cout << best << '\n';
}