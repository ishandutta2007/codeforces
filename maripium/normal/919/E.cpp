#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const double pi=acos(-1);
int a,b,p,x,ans=0;
int powmod(int index){
	if(index==0)return 1;
	if(index==1)return a;
	int cur=powmod(index/2);
	cur=(cur*cur)%p;
	if(index%2)return (cur*a)%p;
	return cur;
}
signed main()	{
	cin>>a>>b>>p>>x;
	for(int i=0;i<p-1;++i)	{
		int r1=b*powmod(i*(p-2)%(p-1))%p;
		int r2;
		if(i>=r1)r2=i+(i-r1)*(p-1);
		else r2=p+i-1+(p+i-1-r1)*(p-1);
		ans+=((x-r2)/(p*(p-1)))+(x>=r2);
		//cout<<r1<<' '<<r2<<endl;
		//cout<<ans
	} 
	
	cout<<ans;
}