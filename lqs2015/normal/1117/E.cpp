#include<bits/stdc++.h>
using namespace std;
string t,p,q,w,pp,qq,ww;
char a,b,c;
int g[11111],n;
int main()
{
	cin>>t;
	n=t.size();
	a='a';b='a';c='a';
	for (int i=0;i<n;i++)
	{
		p+=a;q+=b;w+=c;
		if (c=='z')
		{
			c='a';
			if (b=='z')
			{
				b='a';
				a++;
			}
			else b++;
		}  
		else c++;
	}
	cout<<"? "<<p<<endl;
	fflush(stdout);
	cin>>pp;
	cout<<"? "<<q<<endl;
	fflush(stdout);
	cin>>qq;
	cout<<"? "<<w<<endl;
	fflush(stdout);
	cin>>ww;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (p[i]==pp[j] && q[i]==qq[j] && w[i]==ww[j]) 
			{
				g[i]=j;
				break;
			}
		}
	}
	cout<<"! ";
	for (int i=0;i<n;i++) cout<<t[g[i]];
	cout<<endl;
	fflush(stdout);
	return 0;
}