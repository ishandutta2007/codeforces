#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int cnum;
int n;
int l[1005], r[1005];
vector<pair<int, int> > que;
int ans[1005];

int main(void)
{
	cin >> cnum;
	for(int c = 0; c < cnum; c++){
		cin >> n;
		que.clear();
		for(int i = 0; i < n; i++){
			cin >> l[i] >> r[i];
			que.push_back( make_pair(l[i], i) );
		}
		sort(que.begin(), que.end());
		
		for(int i = 0; i < n; i++) ans[i] = 0;
		
		
		int t = 1;
		for(int i = 0; i < que.size(); i++){
			if(r[que[i].second] < t) continue;
			if(l[que[i].second] > t) t = l[que[i].second];
			ans[que[i].second] = t;
			t++;
		}
		
		for(int i = 0; i < n; i++){
			cout << ans[i];
			if(i != n-1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}