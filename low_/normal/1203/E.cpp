#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define int long long
#define mod 1000000009
#define inf 4444444444444444444
#define mn 150005

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	deque <int> V(n), cnt;
	cnt.assign(mn, 0);
	for (int i=0; i<n; i++) 
	{
		cin>>V[i];
		cnt[V[i]]++;
	}
	
	int ans=0;
	for (int i=mn-5; i>0; i--) if (cnt[i]>0)
	{
		if (cnt[i+1]==0) 
		{
			cnt[i]--;
			cnt[i+1]++;
			i++;
		}
		else 
		{
			if (cnt[i]==1) continue;
			
			cnt[i-1]++;
			cnt[i]--;
		}
		
	}
	for (int i=mn-4; i>0; i--) ans+=(cnt[i]>0);
	cout<<ans;
	
}