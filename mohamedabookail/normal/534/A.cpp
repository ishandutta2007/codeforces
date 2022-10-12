/**
*    author:  Mohamed AboOkail
*    created: 18/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	deque < int > dq;
	int size = n;
	for (int i = 1; i <= size; i++) {
		if(i == size && i != 1) break;
		dq.push_back(i);
		if(size == n / 2 + 1) break;
		dq.push_back(size);
		size--;
	}
	if(n > 3) dq.push_front(n / 2 + 1);
	cout << dq.size() << "\n";
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << ' ';
	}
}