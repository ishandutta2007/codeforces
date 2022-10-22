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

int cant[100050];
int n;
long long k;
long long ati(int val) {
	long long ans=0;
	for (int i=0;i<n;i++) ans+=min(cant[i],val);
	return ans;
}

int main(){
	cin>>n>>k;
	
	for (int i=0;i<n;i++) {
		cin>>cant[i];
	}
	
	int iz=0,de=1000000000;
	if (k==0) {
		for (int i=0;i<n;i++) cout<<(i+1)<<" ";
		cout<<endl;
		return 0;
	} else if (k>ati(de)) {
		cout<<"-1"<<endl;
		return 0;
	}
	
	while (iz+1<de) {
		int me=(iz+de)/2;
		
		if (k>ati(me)) iz=me;
		else de=me;
	}
	
	long long queda=k-ati(iz);
	int pos=-1;
	for (int i=0;i<n;i++) cant[i]-=min(cant[i],iz);
	for (int i=0;i<n;i++) {
		if (queda>0 && cant[i]>0) {
			pos=i;
			queda--;
			cant[i]--;
		}
	}
	int i=(pos+1)%n;
	do {
		if (cant[i]>0) cout<<(i+1)<<" ";
		i=(i+1)%n;
	} while (i!=(pos+1)%n);
	cout<<endl;
	return 0;
}