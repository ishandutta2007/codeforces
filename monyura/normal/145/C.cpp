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

bool isHappy(int a)
{
	while (a)
	{
		if (a%10!=4 && a%10!=7) return false;
		a/=10;
	}
	return true;
}
int P=1000000007;

void Euclid(ll a,ll b,ll &x,ll &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	ll x0,y0;
	Euclid(b,a%b,x0,y0);
	x=y0;
	y=x0-(a/b)*y0;
}

ll C[100002]={0};

void fillC(int n,int k)
{
	C[0]=1;
	ll x,y;
	rep(i,1,k+1)
	{
		Euclid(i,P,x,y);
		x=(x+P)%P;
		C[i]=(((C[i-1]*(n-i+1))%P)*x)%P;
	}
}

int main()
{
	int n,k;
	int A[100001];
	cin>>n>>k;
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	int cnt=0;
	map<int,int> mp;
	rep(i,0,n)
	{
		if (isHappy(A[i])) mp[A[i]]++;
		else ++cnt;
	}
	if (cnt+mp.size()<k)
	{
		printf("0\n");
		return 0;
	}
	if (mp.size()>1024) 
		return 1;
	fillC(cnt,k);
	vector<pii> vec(mp.begin(),mp.end());
	ll Pr[110000]={1};
	ll D[110000]={1};
	rep(i,0,vec.size())
	{
		D[0]=1;
		rep(j,1,k+1)
			D[j]=(Pr[j-1]*vec[i].y+Pr[j])%P;
		memcpy(Pr,D,sizeof(Pr));
	}
	ll res=0;
	rep(i,0,k+1)
		res=(res+D[i]*C[k-i])%P;
	cout<<res<<endl;
	return 0;
} 

/*
3 3
744477744 77747444 447744444

*/