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
	if (bits(5)>5);
	
	int n,a,b,tmp;
	cin>>n>>a>>b;
	int tot[6];
	vector<int> list;
	
	memset(tot,0,sizeof(tot));
	for (int i=0;i<n;i++) {
		cin>>tmp;
		list.push_back(tmp);
		tot[tmp]++;
	}
	
	if (a==b) {
		for (int i=0;i<a;i++) cout<<"1 ";
		for (int i=0;i<a;i++) cout<<"2 ";
	} else {
		int first[6];
		memset(first,0,sizeof(first));
		if (a<b) {
			int total=a;
			for (int m=5; m>=1;m--) {
				first[m]=min(total,tot[m]);
				total-=first[m];
			}
		} else {
			int total2=a;
			for (int m=1; m<=5;m++) {
				first[m]=min(total2,tot[m]);
				total2-=first[m];
			}
		}
		
		for (int i=0;i<n;i++) {
			//cout<<i<<" "<<n<<" "<<list[i]<<" "<<first[list[i]]<<endl;
			if (first[list[i]]) {
				cout<<"1 ";
				first[list[i]]--;
			} else cout<<"2 ";
		}
	}
	
	cout<<endl;
	
	return 0;
}