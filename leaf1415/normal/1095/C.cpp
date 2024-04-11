#include <iostream>
#include <queue>

using namespace std;

int n, k;

int main(void)
{
	cin >> n >> k;
	if(n < k){
		cout << "NO" << endl;
		return 0;
	}
	
	priority_queue<int> Q;
	for(int i = 0; i <= 30; i++){
		if(n & (1<<i)) Q.push(1<<i);
	}
	
	if(Q.size() > k){
		cout << "NO" << endl;
		return 0;
	}
	while(Q.size() < k){
		Q.push(Q.top()/2);
		Q.push(Q.top()/2);
		Q.pop();
	}
	
	cout << "YES" << endl;
	while(Q.size()){
		cout << Q.top() << " ";
		Q.pop();
	}
	cout << endl;
	
	return 0;
}