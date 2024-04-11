# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

void rd(int &x) { scanf("%d", &x); }

char s[5002];
int main() {
	scanf("%s", s);
	int i = 0;
	while(s[i] == 'a') ++i;
	int j = i;
	while(s[j] == 'b') ++j;
	int k = j;
	while(s[k] == 'c') ++k;
	if(i > 0 && j > i && k > j && k == strlen(s) && (k - j == j - i || k - j == i)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}