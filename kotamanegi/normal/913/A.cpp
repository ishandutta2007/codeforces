#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<map>

using namespace std;
#define REP(i,m,n) for(int i=m;i<n;++i)
#define INF 10000000000000000
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define all(v) v.begin(),v.end()
int main() {
	long long n, m;
	cin >> n >> m;
	long long now = 1;
	for (int i = 0;i < n;++i) {
		now *= 2;
		if (now > m) {
			cout << m << endl;
			return 0;
		}
	}
	cout << m%now << endl;
	return 0;
}