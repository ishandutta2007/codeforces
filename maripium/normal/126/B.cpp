#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int z[N];

void init(string s, int x, int *z){              //Z algorithm
	int n = s.size(), l, r; z[x] = 0;
	for(int i=x+1, l = 0, r = 0; i<n; ++i){
		z[i] = min(z[i - l], max(r - i + 1, 0));
		while(s[i + z[i]] == s[z[i]]) ++z[i], l = i, r = i + z[i] - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; 
	cin >> s;
	init(s, 0, z);
	int n = s.size(), ans = 0, mx = 0;
	for(int i=1; i<n; ++i){
		if(z[i] == n - i && mx >= n - i) ans = max(ans,n - i);       //z[i]==n-1,exist suffix at end,mx>=n-i exist suffix at th middle 
		mx = max(mx, z[i]);
	}
	if(ans == 0) cout << "Just a legend";
	for(int i=0; i<ans; ++i) cout << s[i];
	cout << endl;
	return 0;
}