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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

int n, t;
int A[mn*2];
int mcd[mn*2], Q[mn*2];

//VALUE MAPPING
set <int> vals;
map <int, int> MAP;

//SEGMENT-TREE
class segment_tree{
private:
	int st[mn*16];
	
	void UPD(int id, int l, int r, int u)
	{
		if (u<l || u>r) return;
		if (l==r)
		{
			st[id]++;
			return;
		}
		
		int mid=(l+r)/2;
		UPD(2*id, l, mid, u);
		UPD(2*id+1, mid+1, r, u);
		
		st[id]=st[2*id]+st[2*id+1];
	}
	
	int GET(int id, int l, int r, int u, int v)
	{
		if (u>r || v<l) return 0;
		if (u<=l && r<=v) return st[id];
		
		int mid=(l+r)/2;
		return GET(2*id, l, mid, u, v)+GET(2*id+1, mid+1, r, u, v);
	}
	
public:
	void update(int Index_)
	{
		UPD(1, 1, 2*n+2, Index_);
	}
	
	int get(int L, int R)
	{
		return GET(1, 1, 2*n+2, L, R);
	}
	
	segment_tree()
	{
		for (int i=0; i<mn*16; i++) st[i]=0;
	}
};

segment_tree ST;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>t;
	for (int i=1; i<=n; i++) cin>>A[i];
	mcd[0]=Q[0]=0;
	for (int i=1; i<=n; i++) 
	{
		mcd[i]=mcd[i-1]+A[i];
		Q[i]=mcd[i]-t;
	}
	
	//VALUE MAPPING
	for (int i=0; i<=n; i++) vals.insert(mcd[i]), vals.insert(Q[i]);
	int ptr=1;
	for (int j:vals) 
	{
		MAP[j]=ptr;
		ptr++;
	}
	for (int i=0; i<=n; i++) mcd[i]=MAP[mcd[i]], Q[i]=MAP[Q[i]];
	
//	//DEBUG
//	for (int i=0; i<=n; i++) cerr<<mcd[i]<<" ";
//	cerr<<'\n';
//	for (int i=0; i<=n; i++) cerr<<Q[i]<<" ";
	
	//FINDING ANSWERS USING SEG-TREE
	int ans=0;
	for (int i=0; i<=n; i++)
	{
		ans+=ST.get(Q[i]+1, 2*n+2);
		ST.update(mcd[i]);
	}
	
	//OUTPUT
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_