#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	vector<int> letter('Z' - 'A' + 1, 0);
	int n;
	long long k;
	char c;
	cin >> n >> k;
	while(n--){
		cin >> c;
		letter[c-'A']++;
	}

	priority_queue<int> pq (letter.begin(), letter.end());

	long long sum = 0;
	long long card = 0;

	while( card < k ){
		long long max = pq.top();
		if ( card + max <= k ){
			sum += max*max;
			card += max;
			pq.pop();
		}else{
			sum += (k - card) * (k - card);
			card = k;
		}
	}

	cout << sum;

	return 0;
}