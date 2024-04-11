#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s, t;
int a[200005], b[200005], c[200005], d[200005];

int main(void)
{
	cin >> n;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	
	for(int i = 0; i < n; i++) a[i] = s[i] - 'a';
	for(int i = 0; i < n; i++) b[i] = t[i] - 'a';
	
	for(int i = 0; i <= n; i++){
		c[i] += a[i]+b[i];
		c[i+1] += c[i]/26, c[i] %= 26;
	}
	for(int i = n; i >= 0; i--){
		d[i] = c[i]/2;
		if(i > 0) c[i-1] += c[i]%2*26;
	}
	
	/*for(int i = n; i >= 0; i--) cout << a[i] << " "; cout << endl;
	for(int i = n; i >= 0; i--) cout << b[i] << " "; cout << endl;
	for(int i = n; i >= 0; i--) cout << c[i] << " "; cout << endl;
	for(int i = n; i >= 0; i--) cout << d[i] << " "; cout << endl;*/
	
	string ans;
	for(int i = 0; i < n; i++) ans += (char)(d[i] + 'a');
	reverse(ans.begin(), ans.end());

	cout << ans << endl;
	return 0;
}