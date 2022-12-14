#include <iostream>
#include <math.h>
#define int long long 
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;  cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[2*n] = {0};
		int b[200002] = {0};
		int maxn = 0;
		for(int i=1;i<=n;i++){
			 cin>>a[i];
			 b[a[i]]++;
			 maxn = max(maxn,a[i]);
		}
		int sum = 0;
		for(int i=1;i<=maxn+1;i++)
		{
			if(b[i]>=2){
				b[i+1]++; sum++;
			}else if(b[i] == 1){
			sum++;
			}
		}
		cout<<sum<<endl;
	}
}