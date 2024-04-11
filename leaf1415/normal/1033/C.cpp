#include <iostream>

using namespace std;

int n;
int a[100005];
int memo[100005];

bool calc(int s)
{
	if(memo[s]) return memo[s] > 0;
	
	bool ret = false;
	for(int i = s%a[s]; i <= n; i+=a[s]){
		if(a[s] < a[i]) ret |= !calc(i);
	}
	return memo[s] = ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if(calc(i)) cout << "A";
		else cout << "B";
	}
	cout << endl;
	return 0;
}