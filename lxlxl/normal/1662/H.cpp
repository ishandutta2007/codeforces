#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (;T--;){
		int w,l;
		cin >> w >> l;
		vector<int> ans;
		int g1=__gcd(w-2,l-0);
		int g2=__gcd(w-1,l-1);
		int g3=__gcd(w-0,l-2);
		for (int i=1;i*i<=g1;i++)
			if (g1%i==0) ans.push_back(i),ans.push_back(g1/i);
		for (int i=1;i*i<=g2;i++)
			if (g2%i==0) ans.push_back(i),ans.push_back(g2/i);
		for (int i=1;i*i<=g3;i++)
			if (g3%i==0) ans.push_back(i),ans.push_back(g3/i);
		ans.push_back(1);
		ans.push_back(2);
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end())-ans.begin());
		cout << (int)ans.size();
		for (auto e:ans) cout << " " << e;
		cout << "\n";
	}
	return 0;
}