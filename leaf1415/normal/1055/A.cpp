#include <iostream>

using namespace std;

int n, s;
int a[1005], b[1005];

int main(void)
{
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	if(!a[1]) goto no;
	if(a[s]) goto yes;
	if(!b[s]) goto no;
	for(int i = s+1; i <= n; i++){
		if(a[i] && b[i]) goto yes;
	}
	goto no;
	
	yes: cout << "YES" << endl;
	return 0;
	
	no: cout << "NO" << endl;
	return 0;
}