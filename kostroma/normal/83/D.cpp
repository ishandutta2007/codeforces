#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;
#define mp make_pair
#define pb push_back

void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        solve ();
        return 0;
}
//#define int li
int k, u=0;
int prost[50050];
int numbers[25000000];
bool good (int z)
{
	bool f=true;
	for (int i=0; i<u; i++)
		if (z%prost[i]==0)
	{
		f=false;
		break;
	}
	return f;
}
int answer (int b)
{
	if (b==0 || b==1)
		return 0;
	if ( k>b )
		return 0;
	if ( (li)k*k>(li)b )
		return 1;
	int ans=1;
	memset (numbers, 0, sizeof numbers);
	int p=0;
	for (li i=k; (li)i*k<=(li)b; i+=2)
		numbers[p++]=i;
	/*
	if (b==12000-1)
	{
		for (int i=0; i<p; i++)
			cout<<numbers[i]<<' ';
		cout<<endl;
	}*/

	for ( int i=1; i<u; i++ )
	{
		int z=k%prost[i];
		int rest=-z/2+prost[i];
		if (z%2)
			rest=(-z+prost[i])/2;

		for (int j=rest; j<p; j+=prost[i])
		{
			/*if (b==12000-1)

			cout<<numbers[j]<<' ';*/
			numbers[j]=-1;
		}
		//cout<<endl;
	}
	for (int i=0; i<p; i++)
		if (numbers[i]>-1)
			ans++;
	return ans;
}
int num ( int b, int pr, vector <int> rests )
{
	int sum=0;
	for (int i=0; i<rests.size(); i++)
	{
		int cur=rests[i];
		int z=b/pr;
		sum+=z;
		sum+=(b-z*pr>=rests[i])?1:0;
	}
	return sum;
}
int doing (int b)
{
	if (b<2)
		return 0;
	int pr=1;
	for (int i=0; i<=u; i++)
		pr*=prost[i];
	vector <int> good;
	for (int i=0; i<pr; i++)
	{
		bool f=true;
		for (int j=0; j<=u; j++)
			if (i%prost[j]==0)
			{
				f=false;
				break;
			}
		if (f)
		{
		good.pb (i);
		//cout<<i<<"  "<<pr<<" "<<endl;
		}
	}
	int l=0;
	for ( int step=k; step<=b; step*=prost[u] )
	{
		int z=b/step;
		l+=num (z, pr, good);
	}
	return l;
}
int doing1 (int b)
{
	b=b/k;
	int ans=0;
	for (int mask=1; mask<(1<<(u)); mask++)
	{
		int z=0; li pr=1;
		for ( int i=0; i<u; i++ )
			if ( mask & (1<<i) )
			{
				z++;
				pr*=(li)prost[i];
			}
		li dob=(li)b/pr;
		if (z%2)
			ans+=(int)dob;
		else
			ans-=(int)dob;
	}
	return b-ans;
}
void solve ()
{
	int a, b;
	cin>>a>>b>>k;
	bool f=true;
	for (li i=2; i*i<=(li)k; i++)
		if ((li)(k)%i==0)
		{
			f=false;
			break;
		}
	if (!f)
	{
		cout<<"0";
		return;
	}
	int t=0;
	for (li i=2; i*i<=(li)b; i++)
	{
		bool f=true;
		for (int j=2; j*j<=i; j++)
			if (i%j==0)
		{
			f=false;
			break;
		}
		if (f)
		{
			prost[t++]=i;
			if (i==k)
				u=t-1;
		}
	}
	if (u>=24 || k>prost[t-1])
		cout<<answer(b)-answer(a-1);
	else
		cout<<doing1(b)-doing1 (a-1);
}