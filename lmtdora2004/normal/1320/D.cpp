#include <bits/stdc++.h>
#define yeet pair<pair<int, int>, pair<int, int> >
#define l1 first.first
#define l2 first.second
#define h2 second.first
#define lst second.second
#define int long long

using namespace std;

int n, q;
string t;
int ok=0;
int m2[200005];
int inv2[200005];
int mod=1000000007;
int binpow(int a, int b)
{
	int cac=a, ans=1;
	while(b)
	{
		if(b%2==1)
		{
			ans=(ans*cac)%mod;
		}
		cac=(cac*cac)%mod;
		b/=2;
	}
	return ans;
}

yeet it[800005];
yeet zempty={{0, 0}, {0, 0}};
yeet merge(yeet l, yeet r)
{
	if(l==zempty) return r;
	if(r==zempty) return l;
	if(l.l2==0)
	{
		return {{l.l1+r.l1, r.l2}, {r.h2, r.lst}};
	}
	if(l.lst==0)
	{
		if(r.l1%2==0)
		{
			return {{l.l1+r.l1, l.l2+r.l2}, {(l.h2+r.h2*m2[l.l2])%mod, r.l2==0?l.lst:r.lst}};
		}
		else
		{
			return {{l.l1+r.l1-1, l.l2+r.l2+1}, {(l.h2+1*m2[l.l2]+r.h2*m2[l.l2+1])%mod, r.l2==0?1:r.lst}};
		}
	}
	else
	{
		if(r.l1%2==0)
		{
			return {{l.l1+r.l1, l.l2+r.l2}, {(l.h2+r.h2*m2[l.l2])%mod, r.l2==0?l.lst:r.lst}};
		}
		else
		{
			return {{l.l1+r.l1+1, l.l2+r.l2-1}, {(l.h2-1*m2[l.l2-1]+mod*mod+r.h2*m2[l.l2-1])%mod, r.l2==0?0:r.lst}};
		}
	}
}

void build_tree(int id, int l, int r)
{
	if(l==r)
	{
		if(t[l]=='0') it[id]={{0, 1}, {0, 0}};
		else it[id]={{1, 0}, {0, 0}};
	}
	else
	{
		int mid=(l+r)/2;
		build_tree(id*2, l, mid);
		build_tree(id*2+1, mid+1, r);
		it[id]=merge(it[id*2], it[id*2+1]);
	}
}

yeet get(int id, int l, int r, int u, int v)
{
	if(l>v||r<u) return {{0, 0}, {0, 0}};
	if(l>=u&&r<=v) return it[id];
	int mid=(l+r)/2;
	//cout<<id<<" "<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
	return merge(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void print(yeet dit)
{
	cout<<dit.l1<<" "<<dit.l2<<" "<<dit.h2<<" "<<dit.lst<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	m2[0]=1;
	for(int i=1; i<=200002; i++)
	{
		m2[i]=(m2[i-1]*2)%mod;
	}
	inv2[200002]=binpow(m2[200002], mod-2);
	for(int i=200001; i>=0; i--)
	{
		inv2[i]=(inv2[i+1]*2)%mod;
	}
	cin>>n>>t;
	t='!'+t;
	build_tree(1, 1, n);
	// print(get(1, 1, n, 1, 3));
	// return 0;
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		int ll1, ll2, len;
		cin>>ll1>>ll2>>len;
		// print(get(1, 1, n, ll1, ll1+len-1));
		// print(get(1, 1, n, ll2, ll2+len-1));
		if(get(1, 1, n, ll1, ll1+len-1)==get(1, 1, n, ll2, ll2+len-1)) cout<<"Yes\n";
		else cout<<"No\n";
	}

}