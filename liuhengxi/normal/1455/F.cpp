#include<iostream>
#include<string>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
int tt,n,k;
string s,f[N];
int main()
{
	cin>>tt;
	while(tt--)
	{
		cin>>n>>k>>s;
		F(i,1,n+1)f[i]=f[i-1]+"|";
		F(i,1,n+1)
		{
			char x=s[i-1];
			if(i>1&&i<n)f[i+1]=min(f[i+1],f[i-1].substr(0,i-2)+s[i]+f[i-1].substr(i-2,i-1)+x);
			if(i>1)f[i]=min(f[i],f[i-1].substr(0,i-2)+x+f[i-1].substr(i-2,i-1));
			(x!='a')&&(x=='a'+k-1?x='a':--x);
			if(i>1)f[i]=min(f[i],f[i-2]+x+s[i-2]);
			f[i]=min(f[i],f[i-1]+x);
			if(i<n)f[i+1]=min(f[i+1],f[i-1]+s[i]+x);
		}
		cout<<f[n]<<endl;
	}
	return 0;
}