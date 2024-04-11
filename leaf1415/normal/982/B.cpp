#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int n;
P w[200005];
priority_queue<P> Q;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i].first;
		w[i].second = i;
	}
	sort(w+1, w+n+1);
		
	int next = 1; char t;
	for(int i = 0; i < 2*n; i++){
		cin >> t;
		if(t == '0'){
			cout << w[next].second << " ";
			Q.push(w[next]);
			next++;
		}
		else{
			cout << Q.top().second << " ";
			Q.pop();
		}
	}
	cout << endl;
	
	return 0;
}