#include<iostream>
#include<fstream>
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
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S; deque <char> D;
	cin>>S;
	D.clear();
	for (int i=S.size()-1; i>=0; i--) if (S[i]!='1') D.push_front(S[i]);
	
	int c1=S.size()-D.size(), c0=0;
	while (!D.empty()) 
	{
		if (D.front()!='0') break;
		D.pop_front(), c0++;
	}
	
	cerr<<c1<<" "<<c0;
	while (c1--) D.push_front('1');
	while (c0--) D.push_front('0');
	
	for (char i:D) cout<<i;
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: