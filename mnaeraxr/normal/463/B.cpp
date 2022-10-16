/*
	Author:	MarX
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define MAX 100000

int main()
{
	int n; cin >> n;
	long long ans = 0;
	long long prev = 0, cur, e = 0;

	for (int i = 0; i < n; ++i){
		cin >> cur;
		e += prev - cur;
		if (e < 0){ ans += -e;
		e = 0;}
		prev = cur;
	}
	cout << ans << endl;
}