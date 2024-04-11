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
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int A, B, C, N;
	cin>>A>>B>>C>>N;
	
	int BD=A-C, BK=B-C;
	
	if (BD<0 || BK<0) cout<<-1;
	else if (N-BD-BK-C>0) cout<<N-BD-BK-C;
	else cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: