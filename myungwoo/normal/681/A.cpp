#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int N;

int main()
{
	cin >> N;
	bool ans = 0;
	for (int i=1;i<=N;i++){
		string s; int a , b;
		cin >> s >> a >> b;
		if (a >= 2400 && b > a) ans = 1;
	}
	puts(ans ? "YES" : "NO");
}