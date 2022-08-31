#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		int x=0;
		cin>>n;
		int nn=n;
		while(n--){
			int y;
			cin>>y;
			x+=(y%2);
		}
		cout<<min(x,nn-x)<<endl;
	}







	return 0;
}