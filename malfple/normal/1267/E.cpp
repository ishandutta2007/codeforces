#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

const int N = 1005;

int arr[N + 5][N + 5];

vector<int> res;
priority_queue<pair<int,int> > pq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) cin>>arr[i][j];
		res.pb(i);
	}
	for(int i = 1;i < n;i++) {
		while(!pq.empty()) pq.pop();
		int total = 0;
		for(int j = 1;j <= m;j++) {
			total += arr[j][i] - arr[j][n];
			pq.push({arr[j][n] - arr[j][i], j});
		}
		vector<int> tmp;
		while(total < 0) {
			int ct = -pq.top().F;
			int id = pq.top().S;
			pq.pop();
			total -= ct;
			tmp.pb(id);
		}
		if(res.size() > tmp.size()) res = tmp;
	}
	cout<<res.size()<<endl;
	for(auto x: res) cout<<x<<" ";
	cout<<endl;
	return 0;
}