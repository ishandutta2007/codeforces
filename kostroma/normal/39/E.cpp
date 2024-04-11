#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cstdlib>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<memory.h>
#include<ctime>
#include<cctype>
 
using namespace std;
 
typedef long long li;
typedef pair <int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
const long double PI = 3.141592653589793238462643l;
void solve ();
 
int main()
{
        #ifdef _DEBUG
                freopen ("in.txt", "r", stdin);
        #endif
         solve();
        return 0;
}
#define int li
int n;
int st(int a, int b)
{
        li res=1;
        for(int i=0; i<b; i++)
        {
                if(res >= n)
                        return 1;
                res*=a;
        }
        if(res<n)
                return 0;
        return 1;
}
 
int qwerty (int s, int l, int r)
{
        if(l==1 && st(1, s))
                return -1;
        if(l+1==r)
                return l;
        if(st((l+r)/2, s))
                return qwerty(s, l, (l+r)/2);
        else
                return qwerty(s, (l+r)/2, r);
}
vector < vector <int> > x(41);
int mas[50];
int cnt ( int a, int b )
{
	if ( a>mas[b] )
		return 2;
	if ( a>1 && b>1 && x[b][a]!=-1 )
		return x[b][a];
	if ( b==1 && a!=1)
	{
		if (a<=mas[2])
		{
			if ( cnt (a+1, b)==1 || cnt (a, b+1)==1 )
				return x[b][a]=2;
			return x[b][a]=1;
		}
		else 
		{
			if ( (n-a)%2 )
				return 1;
			return 2;
		}
	}
	if ( a==1 )
	{
		if (b>=30)
		{
			//cout<<"!\n";
			return 0;
		}
		int z=cnt (a, b+1), t=cnt (a+1, b);
		//cout<<b<<' '<<z<<' '<<t<<endl;
		if ( t==1 || z==1)
			return x[b][a]=2;
		if ( z==0 )
			return x[b][a]=0;
		if (z==2)
			return x[b][a]=1;
	}
	int z=cnt (a, b+1), t=cnt (a+1, b);
	if ( z==1 || t==1 )
		return x[b][a]=2;
	return x[b][a]=1;
}
void solve()
{
        
        int a, b;
        cin>>a>>b;
        cin>>n;
        for(int i=1; i<=30; i++)
            mas[i]=qwerty(i, 1, n);
		x[1].resize(mas[2]+2);
		for ( int i=2; i<=30; i++)
			x[i].resize(mas[i]+2);
		for (int i=0; i<=30; i++)
			for (int j=0; j<x[i].size(); j++)
				x[i][j]=-1;
		int f=cnt (a, b);
		if ( f==2 )
			cout<<"Masha";
		else if (f==0)
			cout<<"Missing";
		else 
			if (f==1)
				cout<<"Stas";
        //cout << double(clock()) / CLOCKS_PER_SEC;
}