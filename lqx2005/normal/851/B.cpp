#include<bits/stdc++.h>
using namespace std;
int main()
{
	double ax,ay,bx,by,cx,cy,aa,bb,cc;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	aa=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	bb=(bx-cx)*(bx-cx)+(by-cy)*(by-cy);
	cc=(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy);
	aa=sqrt(aa);
	bb=sqrt(bb);
	cc=sqrt(cc);
	if(aa-bb==0)
	{
		if(aa+bb==cc)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;	
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}