#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int a,b; cin>>a>>b;
		if(a > b) {
			cout<<"NO\n";
			continue;
		}
		vector<int> z,w;
		int pointer = 0;
		while(pointer < 35) {
			if(a&1) z.push_back(pointer);
			if(b&1) w.push_back(pointer);
			a = a>>1; b = b>>1;
			pointer++;
		}
		if(w.size() > z.size()) {
			cout<<"NO\n";
		}
		else {
			bool pass = true;
			for(int i=0;i<w.size();i++) {
				if(z[i] > w[i])
					pass = false;
			}
			if(pass)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}