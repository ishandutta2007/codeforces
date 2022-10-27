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

int n;
pair <int, int> D[mn];

int setsize[mn]; // show the size of an indexed set
int ptr=1; //show the next new set
int cntsize[mn];

class segment_tree{
private:
	int ST[mn*4];
	
	void UPD(int id, int l, int r, int u, int v, int up)
	{
		if (u>r || v<l) return;
		
		if (u<=l && r<=v) 
		{
			ST[id]=up;
			return;
		}
		
		int m=(l+r)/2;
		
		UPD(2*id, l, m, u, v, up);
		UPD(2*id+1, m+1, r, u, v, up);
	}
	
	int GET(int id, int l, int r, int u)
	{
		if (u>r || u<l) return -1;
		if (l==r) return ST[id];
		
//		if (ST[id]>-1) return ST[id];
		
		int m=(l+r)/2;
		return max(ST[id], max(GET(2*id, l, m, u), GET(2*id+1, m+1, r, u)));
	}
public:
	segment_tree()
	{
		for (int i=0; i<mn*4; i++) ST[i]=-1;
	}
	
	void update(int l, int r, int u)
	{
		UPD(1, 1, n, l, r, u);
	}
	
	int get(int u)
	{
		return GET(1, 1, n, u);
	}
};

segment_tree ST;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>D[i].first;
		D[i].second=i;
		
		cntsize[i]=0;
		setsize[i]=0;
	}
	
	sort(D+1, D+n+1);
	int ovr=0;
	int setcnt=0;
	int k=0, km=0;
	
	for (int i=1; i<=n; i++)
	{
		int nxt=D[i].second;
		int lset=-1, rset=-1;
		
		if (nxt>1) lset=ST.get(nxt-1);
		if (nxt<n) rset=ST.get(nxt+1);
		
//		cerr<<D[i].first<<" "<<D[i].second<<" "<<lset<<" "<<rset<<"\n";
		
//		cerr<<i<<":\n";
//		cerr<<D[i].first<<" "<<D[i].second<<" "<<lset<<" "<<rset<<"\n";
//		for (int j=1; j<=n; j++) cerr<<ST.get(j)<<" ";
//		cerr<<"\n\n";
		

		if (lset==-1 && rset==-1)
		{
			setsize[ptr]=1;
			ST.update(nxt, nxt, ptr);
			cntsize[1]++;
			if (cntsize[1]==1) ovr++;
			ptr++;
			setcnt++;
		}
		else if (lset==-1) 
		{
			int sz1, sz2, t=rset;
			
			sz1=setsize[t];
			sz2=sz1+1;
			cntsize[sz1]--;
			if (cntsize[sz1]==0) ovr--;
			cntsize[sz2]++;
			if (cntsize[sz2]==1) ovr++;
			setsize[t]++;
			ST.update(nxt, nxt, t);
			
		}
		else if (rset==-1) 
		{
			int sz1, sz2, t=lset;
			
			sz1=setsize[t];
			sz2=sz1+1;
			cntsize[sz1]--;
			if (cntsize[sz1]==0) ovr--;
			cntsize[sz2]++;
			if (cntsize[sz2]==1) ovr++;
			setsize[t]++;
			ST.update(nxt, nxt, t);
		}
		else
		{
			int s1=lset, s2=rset;
			
			cntsize[setsize[s1]]--;
			cntsize[setsize[s2]]--;
			if (cntsize[setsize[s1]]==0) ovr--;
			if (cntsize[setsize[s2]]==0) ovr--;
			cntsize[setsize[s1]+setsize[s2]+1]++;
			
			setcnt--;
	//		cerr<<i<<" "<<setsize[s1]<<" "<<setsize[s2]<<"\n";
			ST.update(nxt-setsize[lset], nxt+setsize[rset], max(s1, s2));
			setsize[max(s1, s2)]=setsize[s1]+setsize[s2]+1;
			setsize[min(s1, s2)]=0;
			if (cntsize[setsize[max(s1, s2)]]==1) ovr++;
		}
		
		if (ovr==1) 
		{
			if (km<setcnt)
			{
				k=D[i].first+1;
				km=setcnt;
			}
			else if (km==setcnt) k=min(k, D[i].first+1);
		}
	}
	
	cout<<k;
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: