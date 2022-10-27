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

int t, a, b;
int POW10[20];
vector <int> V;

int CNP(int u, int l, int r)
{
//	cerr<<u<<" "<<l<<' '<<r<<'\n';
	if (u<=V[l]) return l-1;
	else if (u>V[r]) return r;
	
	int mid=(l+r)/2+1;
	if (u<V[mid]) return CNP(u, l, mid-1);
	else return CNP(u, mid, r); 
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	POW10[0]=1;
	for (int i=1; i<19; i++) POW10[i]=POW10[i-1]*10;
	
	for (int i=0; i<18; i++) for (int j=i+1; j<18; j++) for (int k=j+1; k<18; k++) for (int I1=0; I1<10; I1++) for (int J1=0; J1<10; J1++) for (int K1=0; K1<10; K1++) V.push_back(I1*POW10[i]+J1*POW10[j]+K1*POW10[k]);
	

	
	sort(V.begin(), V.end());
	vector <int> Vnew;
	Vnew.clear();
	V.push_back(POW10[18]);
	for (int i=0; i<V.size()-1; i++) if (V[i]!=V[i+1]) Vnew.push_back(V[i]);
	V=Vnew;
	V.push_back(POW10[18]);
//	for (int i:V) cout<<i<<'\n';
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		
		int x=CNP(b+1, 0, V.size()-1), y=CNP(a, 0, V.size()-1);
//		cerr<<x<<" "<<y<<'\n';
		cout<<x-y<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: