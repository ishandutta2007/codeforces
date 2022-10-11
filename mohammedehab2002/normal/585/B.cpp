#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,k,t,i,x,j,c;
	string s[3];
	cin >> t;
	for (x=0;x<t;x++)
	{
		cin >> n >> k >> s[0] >> s[1] >> s[2];
		bool b[3];
		for (i=0;i<3;i++)
		{
			s[i]+="....";
			b[i]=(s[i][0]=='s');
			if (s[i][1]!='.')
			b[i]=false;
		}
		j=1;
		while (j<n)
		{
			bool b2[]={false,false,false};
			for (i=0;i<3;i++)
			{
				if((i!=0 && b[i-1]) || b[i] || (i!=2 && b[i+1]))
				{
					b2[i]=true;
					for (c=j;c<=j+3;c++)
					{
						if (s[i][c]!='.')
						b2[i]=false;
					}
				}
			}
			copy(b2,b2+3,b);
			j+=3;
		}
		if (b[0] || b[1] || b[2])
		cout << "YES" << endl;
		else
		cout << "NO" << endl;
	}
}