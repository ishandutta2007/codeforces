#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7, inv = 500000004;

struct TMat
{
    long long f[2][2];
}   input, base;
int n;
long long a, prod = 1;

inline TMat operator * (const TMat &a, const TMat &b)
{
    TMat ans;
    ans.f[0][0] = (a.f[0][0] * b.f[0][0] + a.f[0][1] * b.f[1][0]) % mod;
    ans.f[0][1] = (a.f[0][0] * b.f[0][1] + a.f[0][1] * b.f[1][1]) % mod;
    ans.f[1][0] = (a.f[1][0] * b.f[0][0] + a.f[1][1] * b.f[1][0]) % mod;
    ans.f[1][1] = (a.f[1][0] * b.f[0][1] + a.f[1][1] * b.f[1][1]) % mod;
    return ans;
}

inline TMat operator ^ (const TMat &a, const long long &b)
{
	if (b == 1)
		return a;
	TMat ans = a ^ (b / 2);
	ans = ans * ans;
	if (b & 1)
		ans = ans * a;
	return ans;
}

inline long long pow(const long long &a, const long long &b)
{
	if (b == 0)
		return 1;
	long long ans = pow(a, b / 2);
	ans = ans * ans % mod;
	if (b & 1)
		ans = ans * a % mod;
	return ans;
}

void init()
{
	input.f[0][1] = input.f[1][0] = input.f[1][1] = base.f[0][0] = 0;
	input.f[0][0] = base.f[0][1] = base.f[1][1] = 1;
	base.f[1][0] = 2;
}

int main()
{
    scanf("%d", &n);
    init();
    while (n--)
    {
    	scanf("%I64d", &a);
    	prod *= (a % (mod - 1)); prod %= (mod - 1);
    	base = base ^ a;
    }
    input = input * base;
    printf("%I64d/%I64d", input.f[0][0] * inv % mod, pow(2, prod) * inv % mod);
}