#include <iostream>
#include <stack>

using namespace std;

int n, k;
int p[200005];
bool used[200005];
stack<int> stk;

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < k; i++) cin >> p[i];
	
	stk.push(n+1);
	int need = 1;
	for(int i = 0; i < k; i++){
		stk.push(p[i]);
		while(stk.size() > 1 && stk.top() == need ){
			stk.pop();
			need++;
		}
		if(i < k-1 && p[i+1] > stk.top()) goto ng;
	}
	
	for(int i = 0; i < k; i++){
		if(i == 0) cout << p[i];
		else cout << " " << p[i];
		used[p[i]] = true;
	}
	
	while(stk.size() > 0){
		for(int i = stk.top()-1; i >= need; i--){
			cout << " " << i;
		}
		need = stk.top() + 1;
		stk.pop();
	}
	cout << endl;
	return 0;
	
	ng:;
	cout << -1 << endl;
	return 0;
}