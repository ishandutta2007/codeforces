//be naame khodaa
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = -1;

int main(){
	string a, b;
	cin >> a >> b; 
	int diff = 0;
	for(int i = 0; i < sz(b); i++) 
		diff += (a[i] != b[i]); 
	diff %= 2;
	int ans = !diff;

	int ch = 0; 
	for(int i = 0; i+1 < sz(b); i++)
		ch += (b[i] != b[i+1]);

	for(int i = 1; i <= sz(a) - sz(b); i++) { 
		diff += ch;
		diff += (a[i-1] != b[0]);
		diff += (a[i+sz(b)-1] != b[sz(b)-1]);
	//	cout << diff << endl;
		diff %= 2;
		ans += !diff;
	}
	cout << ans << endl;

    return 0;
}