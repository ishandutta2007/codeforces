#include <bits/stdc++.h>

#define REPP(i,a,b,d) for(int i=a; i<=b; i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a; i>=b; i-=d)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

// end of macro

const int N = 105;

int n;
int arr[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#define endl '\n'
	cin>>n;
	REP(i,1,n)cin>>arr[i];
	arr[0] = 0;
	arr[n+1] = 1001;
	arr[n+2] = 10000;
	int s = 0;
	int ans = 0;
	while(s <= n){
		int j = s+1;
		while(arr[j]-arr[s] == j-s)j++;
		//printf("%d-%d\n",s,j);
		ans = max(ans, max(0, j-s-2));
		s = j;
	}
	cout << ans << endl;
	
	return 0;
}