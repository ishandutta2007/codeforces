# include <iostream>
# include <cstdio>
using namespace std;

void gcd(int a,int b)
{
	int ans=0,t;
	if(a==0)return;
	while(b>0){t=a;a=b;ans+=t/a;b=t%a;}
	cout<<ans<<endl;
}

int main()
{
	int n,a,b;
	cin >> n;
	while(n--){cin>>a>>b;gcd(a,b);}
	return 0;
}