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

#define MAX 28000000
#define INF 2100000000

long long a,b,k;

int maxp[MAX];
int first[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int tot;

int cant(int multi) {
	return b/multi - (a-1)/multi;
}

int in(int mask) {
	long long val=1;
	for (int i=0;i<tot;i++) if (mask&(1<<i)) {
		val*=first[i];
		if (val>INF) val=INF;
	}
	int bit=bits(mask);
	if (bit%2==1) return -cant(val);
	return cant(val);
}

void init() {
	for (int i=2;i<MAX;i++) maxp[i]=i;
	for (int i=2;i*i<MAX;i++) if (maxp[i]==i){
		for (int j=i*i;j<MAX;j+=i) maxp[j]=min(maxp[j],i);
	}
}

int primo(int a) {
	for (int i=2;i*i<=a;i++) if (a%i==0) return false;
	return true;
}

int main(){
	cin>>a>>b>>k;
	a=(a+k-1)/k; b/=k;
	
	if (!primo(k)) {
		cout<<"0"<<endl;
		return 0;
	}
	int ans=0;
	if (k>71) {
		init();
		if (a==1 && a<=b) ans++;
		for (int i=max(a,2LL);i<=b;i++) if (maxp[i]>=k) ans++;
	} else {
		for (int i=0;i<20;i++) if (first[i]==k) tot=i;
		//ans=b-a+1;
		for (int m=0;m<(1<<tot);m++) ans+=in(m);
	}
	cout<<ans<<endl;
	
	return 0;
}