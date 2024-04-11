#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[25],sem[25],m;
bool bkt (int poz, int sum)
{
	if(poz==m)
	{
		if((sum+v[poz])%360==0)
		{
			sem[poz]=1;
			return true;
		}
		else
		if((sum-v[poz])%360==0)
		{
			sem[poz]=0;
			return true;
		}
		return false;
	}
	else
	{
		if(bkt(poz+1,sum+v[poz]))
		{
			sem[poz]=1;
			return true;
		}
		else
		if(bkt(poz+1,sum-v[poz]))
		{
			sem[poz]=0;
			return true;
		}
		return false;
	}
}
int main()
{
    long long n,i,j,mn=99999999999,mx=-999999999999,s=0,cnt=0,ok=0,k=0;
    char a,b,ac,bc;
    cin>>m;
    for(i=1;i<=m;++i)
        cin>>v[i];
    i=bkt(1,0);
    if(i)
        cout<<"YES";
    else
        cout<<"NO";
}