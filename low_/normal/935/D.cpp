#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define mod 1000000007

int POW(int tp, int up)
{
	if (up==0) return 1;
	if (up==1) return tp%mod;
	
	int m=POW(tp, up/2);
	if (up%2==0) return (m*m)%mod;
	else return ((m*m)%mod*tp)%mod;
}
 
class fraction{
public:
	int Tu, Mau;
	
	fraction()
	{
		Tu=0;
		Mau=1;
	}
	
	void Simplify()
	{
		Tu%=mod;
		Mau%=mod;
		if (Tu<0) Tu+=mod;
		if (Mau<0) Mau+=mod;
	}
	
	fraction(int T, int M)
	{
		Tu=T;
		Mau=M;
		Simplify();
	}
	
	void Make(int T, int M)
	{
		Tu=T;
		Mau=M;
		Simplify();
	}
	
	int PQmod()
	{
		return (Tu*POW(Mau, mod-2))%mod;
	}
};
 
fraction operator + (fraction a, fraction b)
{
	fraction ret(a.Tu*b.Mau+b.Tu*a.Mau, a.Mau*b.Mau);
	return ret;
}
 
fraction operator - (fraction a, fraction b)
{
	fraction ret(a.Tu*b.Mau-b.Tu*a.Mau, a.Mau*b.Mau);
	return ret;
}
 
fraction operator * (fraction a, fraction b)
{
	fraction ret(a.Tu*b.Tu, a.Mau*b.Mau);
	return ret;
}

int S1[mn], S2[mn];

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n, m;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>S1[i];
	for (int i=1; i<=n; i++) cin>>S2[i];
	
	fraction ans, temp(1, 1);
	for (int i=1; i<=n; i++)
	{
		if (S1[i]==0 && S2[i]==0)
		{
			fraction temp1(m-1, 2*m);
			ans=ans+(temp*temp1);
			temp1.Make(1, m);
			temp=temp*temp1;
		}
		else if (S1[i]==0)
		{
			fraction temp1(m-S2[i], m);
			ans=ans+(temp*temp1);
			temp1.Make(1, m);
			temp=temp*temp1;
		}
		else if (S2[i]==0)
		{
			fraction temp1(S1[i]-1, m);
			ans=ans+(temp*temp1);
			temp1.Make(1, m);
			temp=temp*temp1;
		}
		else
		{
			if (S1[i]>S2[i]) 
			{
				ans=ans+temp;
				break;
			}
			else if (S1[i]<S2[i]) break;
		}
	}
	
	cout<<ans.PQmod();
}