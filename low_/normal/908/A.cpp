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

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	string S;
	cin>>S;
	int ans=0;
	set <char> ss={'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
	
	for (int i=0; i<S.size(); i++) ans+=(int)(ss.count(S[i])==1);
	cout<<ans;
}