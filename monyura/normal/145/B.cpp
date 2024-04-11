#pragma comment(linker,"/STACK:62000000")
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
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> inline T SQR(T a){return a*a;}

int main()
{
	int a[5];
	rep(i,1,5)
		cin>>a[i];
	int b[5];
	memcpy(b,a,sizeof(a));
	char res[4000004]={0};
	char out[4000004]={0};
	int pos=0;
	rep(i,0,a[3])
	{
		res[pos++]='4';
		res[pos++]='7';
	}
	int cnt[300]={0};
	if (a[4]==a[3]-1 || a[4]==a[3])
	{
		if (a[4]==a[3])
			res[pos++]='4';
	}
	else
		a[1]=-1;
	rep(i,0,pos)
		cnt[res[i]]++;
	char F[1000002]={0};
	char S[1000002]={0};
	if (a[1]>=cnt['4'] && a[2]>=cnt['7'])
	{
		rep(i,0,a[1]-cnt['4'])
			F[i]='4';
		rep(i,0,a[2]-cnt['7'])
			S[i]='7';
		int lst=0;
		rep(i,0,pos)
			if (res[i]=='7') lst=i;
		int in=0;
		rep(i,0,pos)
		{
			if (res[i]=='4' && F[0])
			{
				strcat(out+in,F);
				in+=strlen(F);
				F[0]=0;
			}
			if (i==lst)
			{
				strcat(out+in,S);
				in+=strlen(S);
			}
			out[in++]=res[i];
		}
		printf("%s\n",out);
		return 0;			
	}
	memcpy(a,b,sizeof(a));
	memset(res,0,pos+1);
	pos=0;
	rep(i,0,a[4])
	{
		res[pos++]='7';
		res[pos++]='4';
	}
	memset(cnt,0,sizeof(cnt));
	if (a[3]==a[4]-1 || a[3]==a[4])
	{
		if (a[3]==a[4])
			res[pos++]='7';
	}
	else
		a[1]=-1;
	rep(i,0,pos)
		cnt[res[i]]++;
	if (a[1]>=cnt['4'] && a[2]>=cnt['7'])
	{
		rep(i,0,a[1]-cnt['4'])
			F[i]='4';
		rep(i,0,a[2]-cnt['7'])
			S[i]='7';
		int lst=0;
		rep(i,0,pos)
			if (res[i]=='7') lst=i;
		int in=0;
		rep(i,0,pos)
		{
			if (res[i]=='4' && F[0])
			{
				strcat(out+in,F);
				in+=strlen(F);
				F[0]=0;
			}
			if (i==lst)
			{
				strcat(out+in,S);
				in+=strlen(S);
			}
			out[in++]=res[i];
		}
		printf("%s\n",out);
		return 0;			
	}
	printf("-1\n");
	return 0;
} 

/*
4 2 2 1

2 4 2 2
3 5 2 2
*/