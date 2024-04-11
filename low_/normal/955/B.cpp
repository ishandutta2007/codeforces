#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int sc=0, cnt[26];
	string S;
	cin>>S;
	
	for (int i=0; i<26; i++) cnt[i]=0;
	for (int i=0; i<S.size(); i++) cnt[S[i]-'a']++;
	
	for (int i=0; i<26; i++) if (cnt[i]>0) sc++;
	
	if (sc>4 || sc==1) cout<<"no";
	else if (sc==4) cout<<"yes";
	else if (sc==3)
	{
		if (S.size()>3) cout<<"yes";
		else cout<<"no";
	}
	else 
	{
		for (int i=0; i<26; i++) if (cnt[i]==1)
		{
			cout<<"no";
			return 0;
		}
		cout<<"yes";
	}
}