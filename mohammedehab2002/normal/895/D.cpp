#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
string a,b;
int cnt[26];
long long fact[1000005],inv[1000005];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
long long go(string s)
{
	memset(cnt,0,sizeof(cnt));
	for (char i:a)
	cnt[i-'a']++;
	long long ans=0;
	for (int i=0;i<s.size();i++)
	{
		long long tmp=fact[s.size()-i-1];
		for (int x=0;x<26;x++)
		tmp=(tmp*inv[cnt[x]])%mod;
		for (int x=0;x<s[i]-'a';x++)
		{
			if (cnt[x])
			ans=(ans+(tmp*fact[cnt[x]])%mod*inv[cnt[x]-1])%mod;
		}
		cnt[s[i]-'a']--;
		if (cnt[s[i]-'a']<0)
		break;
	}
	return ans;
}
int main()
{
	cin >> a >> b;
	fact[0]=1;
	inv[0]=1;
	for (int i=1;i<1000005;i++)
	{
		fact[i]=(i*fact[i-1])%mod;
		inv[i]=pow_log(fact[i],mod-2);
	}
	cout << (go(b)-go(a)-1+mod)%mod;
}