#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
int a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int id = 1;
	for(int i = 2; i <= n; i++){
		if(a[i]) continue;
		for(int j = i; j <= n; j+=i) a[j] = id;
		id++;
	}
	for(int i = 2; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	return 0;
}