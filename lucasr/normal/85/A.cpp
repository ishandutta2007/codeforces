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
	
	if (n%2==0) {
		for (int i=0;i<n/2;i++) {if (i%2==0) cout<<"aa"; else cout<<"bb";}
		cout<<endl;
		cout<<"c";
		for (int i=0;i<n/2-1;i++) { if (i%2==0) cout<<"ff"; else cout<<"gg"; }
		cout<<"e"<<endl;
		cout<<"c";
		for (int i=0;i<n/2-1;i++) { if (i%2==0) cout<<"hh"; else cout<<"ii"; }
		cout<<"e"<<endl;
		for (int i=0;i<n/2;i++) {if (i%2==0) cout<<"ll"; else cout<<"kk";}
		cout<<endl;
	} else {
		for (int i=0;i<n/2;i++) { if (i%2==0) cout<<"aa"; else cout<<"bb"; }
		cout<<"c"<<endl;
		for (int i=0;i<n/2;i++) { if (i%2==0) cout<<"dd"; else cout<<"ee"; }
		cout<<"c"<<endl;
		cout<<"l";
		for (int i=0;i<n/2;i++) { if (i%2==0) cout<<"zz"; else cout<<"yy"; }
		cout<<endl<<"l";
		for (int i=0;i<n/2;i++) { if (i%2==0) cout<<"ww"; else cout<<"xx"; }
		cout<<endl;
	}
	
	return 0;
}