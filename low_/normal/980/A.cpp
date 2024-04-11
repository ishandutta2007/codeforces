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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	cin>>S;
	int prl=0, lnk=0;
	for (int i=0; i<S.size(); i++) prl+=(S[i]=='o'), lnk+=(S[i]=='-');
	
	
	if (prl==0) cout<<"YES";
	else if (lnk%prl==0) cout<<"YES";
	else cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: