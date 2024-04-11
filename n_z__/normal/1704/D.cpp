#include <bits/stdc++.h>
#define int long long
#define double long double
#define mid ((l+r)>>1)
using namespace std;
signed main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int c[n+1][m+1];
		__int128 d[n+1];
		__int128 maxv=0;
		for(int i=1;i<=n;i++){
			d[i]=0;
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				d[i]=d[i]+c[i][j]*j;
			}
			maxv=max(maxv,d[i]);
		}
		__int128 dif,pos;
		for(int i=1;i<=n;i++){
			if(d[i]!=maxv){
				dif=maxv-d[i];
			}
			else{
				pos=i;
			}
		}
		int D=dif,P=pos;
		cout<<P<<" "<<D<<endl;
	}
	return 0;
}
/*things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <= , - or =
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. if you don't know where the bug is , try to clear some parts of the code
 and check each part seperately.
13. ...
*/