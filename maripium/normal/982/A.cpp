#include <bits/stdc++.h>
using namespace std;

void NO() {
	cout << "No\n";
	exit(0);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;string s; 
	cin >> n >> s;
	vector<int> pos;
	for (int i = 0;i < n;++i) if (s[i] == '1') pos.push_back(i);
	if (pos.size() == 0) NO();
	if (pos[0] > 1 || pos.back() < n - 2) NO();
	for (int i = 1;i < pos.size();++i) if (pos[i] == pos[i - 1] + 1) NO(); 
	for (int i = 1;i < pos.size();++i) {
		if (pos[i] - pos[i - 1] > 3) NO();
	}  
	cout << "Yes\n";
}