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
	int n,m;
	cin>>n>>m;
	int tmp;
	vector<pair<int, int> > sorted;
	
	for (int i=0;i<m;i++) {
		cin>>tmp;
		sorted.push_back(make_pair(tmp,i));
	}
	
	sort(all(sorted));
	reverse(all(sorted));
	
	vector<pair<int,int> > use;
	int need=n;
	for (int i=0;i<m;i++) {
		int have = min(n/2,sorted[i].first);
		have = min(have,need);
		need-=have;
		use.push_back(make_pair(have,sorted[i].second));
	}
	if (need > 0) {
		cout<<"-1"<<endl;
	} else {
		int ans[n];
		memset(ans,-1,sizeof(ans));
		
		if (n%2==1) {
			int pos=0;
			for (int i=0;i<use.size();i++) {
				for (int j=0;j<use[i].first;j++) {
					ans[pos]=use[i].second;
					pos=(pos+2)%n;
				}
			}
		} else {
			int pos=0;
			for (int i=0;i<use.size();i++) {
				for (int j=0;j<use[i].first;j++) {
					if (ans[pos]!=-1) { pos=(pos+1)%n; }
					ans[pos]=use[i].second;
					pos=(pos+2)%n;
				}
			}
		}
		bool first = true;
		for (int kk=0;kk<n;kk++) {
			if (first) first = false;
			else cout<<" ";
			cout<<ans[kk]+1;
		}
		cout<<endl;
	}
	
	return 0;
}