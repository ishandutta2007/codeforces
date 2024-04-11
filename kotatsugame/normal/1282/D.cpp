#include<iostream>
#include<cstdlib>
using namespace std;
int q(const string&s)
{
	cout<<s<<endl;
	int ret;cin>>ret;
	if(ret==0)exit(0);
	return ret;
}
main()
{
	int x=q("a");
	string ret(x,'b');
	int ac=q(ret);
	ret+="b";
	int N=x+1;
	int pre=ac;
	for(int i=0;i<N;i++)
	{
		ret[i]='a';
		int now=q(ret);
		if(now>pre)ret[i]='b';
		else pre=now;
	}
}