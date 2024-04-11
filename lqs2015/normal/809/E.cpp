#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,a[222222],x,y,id[222222],mu[222222],phi[222222],cnt,ans,prime[222222],F[222222],g[222222],inv[222222];
vector<int> gr[222222],ys[222222];
bool f[222222];
int sub[222222];
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod; 
	}
	return res;
}
bool conc[222222],used[222222];
void calsub(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<gr[i].size();j++)
	{
		int to=gr[i][j];
		if (conc[to] || to==fa) continue;
		calsub(to,i);
		sub[i]+=sub[to];
	}
}
pair<int,int> findgrav(int i,int fa,int all)
{
	pair<int,int> res=make_pair(1e9,1e9);
	int mx=0,sum=0;
	for (int j=0;j<gr[i].size();j++)
	{
		int to=gr[i][j];
		if (conc[to] || to==fa) continue;
		res=min(res,findgrav(to,i,all));
		mx=max(mx,sub[to]);
		sum+=sub[to];
	}
	mx=max(mx,all-sum);
	res=min(res,make_pair(mx,i));
	return res;
}
void dfs(int i,int fa,long long len,vector<pair<long long,long long> > &v)
{
	v.push_back(make_pair(a[i],len));
	for (int j=0;j<gr[i].size();j++)
	{
		int to=gr[i][j];
		if (conc[to] || to==fa) continue;
		dfs(to,i,len+1,v);
	} 
}
long long pairit(vector<pair<long long,long long> > &v)
{
	vector<long long> s,sf,sp;
	s.clear();sf.clear();sp.clear();
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<ys[v[i].first].size();j++)
		{
			if (!used[ys[v[i].first][j]]) 
			{
				used[ys[v[i].first][j]]=1;
				s.push_back(ys[v[i].first][j]);
				id[ys[v[i].first][j]]=(int)s.size()-1;
			}
		}
	}
	sf.resize(s.size());sp.resize(s.size());
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<ys[v[i].first].size();j++)
		{
			int to=ys[v[i].first][j];
			sf[id[to]]=(sf[id[to]]+phi[v[i].first]*v[i].second)%mod;
			sp[id[to]]=(sp[id[to]]+phi[v[i].first])%mod;
		}
	}
	long long res=0;
	for (long long i=0;i<s.size();i++)
	{
		res=(res+(F[s[i]]*sf[i]%mod)*sp[i]*2)%mod;
	}
	for (int i=0;i<s.size();i++) used[s[i]]=0;
	return res;
}
void gravity(int i)
{
	calsub(i,0);
	int pos=findgrav(i,0,sub[i]).second;
	conc[pos]=1;
	for (int j=0;j<gr[pos].size();j++)
	{
		int to=gr[pos][j];
		if (!conc[to]) gravity(to);
	}
	vector<pair<long long,long long> > v,tot;
	tot.clear();v.clear();
	tot.push_back(make_pair(a[pos],0)); 
	for (int j=0;j<gr[pos].size();j++)
	{
		int to=gr[pos][j];
		if (conc[to]) continue;
		v.clear();
		dfs(to,pos,1,v);
		ans=(ans-pairit(v))%mod;
		for (int k=0;k<v.size();k++) tot.push_back(v[k]); 
	}
	ans=(ans+pairit(tot))%mod;
	conc[pos]=0;
}
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		gr[x].push_back(y);
		gr[y].push_back(x);  
	}
	mu[1]=phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
			mu[i]=-1;phi[i]=i-1; 
		}
		for (int j=1;j<=cnt && prime[j]*i<=n;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else
			{
				mu[i*prime[j]]=-mu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	for (long long i=1;i<=n;i++) inv[i]=binpow(i,mod-2);
	for (long long i=1;i<=n;i++) g[i]=i*inv[phi[i]]%mod;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j+=i)
		{
			F[j]=(F[j]+g[i]*mu[j/i])%mod;
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		cout<<mu[i]<<" "<<phi[i]<<" "<<g[i]<<" "<<F[i]<<endl;
	}*/
	for (int i=1;i<=n;i++)
	{
		x=sqrt(i);
		for (int j=1;j<=x;j++)
		{
			if (i%j==0)
			{
				ys[i].push_back(j);
				if (i/j!=j) ys[i].push_back(i/j);  
			}
		}
	}
	gravity(1);
	printf("%lld\n",((ans*inv[n]%mod)*inv[n-1]%mod+mod)%mod);
	return 0;
}