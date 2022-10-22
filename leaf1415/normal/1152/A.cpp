#include <iostream>

using namespace std;

int n, m;
int a[100005], b[100005];
int odda, oddb, evena, evenb;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i]%2) odda++; else evena++;
	}
	for(int i = 1; i <= m; i++){
		if(b[i]%2) oddb++; else evenb++;
	}
	
	int ans = min(odda, evenb) + min(oddb, evena);
	cout << ans << endl;
	
	return 0;
}