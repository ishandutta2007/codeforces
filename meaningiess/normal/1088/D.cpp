#include<bits/stdc++.h>
using namespace std;
int n,m,a1,b1;
inline int sol(int re,int r)
{
	cout<<"? "<<re<<" "<<r<<endl;fflush(stdout);
	int w;cin>>w;return w;
} 
int main()
{
	int da=sol(0,0),i,ch;
	for (i=29;i>=0;i--)
	{
		ch=sol(a1|(1<<i),b1|(1<<i));
		if (ch!=da)
		{
			if (ch!=0)
			{
				if (ch!=1) (a1|=(1<<i));
				else b1|=(1<<i);
				da=sol(a1,b1);
			}
			else
			{
				if (da==1) b1|=(1<<i);
				else a1|=(1<<i);da=0;
			}
		}
		else if (sol(a1^(1<<i),b1)==-1) a1|=(1<<i),b1|=(1<<i);
	}
	cout<<"! "<<a1<<" "<<b1;fflush(stdout);
}