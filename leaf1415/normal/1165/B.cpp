#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int a[200005];
priority_queue<int, vector<int>, greater<int> > Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i =1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) Q.push(a[i]);
	
	for(int i = 1; ; i++){
		while(1){
			if(Q.size() == 0){
				cout << i-1 << endl;
				return 0;
			}
			if(Q.top() >= i){
				Q.pop();
				break;
			}
			Q.pop();
		}
	}
	
	return 0;
}