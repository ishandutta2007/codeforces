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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const int maxN = 1000 * 100 + 10;

bool mark[maxN];
int n,q;
set <int> sit[maxN];
vector <int> prime[maxN];

void go (vector <int> &Q, int n){
	
	for (int i=2; i*i<=n; i++){
		int c=0;	
		while (n%i==0) { n/=i; c++; }
		if (c>0){
			Q.push_back(i);
		}
	}
	if (n>1)
		Q.push_back(n);
}

int check (int x){

	if (x==1)
		return -1;

	for (int i=0; i<prime[x].size(); i++) if (!sit[prime[x][i]].empty())
		return *sit[prime[x][i]].begin();

	for (int i=0; i<prime[x].size(); i++)
		sit[prime[x][i]].insert(x);

	return -1;
}

int main(){
	
	cin >> n >> q;

	for (int i=1; i<=n; i++)
		go(prime[i],i);

	for (int o=1; o<=q; o++){
		char ord; cin >> ord;
		int x; cin >> x;
		if (ord == '-'){
			if (mark[x]){
				mark[x] = false;
				for (int i=0; i<prime[x].size(); i++) 
					sit[prime[x][i]].erase(x);
				cout << "Success" << endl;
			}
			else
				cout << "Already off" << endl;
		}
		else{
			if (mark[x])
				cout << "Already on" << endl;
			else{
				int p = check(x);
				if (p==-1){	
					mark[x] = true;
					cout << "Success" << endl;
				}
				else
					cout << "Conflict with " << p << endl;
			}
		}
	}

	return 0;
}