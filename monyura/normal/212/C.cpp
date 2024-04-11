#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

ll calc(char *str)
{
	int n=strlen(str);
	int pos=-1;
	rep(i,0,n)
		if (str[i]=='A' && str[(i+1)%n]=='B' && str[(i+2)%n]=='B')
			pos=i;
	ll F[60]={0,1};
	rep(i,2,60)
		F[i]=F[i-1]+F[i-2];
	if (pos==-1)
		return F[n/2]+2*F[n/2-1];
	rotate(str,str+pos,str+n);
	vector<char> vec;
	for (int i=0;i<n-1;i++)
	{
		if (str[i]=='A' && str[i+1]=='B' && str[(i+2)%n]=='B')
			vec.push_back('B');
		else if (str[i]=='A' && str[i+1]=='A' && str[(i+2)%n]=='B')
		{
			vec.push_back('A');
			i++;
		}
		else if (str[i]=='A' && str[i+1]=='B' && str[(i+2)%n]=='A')
			vec.push_back(0);
	}
	ll open=1;
	ll close=0;
	for (int i=vec.size()-1;i!=0;i--)
	{
		if (vec[i]==0)
		{
			ll s=open+close;
			close=open;
			open=s;
		}
		else if (vec[i]=='B')
		{
			open=open+close;
			close=0;
		}
		else if (vec[i]=='A')
		{
			close=open;
			//open=1;
		}
	}
	return open+close;
}

ll check(char *pat)
{
	char str[100]={0};
	int res=0;
	int n=strlen(pat);
	rep(i,0,1<<n)
	{
		rep(j,0,n)
			str[j]='A'+((i>>j)&1);
		bool rev[20]={0};
		rep(j,0,n-1)
			if (str[j]=='A' && str[j+1]=='B')
				rev[j]=rev[j+1]=1;
		if (str[n-1]=='A' && str[0]=='B')
			rev[n-1]=rev[0]=1;
		rep(j,0,n)
			if (rev[j])
				str[j]='A'+(str[j]=='A');
		if (strcmp(str,pat)==0)
			++res;
	}
	return res;
}

ll getCnt(char *str)
{
	int n=strlen(str);
	int C[2]={0};
	rep(i,0,n)
		C[str[i]-'A']++;
	if (C[0]==0 || C[1]==0)
		return 1;
	bool bad=0;
	
	char pat[5]="AABB";
	if (n>3)
	{
		rep(i,0,n)
		{
			bool same=true;
			rep(j,0,4)
				if (str[(i+j)%n]!=pat[j])
					same=false;
			bad|=same;
		}
	}
	if (bad)
		return 0;
	strcpy(pat,"ABB");
	bool ok=0;
	rep(i,0,n)
	{
		bool same=true;
		rep(j,0,3)
			if (str[(i+j)%n]!=pat[j])
				same=false;
		ok|=same;
	}
	if (!ok)
	{
		reverse(str,str+n);
		rep(i,0,n)
			if (str[i]=='A')
				str[i]='B';
			else 
				str[i]='A';
	}
	ll res=calc(str);
	return res;
}

void run()
{
	char str[200];
	scanf("%s",str);
	ll res=getCnt(str);
	cout<<res<<endl;
	/*check(str);
	rep(i,0,1e9)
	{
		if (i%100==1)
			printf("%d\n",i);
		int n=10;
		str[n]=0;
		rep(i,0,n)
			str[i]='A'+(rand()&1);
		ll r=getCnt(str);
		ll c=check(str);
		if (r!=c)
		{
			printf("%s res=%lld check=%lld\n",str,r,c);
			system("pause");
		}
	}*/
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	time_t beg=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/