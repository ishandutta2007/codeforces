#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005], b[100005];
int omax, emax;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ocnt = 0, ecnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i]%2) ocnt++;
		else ecnt++;
	}
	if(ocnt && ecnt) sort(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

	return 0;
}