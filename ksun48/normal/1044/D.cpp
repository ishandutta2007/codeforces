#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<int,int> uf;
map<int,vector<int> > contents;
map<int,int> val;
void make(int a){
	if(uf.find(a) == uf.end()){
		uf[a] = a;
		contents[a].push_back(a);
		val[a] = 0;
	}
}


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	int last = 0;
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if(l > r) swap(l,r);
			r++;
			make(l); make(r);
			if(uf[l] == uf[r]) continue;
			int v = val[l] ^ val[r] ^ x;
			l = uf[l];
			r = uf[r];
			if(contents[l].size() > contents[r].size()){
				swap(l, r);
			}
			//cout << "set " << l << " " << r << " " << x << endl;
			for(int a : contents[l]){
				uf[a] = r;
				val[a] ^= v;
				contents[r].push_back(a);
			}
			contents.erase(l);
		} else {
			int l, r;
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if(l > r) swap(l,r);
			r++;
			make(l); make(r);
			//cout << "get " << l << " " << r << " " << (val[l] ^ val[r]) << endl;
			if(uf[l] != uf[r]){
				cout << -1 << '\n';
				last = 1;
			} else {
				cout << (val[l] ^ val[r]) << '\n';
				last = val[l] ^ val[r];
			}
		}
	}
}