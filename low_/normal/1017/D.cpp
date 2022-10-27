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

int QueryAns[5005][105];
int n, m, q;
int W[105];
int cnt[5005];

vector <int> xoreq[105];

int cvBin(string S)
{
	int ret=0;
	for (int i=S.size()-1; i>-1; i--) ret=ret*2+S[i]-'0';
//	cerr<<S<<" "<<ret<<"-\n";
	return ret;
}

void brute(int u, int t, int bin) //t- Wu number when xor, bin- current binary term
{
	if (t>102) return;
	if (u<0) 
	{
		xoreq[t].push_back(bin);
		return;
	}
	
	brute(u-1, t+W[u], bin*2);
	brute(u-1, t, bin*2+1);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<5005; i++) cnt[i]=0;
	cin>>n>>m>>q;
	for (int i=0; i<n; i++) cin>>W[i];
	
	string temp;
	int t1, t2;
	for (int i=0; i<m; i++)
	{
		cin>>temp;
		cnt[cvBin(temp)]++;
	}
	
//	for (int i=0; i<10; i++) cerr<<cnt[i]<<'\n';
	
	brute(n-1, 0, 0);
//	for (int i=0; i<105; i++)
//	{
//		cerr<<xoreq[i].size()<<": ";
//		for (int j: xoreq[i]) cerr<<j<<' ';
//		cerr<<'\n';
//	}
	for (int i=0; i<5000; i++) for (int j=0; j<105; j++)
	{
		if (j>0) QueryAns[i][j]=QueryAns[i][j-1];
		for (int x: xoreq[j]) QueryAns[i][j]+=cnt[(i^x)];
	}
	
	while (q--)
	{
		cin>>temp>>t2;
	//	cerr<<cvBin(temp)<<'\n';
		cout<<QueryAns[cvBin(temp)][t2]<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: