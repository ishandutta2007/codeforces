#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

int main(){
	int n,tmp,tmp2;
	cin>>n;
	set<int> used;
	set<int> tot[n*(n-1)/2];
	
	for (int i=0;i<n*(n-1)/2;i++) {
		cin>>tmp;
		for (int j=0;j<tmp;j++) {
			cin>>tmp2;
			tot[i].insert(tmp2);
		}
	}
	
	if (n==2) {
		cout<<"1 "<<*tot[0].begin()<<endl;
		bool first=true;
		FOR(it,tot[0]) {
			if (first) {
				first = false;
				cout<<(int)tot[0].size()-1;
			}else cout<<" "<<*it;
		}
		cout<<endl;
	} else {
		for (int i=0;i<n*(n-1)/2;i++) {
			FOR(it, tot[i]) {
				if (used.count(*it)==0) {
					for (int j=i+1;j<n*(n-1)/2;j++) if (tot[j].count(*it)) {
						set<int> C;
						set_intersection(all(tot[i]), all(tot[j]), inserter(C, C.begin()));
						cout<<C.size();
						FOR(it2,C) {
							used.insert(*it2);
							cout<<" "<<*it2;
						}
						cout<<endl;
						break;
					}
				}
			}
		}
	}
	
	return 0;
}