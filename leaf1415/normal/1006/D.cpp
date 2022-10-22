#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
string a, b;

int cnt[50005][26];

int main(void)
{
	cin >> n;
	cin >> a >> b;
	
	llint N = n/2;
	llint ans = 0;
	for(int i = 0; i < N; i++){
		char a1 = a[i], a2 = a[n-i-1];
		char b1 = b[i], b2 = b[n-i-1];
		if(b1 == b2){
			if(a1 == a2) continue;
			ans++;
		}
		else{
			if(a1 == b1){
				if(a2 == b2) continue;
				ans++;
			}
			else if(a1 == b2){
				if(a2 == b1) continue;
				ans++;
			}
			else{
				if(a2 == b1 || a2 == b2) ans++;
				else ans += 2;
			}
		}
	}
	
	if(n%2 && a[n/2] != b[n/2]) ans++;
	cout << ans << endl;
	return 0;
}