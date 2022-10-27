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
#include<sstream>
#include<bitset>
#include<ctime>
using namespace std;
#define int long long
#define inf 444444444444444444
#define mn 200005
#define FLN "test"

int L[mn], R[mn], U[mn], D[mn];

int n;
string S;
int x, y, sx=0, sy=0;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>S>>x>>y;
	S="_"+S;
	L[0]=R[0]=U[0]=D[0]=0;
	for (int i=1; i<=n; i++)
	{
		L[i]=L[i-1]; R[i]=R[i-1]; D[i]=D[i-1]; U[i]=U[i-1];
		if (S[i]=='L') L[i]++, sx--;
		else if (S[i]=='R') R[i]++, sx++;
		else if (S[i]=='U') U[i]++, sy++;
		else if (S[i]=='D') D[i]++, sy--;
	}
	
	if (sx==x && sy==y)
	{
		cout<<0;
		return 0;
	}
	if ((sx+sy+x+y)%2!=0)
	{
		cout<<-1;
		return 0;
	}
	
	int s_ind=1, g_ind=n+1;
	while (g_ind>s_ind)
	{
		int len=(g_ind+s_ind)/2;
		
		bool b=0;
		for (int j=len; j<=n; j++)
		{
			int l=L[n]-L[j]+L[j-len], r=R[n]-R[j]+R[j-len], u=U[n]-U[j]+U[j-len], d=D[n]-D[j]+D[j-len];
			
			int curx=r-l, cury=u-d;
//			cerr<<j-len+1<<' '<<j<<' '<<curx<<' '<<cury<<"\n";
			if (abs(curx-x)+abs(cury-y)<=len) 
			{
				b=1;
				break;
			}
		}
		
		if (b) g_ind=len;
		else s_ind=len+1;
	}
	
	if (s_ind<=n) cout<<s_ind;
	else cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_