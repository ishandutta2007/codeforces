#include <iostream>

using namespace std;

int n;
int a[200005], b[200005];
int pos[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) pos[a[i]] = i;
	
	int end = 0;
	for(int i = 1; i <= n; i++){
		if(end >= pos[b[i]]) cout << 0 << " ";
		else{
			cout << pos[b[i]] - end << " ";
			end = pos[b[i]];
		}
	}
	cout << endl;
	return 0;
}