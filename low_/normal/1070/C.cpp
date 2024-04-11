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
#define mn 1000005
#define FLN "test"

//***** FAST I/O *****
int getint()
{
	int ret=0; char c=getchar();
	while ((c<48 || c>57) && c!=45) c=getchar();
	int si=1;
	if (c==45)
	{
		si=-1;
		c=getchar();
	}
	while (c>47 && c<58)
	{
		ret=ret*10+c-48;
		c=getchar();
	}
	return ret*si;
}

string getstr() //get string without spaces and endl
{
	string ret=""; char c;
	while (c<33 || c>126) c=getchar();
	while (c>32 && c<127)
	{
		ret+=c;
		c=getchar();
	}
	return ret;
}
//***** FAST I/O *****

//***** Number mapping
vector <int> PP={-inf};
void P_map()
{
	sort(PP.begin(), PP.end());
	
	vector <int> temp={PP[0]};
	for (int i=1; i<PP.size(); i++) if (PP[i]!=PP[i-1]) temp.push_back(PP[i]);
	PP=temp;
}

int in_PP(int u, int l, int r)
{
	if (u<PP[l] || u>PP[r]) return -1;
	if (l==r) return l;
	
	int mid=(l+r)/2;
	if (u>PP[mid]) return in_PP(u, mid+1, r);
	else return in_PP(u, l, mid);
}
//////// Number mapping

//****** Binary_Indexed Tree
class  BI_tree{
private:
	int BIT[200005];
public:
	BI_tree()
	{
		for (int i=0; i<200005; i++) BIT[i]=0;
	}
	
	void update(int ind, int val)
	{
//		cerr<<"UPD"<<' '<<ind<<' '<<val<<'\n';
		int i=ind;
		while (i<=200000)
		{
			BIT[i]+=val;
			i+=(i&(-i));
		}
	}
	
	int get(int ind)
	{
//		cerr<<"GET "<<ind<<"\n";
		int i=ind, sum=0;
		while (i>0)
		{
			sum+=BIT[i];
			i-=(i&(-i));
		}
		return sum;
	}
};
//////// Binary_Indexed Tree

vector <int> L[mn], R[mn];
pair <int, int> pii[mn];
int n, k, m;

BI_tree BT_count, BT_sum;
int mcd[mn];

signed main()
{
//	freopen(FLN".inp", "r", stdin);
//	freopen(FLN".out", "w", stdout);
	
	//INPUT
	n=getint(); k=getint(); m=getint();
	int l, r, c, p;
	for (int i=1; i<=m; i++)
	{
		l=getint(); r=getint(); c=getint(); p=getint();
		
		L[l].push_back(i);
		R[r].push_back(i);
		
		pii[i]={c, p};
		PP.push_back(p);
	}
	
	//PRE-PROCESS
	P_map();
	
	//PROCESS
	int ans=0;
	for (int i=1; i<=n; i++)
	{
//		cerr<<ans<<'\n';
		for (int d:L[i]) 
		{
			p=in_PP(pii[d].second, 0, PP.size()-1);
			BT_count.update(p, pii[d].first);
			BT_sum.update(p, pii[d].first*pii[d].second);
		}
		
		int l=1, r=PP.size();
		if (BT_count.get(r)<=k) ans+=BT_sum.get(r);
		else 
		{
			while (r>l)
			{
				int mid=(l+r)/2;
				
				if (BT_count.get(mid)<k) l=mid+1;
				else r=mid;
			}
			ans+=BT_sum.get(l-1);
			
			r=k-BT_count.get(l-1); //REUSING r
//			cerr<<ans<<'\n';
			ans+=r*PP[l];
		}
		
		for (int d:R[i])
		{
			p=in_PP(pii[d].second, 0, PP.size()-1);
			BT_count.update(p, -pii[d].first);
			BT_sum.update(p, -pii[d].first*pii[d].second);
		}
	}
	
	printf("%lld", ans);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_