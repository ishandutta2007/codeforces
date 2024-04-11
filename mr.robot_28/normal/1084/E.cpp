#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
 	ll n, k, ans = 0, temp = 1, f = 0, x = 1;
 	cin >> n >> k;
 	string s1, s2;
 	cin >> s1 >> s2;
 	for(ll i=0;i<n;i++)
 	{
 		if(f == 0)
 		{	
 			x = (x * 2);
 			if(s1[i] == 'b') x -= 1;
 			if(s2[i] == 'a') x -= 1;
 			if(k <= x) f = 1;
 			else ans += x;
 		}
 		if(f == 1) ans += k;
 	}   
 	cout << ans << endl;
    return 0;
}