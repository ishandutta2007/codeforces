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
#define inf 1000000009
#define mn 100005
#define FLN "test"
#define X first 
#define Y second 
typedef pair <int, int> vec;
typedef pair <pair <int, int>, pair <int, int> > seg;

int n;
seg SG[mn];
vec VC[mn];
vector <vec> V;

int GCD(int a, int b)
{
	if (b==0) return a;
	return GCD(b, a%b);
}

int CCW(vec A, vec B, vec C)
{
	int t=(C.X-B.X)*(B.Y-A.Y)-(C.Y-B.Y)*(B.X-A.X);
	if (t==0) return 0;
	else if (t>0) return 1;
	else return -1;
}

vec cut_point(seg a, seg b)
{
//	cerr<<'-';
	if (CCW(a.X, a.Y, b.X)==CCW(a.X, a.Y, b.Y)) return {inf, inf};
	if (CCW(b.X, b.Y, a.X)==CCW(b.X, b.Y, a.Y)) return {inf, inf};
//	cerr<<"\n";
	int l=0, r=abs(GCD(b.Y.X-b.X.X, b.Y.Y-b.X.Y));
	vec v={(b.Y.X-b.X.X)/r, (b.Y.Y-b.X.Y)/r}, temp;
	while (r>l)
	{
		int mid=(l+r)/2;
		temp={b.X.X+mid*v.X, b.X.Y+mid*v.Y};
		
		if (CCW(a.X, a.Y, temp)==0) l=r=mid;
		else if (CCW(a.X, a.Y, temp)==CCW(a.X, a.Y, b.X)) l=mid+1;
		else r=mid;
	}
	temp={b.X.X+l*v.X, b.X.Y+l*v.Y};
//	if (a==SG[2] && b==SG[3]) cerr<<l<<' '<<temp.first<<' '<<temp.second<<'\n';
	
	if (CCW(a.X, a.Y, temp)==0) return temp;
	else return {inf, inf};
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//Initializing
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>SG[i].X.X>>SG[i].X.Y>>SG[i].Y.X>>SG[i].Y.Y;
	}
	int t, ans=0;
	
	for (int i=1; i<=n; i++)
	{
		t=GCD(SG[i].Y.X-SG[i].X.X, SG[i].Y.Y-SG[i].X.Y);
		ans+=abs(t)+1;
		VC[i]={(SG[i].Y.X-SG[i].X.X)/t, (SG[i].Y.Y-SG[i].X.Y)/t};
	}

	//Process
	vec temp;
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++)  
	{
		temp=cut_point(SG[i], SG[j]);
//		if (i==2 && j==3) cerr<<temp.X<<' '<<temp.Y<<"\n";
		if (temp.X!=inf) V.push_back(temp);
	}
	
	sort(V.begin(), V.end());
	V.push_back({inf, inf});
	t=1;
	for (int i=1; i<V.size(); i++)
	{
//		cerr<<V[i-1].X<<' '<<V[i-1].Y<<'\n';
		if (V[i]==V[i-1]) t++;
		else
		{
			t*=2;
			ans-=(int)sqrt(t);
			t=1;
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: