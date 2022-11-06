#include<cstdio>
#define int long long
const int N=2e5+5,mod=1e9+7;
int n,ans;
int sumj,sume,cntj,cnte;
int a[N];
int v[N<<1],first[N],next[N<<1];
int size[N],max_size[N];
bool book[N];
void calc_size(int now,int father)
{
  size[now]=1;
  for(int go=first[now];go;go=next[go])
    if(!book[v[go]]&&v[go]!=father)
      calc_size(v[go],now),size[now]+=size[v[go]];
  return;
}
int get_center(int now,int root)
{
  int res=0,d;
  max_size[now]=size[root]-size[now];
  for(int go=first[now];go;go=next[go])
    if(!book[v[go]]&&size[v[go]]<size[now])
    {
      d=get_center(v[go],root);
      if(!res||max_size[res]>max_size[d])
        res=d;
      if(size[v[go]]>max_size[now])
        max_size[now]=size[v[go]];
    }
  if(!res||max_size[res]>max_size[now])
    res=now;
  return res;
}
void enumerate(int now,int father,int wi,int deep)
{
	wi=(wi+(a[now]*deep%mod+mod)%mod)%mod;
	if(deep==-1)
		(ans+=(mod-(sume+wi*cnte%mod)%mod)%mod)%=mod;
	else
		(ans+=(sumj+wi*cntj%mod)%mod)%=mod;
	deep=-deep;
	for(int go=first[now];go;go=next[go])
		if(!book[v[go]]&&v[go]!=father)
			enumerate(v[go],now,wi,deep);
	return;
}
void insert(int now,int father,int wi,int deep)
{
	wi=(wi+(a[now]*deep%mod+mod)%mod)%mod;
	if(deep==-1)
		(sume+=wi)%=mod,cnte++;
	else
		(sumj+=wi)%=mod,cntj++;
	deep=-deep;
	for(int go=first[now];go;go=next[go])
		if(!book[v[go]]&&v[go]!=father)
			insert(v[go],now,wi,deep);
	return;
}
void solve(int now)
{
  int go;
  calc_size(now,0);
  now=get_center(now,now);
  book[now]=true;
  for(go=first[now];go;go=next[go])
    if(!book[v[go]])
      solve(v[go]);
  sumj=sume=cntj=cnte=0;
  sumj=a[now];cntj++;
  for(go=first[now];go;go=next[go])
    if(!book[v[go]])
    {
      enumerate(v[go],now,0,-1);
      insert(v[go],now,a[now],-1);
		}
  book[now]=false;
  return;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]=(a[i]%mod+mod)%mod;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&v[i+n-1],&v[i]);
		next[i]=first[v[i+n-1]];first[v[i+n-1]]=i;
		next[i+n-1]=first[v[i]];first[v[i]]=i+n-1;
	}
	solve(1);(ans*=2)%=mod;
	for(int i=1;i<=n;i++)
		ans=(ans+a[i])%mod;
	printf("%lld\n",ans);
	return 0;
}