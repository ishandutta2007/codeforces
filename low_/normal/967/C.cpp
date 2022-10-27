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

int n, m, cl, ce, v;
int L[mn], E[mn];
int Q, X1, X2, Y1, Y2;

int CNP_L(int u, int l, int r)
{
	if (u<=L[l]) return l-1;
	if (u>L[r]) return r;
	
	int m=(l+r)/2;
	
	if (u>=L[m]) return CNP_L(u, m+1, r);
	else return CNP_L(u, l, m);
}

int CNP_E(int u, int l, int r)
{
	if (u<=E[l]) return l-1;
	if (u>E[r]) return r;
	
	int m=(l+r)/2;
	
	if (u>=E[m]) return CNP_E(u, m+1, r);
	else return CNP_E(u, l, m);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>cl>>ce>>v;
	for (int i=1; i<=cl; i++) cin>>L[i];
	for (int i=1; i<=ce; i++) cin>>E[i];
	
	sort(L+1, L+cl+1);
	sort(E+1, E+ce+1);
	
	cin>>Q;
	while (Q--)
	{
		cin>>X1>>Y1>>X2>>Y2;
		
		if (Y1>Y2)
		{
			Y1=Y1+Y2;
			Y2=Y1-Y2;
			Y1=Y1-Y2;
			
			X1=X1+X2;
			X2=X1-X2;
			X1=X1-X2;
		}
		
		int ans=inf;
		if (X2==X1) ans=Y2-Y1;
		else if (ce>0)
		{
			//find nearest elevator
			int ptr=CNP_E(Y2, 1, ce);
			int kc=abs(X2-X1);
			kc=kc/v+(kc%v>0);
			
			cerr<<kc<<"\n";
			
			if (ptr==0) ans=2*E[1]-Y2-Y1+kc;
			else if (E[ptr]>=Y1) ans=(Y2-Y1)+kc;
			else if (ptr==ce) ans=Y2+Y1-2*E[ptr]+kc;
			else ans=min(Y2+Y1-2*E[ptr], 2*E[ptr+1]-Y2-Y1)+kc;
			
			if (cl>0)
			{
				kc=abs(X2-X1);
				int ptr2=CNP_L(Y2, 1, cl);
			
				if (ptr2==0) ans=min(ans, 2*L[1]-Y2-Y1+abs(X2-X1));
				else if (L[ptr2]>=Y1) ans=min(ans, (Y2-Y1)+abs(X2-X1));
				else if (ptr2==cl) ans=min(ans, Y2+Y1-2*L[ptr2]+abs(X2-X1)); 
				else ans=min(ans, min(Y2+Y1-2*L[ptr2], 2*L[ptr2+1]-Y2-Y1)+abs(X2-X1));
			}
		}
		else //find nearest stairs
		{
			int ptr2=CNP_L(Y2, 1, cl);
			
			if (ptr2==0) ans=2*L[1]-Y2-Y1+abs(X2-X1);
			else if (L[ptr2]>=Y1) ans=(Y2-Y1)+abs(X2-X1);
			else if (ptr2==cl) ans=Y2+Y1-2*L[ptr2]+abs(X2-X1); 
			else ans=min(Y2+Y1-2*L[ptr2], 2*L[ptr2+1]-Y2-Y1)+abs(X2-X1);
		}
		
		cout<<ans<<"\n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: