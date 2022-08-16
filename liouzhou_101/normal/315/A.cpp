#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n;
int a[110],b[110],u[110];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i]>>b[i];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j) if (i!=j)
			if (b[i]==a[j]) u[j]=1;
	int p=0;
	for (int i=1;i<=n;++i)
		p+=1-u[i];
	cout<<p<<endl;
	return 0;
}