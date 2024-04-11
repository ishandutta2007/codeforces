#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, k;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> s;
	
	string t = s;
	for(int i = k; i < n; i++) t[i] = t[i-k];
	
	if(t >= s){
		cout << n << endl;
		cout << t << endl;
		return 0;
	}
	
	s[k-1]++;
	for(int i = k-1; i >= 0; i--){
		if(s[i] > '9') s[i] = '0', s[i-1]++;
	}
	t = s;
	for(int i = k; i < n; i++) t[i] = t[i-k];
	
	cout << n << endl;
	cout << t << endl;
	
	return 0;
}