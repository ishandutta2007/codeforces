#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, k;
	cin >> n >> a >> b >> k;

	string s; cin >> s;

	int total = 0;

	vector<int> answer;
	priority_queue<pair<int,int>> pq;

	int pos = -1;

	for (int i = 0; i < n; ++i){
		if (s[i] == '0'){
			if (pos == -1)
				pos = i;
		}
		else{
			if (pos != -1){
				pq.push(make_pair(i - pos, pos));
				total += (i - pos) / b;
				pos = -1;
			}
		}
	}

	if (pos != -1){
		pq.push(make_pair(n - pos, pos));
		total += (n - pos) / b;
	}

	while (total >= a){
		auto c = pq.top(); pq.pop();
		total--;
		
		answer.push_back(c.second + b - 1);
		pq.push(make_pair(c.first - b, c.second + b));
	}

	cout << answer.size() << endl;
	for (auto a : answer)
		cout << a + 1 << " ";
	cout << endl;

	return 0;
}