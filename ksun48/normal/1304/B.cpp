#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	map<string, int> freq;
	string a;
	string b;
	for(int i = 0; i < n; i++){
		string q;
		cin >> q;
		string rq = q;
		reverse(rq.begin(), rq.end());
		if(freq[rq] >= 1){
			freq[rq]--;
			a += rq;
			b += rq;
		} else {
			freq[q]++;
		}
	}
	for(auto r : freq){
		string q = r.first;
		string rq = q;
		reverse(rq.begin(), rq.end());
		if(r.second >= 1 && q == rq){
			a += q;
			break;
		}
	}
	reverse(b.begin(), b.end());
	a += b;
	cout << a.size() << '\n';
	cout << a << '\n';
}