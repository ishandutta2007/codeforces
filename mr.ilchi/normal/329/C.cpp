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

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

bool mat[10][10],test[10][10];
bool mark[1<<20];
int n,e;
int f0[100],f1[100];
int path[1<<20];
set <pii> edge;

inline bool check(){
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) if (mat[i][j] && test[i][j])
			return false;
	for (int i=0; i<n; i++){
		int d = 0;
		for (int j=0; j<n; j++)
			d+= test[i][j];
		if (d > 2)
			return false;
	}
	return true;
}

int main(){
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		edge.insert(pii(e1,e2));
		edge.insert(pii(e2,e1));
		if (n<=6)
			mat[e1][e2] = mat[e2][e1] = true;
	}
	if (n<=6){
		int c = 0;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++){ 
				f0[c] = i, f1[c] = j;
				c++;
			}
		for (int mask = 0; mask < (1<<c); mask++) if (__builtin_popcount(mask) == e){
			memset(test,false,sizeof test);
			for (int j=0; j<c; j++) if (mask & (1<<j))
				test[f0[j]][f1[j]] = test[f1[j]][f0[j]] = true;
			if (check()){
				for (int i=0; i<n; i++)
					for (int j=i+1; j<n; j++) if (test[i][j])
						cout << i+1 << ' ' << j+1 << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}
	int head = n, tail = n + 1;
	path[head] = 0;
	set <int> SET;
	for (int i=1; i<n; i++)
		SET.insert(i);
	while (!SET.empty()){
		set <int> :: iterator it = SET.begin();
		bool f = false;
		while (it!=SET.end()){
			if (edge.find(pii(path[head],*it)) == edge.end()){
				path[--head] = *it;
				SET.erase(*it);
				f = true;
				break;
			}else if (edge.find(pii(path[tail-1],*it)) == edge.end()){
				path[tail++] = *it;
				SET.erase(*it);
				f = true;
				break;
			}
			it++;
		}
		if (f == false)
			break;
	}
	vector <int> Q;
	for (int i=head; i<tail; i++){
		Q.push_back(path[i]);
		mark[path[i]] = true;
	}
	for (int i=0; i<n; i++) if (!mark[i]){
		for (int j=1; j+1<(int)Q.size(); j++) if (edge.find(pii(Q[j], i)) == edge.end() && edge.find(pii(Q[j+1],i))==edge.end()){
			Q.insert(Q.begin() + j + 1, i);
			mark[i] = true;
			break;
		}
	}
	if (edge.find(pii(Q[0],Q.back())) != edge.end()){
		for (int i=1; i<(int)Q.size()-1; i++) if (edge.find(pii(Q[0],Q[i+1]))==edge.end() && edge.find(pii(Q.back(),Q[i]))==edge.end()){
			vector <int> temp;
			temp.push_back (Q[0]);
			for (int j=i+1; j<(int)Q.size(); j++)
				temp.push_back(Q[j]);
			for (int j=i; j>0; j--)
				temp.push_back(Q[j]);
			Q = temp;
			break;
		}
	}
	for (int i=0; i<e; i++)
		cout << Q[i]+1 << ' ' << Q[(i+1)%(int)Q.size()]+1 << endl;
	return 0;
}