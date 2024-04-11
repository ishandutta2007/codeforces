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
	
	int n;
	cin>>n;
	if (n<20)
	{
		int ans[21]={0,4,10,20,35,56,83,116,155,198,244,292,341,390,439,488,537,586,635,684};
		cout<<ans[n];
		return 0;
	}
	
	int ans=0;
	for (int x=0; x<9; x++) ans+=(n-x+1);
	for (int v=1; v<9; v++) for (int x=0; x<5; x++) ans+=(n-v-x+1);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: