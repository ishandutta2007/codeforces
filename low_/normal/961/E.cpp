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
#define mn 200005
#define FLN "test"

int n;

class segment_tree{
private:
	int ST[mn*4];
	void UPD(int id, int l, int r, int u, int v)
	{
		if (u>r||v<l) return;
		if (u<=l && r<=v) 
		{
			ST[id]++;
			return;
		}
		
		int mid=(l+r)/2;
		UPD(id*2, l, mid, u, v); UPD(id*2+1, mid+1, r, u, v);
	}
	
	int GET(int id, int l, int r, int u)
	{
		if (u<l || u>r) return 0;
		if (l==r) return ST[id];
		
		int mid=(l+r)/2;
		int ret=ST[id]+GET(2*id, l, mid, u)+GET(2*id+1, mid+1, r, u);
//		cerr<<id<<' '<<l<<' '<<r<<' '<<ret<<"\n";
		return ret;
	}
public:
	void update(int u, int v)
	{
		UPD(1, 1, n, u, v);
	}
	
	int get(int u)
	{
		return GET(1, 1, n, u);
	}
	
	segment_tree()
	{
		for (int i=0; i<4*mn; i++) ST[i]=0;
	}
};

segment_tree st;
int A[mn];
vector <pair <int, int> > Pii;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	pair <int, int> t;
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		t.first=min(A[i], i);
		t.second=i;
		Pii.push_back(t);
	}
	
	sort(Pii.begin(), Pii.end());
	
	int ans=0, ptr=0;
	for (int i=1; i<=n; i++)
	{
		st.update(1, min(A[i], n));
		if (A[i]>=i) ans--;
		while (ptr<n)
		{
			if (Pii[ptr].first>i) break;
			ans+=st.get(Pii[ptr].second);
//			cerr<<ptr<<" "<<i<<" "<<st.get(Pii[ptr].second)<<" "<<Pii[ptr].second<<"\n";
			ptr++;
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: