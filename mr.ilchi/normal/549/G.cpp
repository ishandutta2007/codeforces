#include <bits/stdc++.h>
using namespace std;

int n;
int a[1<<20];

inline bool cmp (const int &i, const int &j){
	return i+a[i] < j+a[j];
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	vector<int> perm(n);
	for (int i=0; i<n; i++)
		perm[i] = i;
	sort(perm.begin(), perm.end(), cmp);
	for (int i=1; i<n; i++) if (a[perm[i-1]]+perm[i-1] == a[perm[i]]+perm[i]){
		cout << ":(" << endl;
		return 0;
	}
	for (int i=0; i<n; i++)
		cout << perm[i]+a[perm[i]]-i << ' ';
	cout << endl;
	return 0;
}