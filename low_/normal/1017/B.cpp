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

string s1, s2;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cin>>s1>>s2;
	int t00=0, t01=0, t10=0, t11=0;
	for (int i=0; i<n; i++) t00+=(s1[i]=='0' && s2[i]=='0'), t01+=(s1[i]=='0' && s2[i]=='1'), t10+=(s1[i]=='1' && s2[i]=='0'), t11+=(s1[i]=='1' && s2[i]=='1');
	
	cout<<t00*t10+t00*t11+t01*t10;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: