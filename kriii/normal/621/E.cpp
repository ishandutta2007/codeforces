#include <stdio.h>
#include <vector>
using namespace std;

int n,b,k,x,a[50005];

int pow(int a, int p)
{
	int r = 1;
	while (p){
		if (p & 1) r = r * a % x;
		a = a * a % x;
		p /= 2;
	}
	return r;
}

const long long mod = 1000000007;

void add(long long &a, long long b)
{
	a = (a + b) % mod;
}

vector<long long> con(vector<long long> a, vector<long long> b, int mul)
{
	vector<long long> r(x);
	for (int i=0;i<x;i++) for (int j=0;j<x;j++){
		add(r[(i*mul+j)%x],a[i]*b[j]);
	}
	return r;
}

vector<long long> base;

vector<long long> get(int n)
{
	if (n == 1) return base;
	int h = n / 2, v = pow(10,h);
	vector<long long> f = get(h);
	f = con(f,f,v);
	if (n % 2) f = con(base,f,v*v%x);
	return f;
}

int main()
{
	scanf ("%d %d %d %d",&n,&b,&k,&x);
	base = vector<long long>(x);
	for (int i=0;i<n;i++){
		int p; scanf ("%d",&p);
		base[p%x]++;
	}

	printf ("%lld\n",get(b)[k]);

	return 0;
}