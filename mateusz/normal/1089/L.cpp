#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
int id[N], n, k;
std::vector<int> war[N];
multiset<int> s;
long long wynik;
int main() {
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 0; i < n; i ++) {
		int a;
		cin>>a;
		id[i] = a;
	}
	for(int i = 0; i < n; i ++) {
		int a;
		cin>>a;
		war[id[i]].push_back(a);
	}
	int huj = 0;
	for(int i = 1 ; i<=k;i++) {
		if(war[i].size() == 0) huj++;
		sort(war[i].begin(), war[i].end());
		reverse(war[i].begin(), war[i].end());
		while(war[i].size()>1) {
			s.insert(war[i].back());
			war[i].pop_back();
		}
	}
	for(int i = 0; i<huj; i ++) {
		wynik+=(*s.begin());
		// cout<<(*s.begin())<<endl;
		s.erase(s.begin());
	}
	cout<<wynik<<endl;
}