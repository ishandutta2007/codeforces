#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#define llint long long
#define inf 100000000000000000

using namespace std;

llint n, k;
string s;
bool stable[200005];
llint leftW[400005], leftB[400005];
llint rightW[400005], rightB[400005];

char get(char c, llint x)
{
	if(x % 2 == 0) return c;
	if(c == 'B') return 'W';
	if(c == 'W') return 'B';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	
	for(int i = 0; i < n; i++){
		if(s[i] == s[(i+1)%n] || s[i] == s[(i-1+n)%n]) stable[i] = true;
	}
	
	llint d = inf;
	for(int i = 0; i < 2*n; i++){
		if(stable[i%n] && s[i%n] == 'W') d = 0;
		else d++;
		leftW[i] = d;
	}
	d = inf;
	for(int i = 0; i < 2*n; i++){
		if(stable[i%n] && s[i%n] == 'B') d = 0;
		else d++;
		leftB[i] = d;
	}
	
	d = inf;
	for(int i = 2*n-1; i >= 0; i--){
		if(stable[i%n] && s[i%n] == 'W') d = 0;
		else d++;
		rightW[i] = d;
	}
	d = inf;
	for(int i = 2*n-1; i >= 0; i--){
		if(stable[i%n] && s[i%n] == 'B') d = 0;
		else d++;
		rightB[i] = d;
	}
	
	string ans;
	for(int i = 0; i < n; i++){
		llint w = inf, b = inf;
		w = min(min(leftW[i], rightW[i]), min(leftW[n+i], rightW[n+i]));
		b = min(min(leftB[i], rightB[i]), min(leftB[n+i], rightB[n+i]));
		char c;
		if(w > k && b > k) c = get(s[i], k);
		else{
			if(w > b) c = 'B';
			else if(w < b) c = 'W';
			else c = get(s[i], w-1);
		}
		ans += c;
	}
	cout << ans << endl;
	
	return 0;
}