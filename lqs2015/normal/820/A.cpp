#include<iostream>
using namespace std;
int c,v0,v1,a,l,pos,rea,ans;
int main()
{
	cin>>c>>v0>>v1>>a>>l;
	rea=v0;
	for(ans=1;;ans++) 
	{
		pos=pos+rea;
		if (pos>=c) break;
		pos-=l;
		rea=min(v1,rea+a);
	}
	cout<<ans<<endl;
	return 0;
 }