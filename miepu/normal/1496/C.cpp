#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> A,B;
	for(int i=0;i<2*n;i++){
		int x,y;cin>>x>>y;
		if(x==0)B.push_back(y);
		else A.push_back(x);
	}
	sort(A.begin(),A.end(),[](int x,int y){return abs(x)<abs(y);});
	sort(B.begin(),B.end(),[](int x,int y){return abs(x)<abs(y);});
	double res=0;
	for(int i=0;i<n;i++){
		res+=sqrt(A[i]*A[i]+B[i]*B[i]);
	}
	printf("%.12lf\n",res);
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}