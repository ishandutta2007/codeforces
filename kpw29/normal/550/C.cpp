#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define root 1
#define maxn 300100
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
ll N,M,P,Q;
string s;
int main()
{
	cin >> s;
	int n = s.length();
	for (int i=0; i<n; ++i)
	  for (int j=i+1; j<n; ++j)
	    for (int k=j+1; k<n; ++k)
	    {
			int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
			if (num % 8 == 0) 
			{
				puts("YES");
				printf("%d", num);
				return 0;
			}
	}
	
	  for (int j=0; j<n; ++j)
	    for (int k=j+1; k<n; ++k)
	    {
			int num =(s[j] - '0') * 10 + s[k] - '0';
			if (num % 8 == 0) 
			{
				puts("YES");
				printf("%d", num);
				return 0;
			}
		}
		
	    for (int k=0; k<n; ++k)
	    {
			int num = s[k] - '0';
			if (num % 8 == 0) 
			{
				puts("YES");
				printf("%d", num);
				return 0;
			}
		}
	puts("NO");
}