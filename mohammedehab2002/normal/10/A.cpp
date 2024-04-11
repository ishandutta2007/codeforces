#include <iostream>
using namespace std;
int main()
{
	int n,p1,p2,p3,t1,t2,res=0,s,i,l[200],r[200];
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	for (i=1;i<=n;i++)
	{
		cin >> l[i] >> r[i];
		res+=(r[i]-l[i])*p1;
	}
	for (i=1;i<n;i++)
	{
		s=l[i+1]-r[i];
		if (s>=t1+t2)
		res+=t1*p1+t2*p2+(s-(t1+t2))*p3;
		else if (s>=t1)
		res+=t1*p1+(s-t1)*p2;
		else
		res+=s*p1;
	}
	cout << res;
}