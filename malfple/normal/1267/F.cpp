#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

const int N = 2e5;
vector<int> lst[N + 5];

int a = 0, b = 0;
int KA[N + 5], KB[N + 5];
int mark[N + 5];

priority_queue<int> atas, bawah, gabungan;

int main(){
	int n, m, ka, kb;
	cin>>n>>m>>ka>>kb;
	for(int i = 0;i < ka;i++) {
		cin>>KA[i];
		mark[KA[i]]++;
	}
	for(int i = 0;i < kb;i++) {
		cin>>KB[i];
		mark[KB[i]]++;
	}
	if(ka >= m || kb >= n) {
		cout<<"No"<<endl;
		return 0;
	}
	
	while(ka != m - 1) {
		KA[ka++] = 1;
		mark[1]++;
	}
	
	while(kb != n - 1) { 
		KB[kb++] = n + 1;
		mark[n + 1]++;
	}
	for(int i = 1;i <= n + m;i++) {
		if(mark[i] == 0) {
			if(i <= n) {
				atas.push(-i);
			}
			else bawah.push(-i);
			gabungan.push(-i);
		}
	}
	while(!gabungan.empty()) {
		int val = -gabungan.top();
		gabungan.pop();
		if(val <= n) {
			atas.pop();
			if(b != kb) {
				mark[KB[b]]--;
				lst[val].pb(KB[b]);
				lst[KB[b]].pb(val);
				if(mark[KB[b]] == 0) {
					gabungan.push(-KB[b]);
					bawah.push(-KB[b]);
				}
				b++;
			} else {
				int ct = -bawah.top();
				lst[val].pb(ct);
				lst[ct].pb(val);
			}
		}
		else {
			bawah.pop();
			if(a != ka) {
				mark[KA[a]]--;
				lst[val].pb(KA[a]);
				lst[KA[a]].pb(val);
				if(mark[KA[a]] == 0) {
					gabungan.push((-KA[a]));
					atas.push(-KA[a]);
				}
				a++;
			} else {
				if(atas.size() == 0) break;
				assert(0);
			}
		}
	}
	#define endl '\n'
	cout<<"Yes"<<endl;
	for(int i = 1;i <= n;i++) {
		for(auto x: lst[i]) cout<<i<<" "<<x<<endl;
	}
	return 0;
}