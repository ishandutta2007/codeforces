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
	int n;
	cin>>n;
	
	int last, tmp;
	long long ans=0, cant=0;
	for (int i=0;i<n;i++) {
		cin>>tmp;
		if (i>0 && last==tmp) {
			cant++;
		} else {
			ans+=(cant*(cant+1))/2;
			cant=1;
		}
		last=tmp;
	}
	ans+=(cant*(cant+1))/2;
	cout<<ans<<endl;
	
	return 0;
}