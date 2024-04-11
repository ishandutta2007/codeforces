#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
#include<sstream>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n;
	cin>>n;
	string S;
	char act;
	bool able[26], cur[26];
	int cnt=26, ans=0;
	for (int i=0; i<26; i++) able[i]=1;
	while (n>1)
	{
		n--;
		cin>>act;
		if (act=='!')
		{
			cin>>S;
			if (cnt>1)
			{
				for (int i=0; i<26; i++) cur[i]=0;
				for (int i=0; i<S.size(); i++) cur[S[i]-'a']=1;
				for (int i=0; i<26; i++) if (able[i] && !cur[i])
				{
					cnt--;
					able[i]=0;
				}
			}
			else ans++;
		}
		else if (act=='.')
		{
			cin>>S;
			if (cnt>1)
			{	
				for (int i=0; i<26; i++) cur[i]=1;
				for (int i=0; i<S.size(); i++) cur[S[i]-'a']=0;
				for (int i=0; i<26; i++) if (able[i] && !cur[i])
				{
					cnt--;
					able[i]=0;
				}
			}
		}
		else
		{
			cin>>act;
			if (cnt==1) ans++;
			else 
			{
			    if (able[act-'a']) cnt--;
				able[act-'a']=0;
			}
		}
	}
	cin>>act>>S;
	cout<<ans;
	return 0;
}