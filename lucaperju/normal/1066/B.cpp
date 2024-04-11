#include <iostream>
const int N=10000000;
using namespace std;
long long rez[10000003];
int v[5005];
int main()
{
	int t,i,j,cnt=0,a,b,c,d,r,m,pr=0,pz=-1,n;
	cin>>n>>r;
	for(i=1;i<=n;++i)
	{
	    cin>>v[i];
	}
	for(i=1;i<=n;++i)
	{
        if(v[i]==1)
        {
            if(i-r<=pr)
                pz=i;
            else
            {
                if(pz==-1)
                {
                    cout<<-1;
                    return 0;
                }
                else
                {
                    ++cnt;
                    pr=pz+r-1;
                    --i;
                    pz=-1;
                }
            }
        }
	}
	if(pr<n)
	{
	    if(pz==-1)
        {
            cout<<-1;
            return 0;
        }
        else
        {
            pr=pz+r-1;
            ++cnt;
        }
        if(pr<n)
        {
            cout<<-1;
            return 0;
        }
	}
        cout<<cnt;
}