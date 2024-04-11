#include <iostream>
#include <deque>

using namespace std;

int n, k;
deque<int> deq;

int main(void)
{
	cin >> n >> k;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		deq.push_back(a);
	}
	
	int ans = 0;
	while(deq.size() && deq.front() <= k) deq.pop_front(), ans++;
	while(deq.size() && deq.back() <= k) deq.pop_back(), ans++;
	cout << ans << endl;
	
	return 0;
}