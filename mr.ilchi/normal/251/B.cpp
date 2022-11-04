/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define ff first
#define ss second

using namespace std;

typedef long long LL;
typedef long long ll;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,int> pie;

const int MAXN = 100+10;

int n,k;
int t[MAXN],p[MAXN],a[MAXN],b[MAXN];

int func1(){
	for (int i=0; i<n; i++)
		p[i] = i;
	for (int move=0; move<=k; move++){
		bool bad = false;
		for (int i=0; i<n; i++) if (p[i]!=b[i])
			bad = true;
		if (!bad)
			return move;
		for (int i=0; i<n; i++)
			t[i] = p[a[i]];
		for (int i=0; i<n; i++)
			p[i] = t[i];
	}
	return k+1;
}

int func2(){
	for (int i=0; i<n; i++)
		p[i] = i;
	for (int move=0; move<=k; move++){
		bool bad = false;
		for (int i=0; i<n; i++) if (p[i]!=b[i])
			bad = true;
		if (!bad)
			return move;
		for (int i=0; i<n; i++)
			t[a[i]] = p[i];
		for (int i=0; i<n; i++)
			p[i] = t[i];
	}
	return k+1;
}

int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> a[i]; a[i]--;
	}
	for (int i=0; i<n; i++){
		cin >> b[i]; b[i]--;
	}
	int f1 = func1();
	int f2 = func2();
	if (k==1){
		if (min(f1,f2)==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if (min(f1,f2)>k || max(f1,f2)<=1){
		cout << "NO" << endl;
		return 0;
	}
	if ((f1<=k && k%2==f1%2) || (f2<=k && k%2==f2%2)){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}