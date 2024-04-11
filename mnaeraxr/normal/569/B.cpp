#include <iostream>

using namespace std;

const int maxn = 100100;

int v[maxn];
bool seen[maxn];
bool mk[maxn];

int main()
{
	int n; cin >> n;

	for (int i = 1; i <= n; ++i){
		cin >> v[i];
		seen[ v[i] ] = true;
	}

	int pos = 1;
	while (pos <= n && seen[pos]) ++pos;

	for (int i = 1; i <= n; ++i){
		if (v[i] <= n && !mk[v[i]]){
			cout << v[i] << " \n"[i == n];
			mk[v[i]] = true;
		}
		else{
			cout << pos++ << " \n"[i == n];
			while (pos <= n && seen[pos]) ++pos;
		}
	}
}