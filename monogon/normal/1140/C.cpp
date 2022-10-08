
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

unsigned int n, k;
int t, b;
vector<pair<int, int> > v;
long long S[300000];

int main() {
	cin >> n >> k;
	for(unsigned int i = 0; i < n; i++) {
		cin >> t >> b;
		v.push_back(make_pair(b, t));
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i = n - 1; i >= 0; i--) {
		S[i] = sum;
		if(Q.size() + 1 < k) {
			Q.push(v[i].second);
			sum += v[i].second;
		}else if(!Q.empty() && Q.top() < v[i].second) {
			sum += v[i].second - Q.top();
			Q.pop();
			Q.push(v[i].second);
		}
	}
	long long M = 0;
	for(unsigned int i = 0; i < n; i++) {
		long long x = (S[i] + v[i].second) * v[i].first;
		if(x > M) {
			M = x;
		}
	}
	cout << M << endl;
}