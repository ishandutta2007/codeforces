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
#define mod 1000000009

int POW(int tp, int up)
{
	if (up==0) return 1;
	
	int mid=POW(tp, up/2);
	if (up%2==0) return (mid*mid)%mod;
	else return ((mid*mid)%mod)*tp%mod;
}

bool AsubB(string Sa, string Sb)
{
	if (Sa.size()>Sb.size()) return 0;
	
//	cerr<<Sa<<' '<<Sb<<"\n";
	int a1=0, b1=0, p1=0, p2=Sa.size();
	
	for (int i=p1; i<p2; i++) a1=(a1*29+Sa[i]-96)%mod, b1=(b1*29+Sb[i]-96)%mod;
	
	if (b1==a1) return 1;
	while (p2<Sb.size())
	{
		b1=(b1*29+Sb[p2]-96)%mod;
		b1-=((Sb[p1]-96)*POW(29, Sa.size()))%mod;
		if (b1<0) b1+=mod;
		if (a1==b1) return 1;
		p2++, p1++;
	}
//	cerr<<"\n\n";
	return 0;
}

int n;
string S[1005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i];
	
	cerr<<1<<"\n";
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (!AsubB(S[i], S[j]) && !AsubB(S[j], S[i])) 
	{
		cout<<"NO";
		return 0;
	}
	
	for (int i=2; i<=n; i++)
	{
		for (int j=i-1; j>=1; j--)
		{
			if (AsubB(S[j+1], S[j]))
			{
				string temp;
				temp=S[j+1];
				S[j+1]=S[j];
				S[j]=temp;
			}
			else break;
		}
	}
	cerr<<1<<"\n";
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<S[i]<<"\n";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: