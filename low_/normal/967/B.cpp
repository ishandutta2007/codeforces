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

int n, A, B, S[mn];
int mcd[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int tong=0;
	cin>>n>>A>>B;
	for (int i=0; i<n; i++) 
	{
		cin>>S[i];
		tong+=S[i];
	}
	
	sort(S+1, S+n);
	mcd[n]=0;
	for (int i=n-1; i>=0; i--) mcd[i]=mcd[i+1]+S[i];
	
	for (int i=0; i<n; i++) if ((S[0]*A)/(tong-mcd[n-i])>=B)
	{
		cout<<i;
		return 0;
	}
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: