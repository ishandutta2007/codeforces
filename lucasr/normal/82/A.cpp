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

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(){
	int n, tot=5;
	cin>>n;
	
	while (n>tot) {
		n-=tot;
		tot*=2;
	}
	tot/=5;
	for (int i=1;i<=5;i++) {
		if (n<=i*tot) {
			cout<<names[i-1]<<endl;
			break;
		}
	}
	
	return 0;
}