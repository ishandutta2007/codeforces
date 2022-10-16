#include <bits/stdc++.h>
using namespace std;
const int N=65;
const int Mod=1e9+7;
long long val[N],k;
map <long long,bool> haveval[10],cant[10];
map <long long,long long> d[10];
long long getval(long long id,int col)
{
	if(cant[col][id])
		return 0;
	if(haveval[col][id])
		return d[col][id];
	int dep=floor(log2(id))+1;
	return val[dep];
}
void calc(long long id,int col)
{
	if(cant[col][id])
		return;
	haveval[col][id]=true;
	int dep=floor(log2(id))+1;
	if(dep==k)
	{
		d[col][id]=1;
		return;
	}
	int cantcol=col;
	if(col%2==1)
		cantcol++;
	else
		cantcol--;
	long long sumleft=0,sumright=0;
	for(int i=1;i<=6;i++)
		if(i!=col && i!=cantcol)
		{
			sumleft=(sumleft+getval(id*2,i))%Mod;
			sumright=(sumright+getval(id*2+1,i))%Mod;
		}
	d[col][id]=sumleft*sumright%Mod;
}
void update(long long id,int col)
{
	for(int i=1;i<=6;i++)
		if(i!=col)
			cant[i][id]=true;
 
	while(id)
	{
		for(int i=1;i<=6;i++)
			calc(id,i);
		id/=2;
	}
}
int main()
{
	cin >> k;
	val[k]=1;
	for(int i=k-1;i>=1;i--)
		val[i]=val[i+1]*val[i+1]%Mod*16%Mod;
	int T;
	cin >> T;
	while(T--)
	{
		long long id;
		char c[10];
		scanf("%lld %s",&id,c);
		if(c[0]=='w') update(id,1);
		else if(c[0]=='y') update(id,2);
		else if(c[0]=='g') update(id,3);
		else if(c[0]=='b') update(id,4);
		else if(c[0]=='r') update(id,5);
		else update(id,6);
	}
	long long ans=0;
	for(int i=1;i<=6;i++)
		ans=(ans+getval(1,i))%Mod;
	printf("%lld\n",ans);
	return 0;
}