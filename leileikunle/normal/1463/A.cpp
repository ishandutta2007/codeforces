#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int a,b,c; cin>>a>>b>>c;
		int d[3]={0};
		int maxn = max(a,b);
		maxn = max(maxn,c);
		int minn = min(a,b);
		minn = min(minn,c);
		int minnn = a+b+c-maxn-minn;
		d[0] = minn;
		d[1] = minnn;
		d[2] = maxn;
		
		int e = a+b+c;
		if(e%9==0&& d[0]>=(e/9))
		{
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}