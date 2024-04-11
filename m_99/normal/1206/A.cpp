#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)cin>>A[i];
	
	int m;
	cin>>m;
	vector<int> B(m);
	for(int i=0;i<m;i++)cin>>B[i];
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	cout<<A[n-1]<<' '<<B[m-1]<<endl;
	
	return 0;
}