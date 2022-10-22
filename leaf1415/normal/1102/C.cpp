#include <iostream>

using namespace std;

int n, x, y;
int a[105];

int main(void)
{
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	if(x > y){
		cout << n << endl;
		return 0;
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) if(a[i] <= x) cnt++;
	cout << (cnt+1)/2 << endl;
	
	return 0;
}