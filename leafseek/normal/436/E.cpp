#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=300000+5,Inf=(1LL<<60)-1;
struct PolicyDecision
{
	int idx;
	int val;
	inline bool operator < (const PolicyDecision& other) const
	{
		if(val==other.val)
			return (idx>other.idx);
		return (val>other.val);
	}
};
PolicyDecision Error;
inline void SculptError(void)
	{Error.val=Inf;}
priority_queue<PolicyDecision> Ichi,Bine;
PolicyDecision ichiA,ichiB,bineA,bineB;
int a[MaxN],b[MaxN];
char stat[MaxN];
signed main()
{
	register int n,m;
	scanf("%d%d",&n,&m);
	SculptError();
	Ichi.push(Error),Bine.push(Error);
	Ichi.push(Error),Bine.push(Error);
	rep(i,1,n)
	{
		scanf("%d%d",&a[i],&b[i]);
		stat[i]='0';
		Ichi.push((PolicyDecision){i,a[i]});
		Bine.push((PolicyDecision){i,b[i]});
	}
	register int Sum=0;
	while(m--)
	{
		do{ichiA=Ichi.top(),Ichi.pop();}while(!(ichiA.idx==0||stat[ichiA.idx]!='2'));
		do{ichiB=Ichi.top(),Ichi.pop();}while(!(ichiB.idx==0||stat[ichiB.idx]!='2'));
		do{bineA=Bine.top(),Bine.pop();}while(!(bineA.idx==0||stat[bineA.idx]=='0'));
		do{bineB=Bine.top(),Bine.pop();}while(!(bineB.idx==0||stat[bineB.idx]=='0'));
		if(!(m==0)&&bineA.val!=Inf&&(bineA.val<=(ichiA.val+ichiB.val)))
		{
			stat[bineA.idx]='1',Sum+=a[bineA.idx];
			Ichi.push((PolicyDecision){bineA.idx,b[bineA.idx]-a[bineA.idx]});
			if(ichiA.idx!=bineA.idx) Ichi.push(ichiA);
			if(ichiB.idx!=bineA.idx) Ichi.push(ichiB);
			Bine.push(bineB);
		}
		else
		{
			if(stat[ichiA.idx]=='0')
				stat[ichiA.idx]='1',Sum+=a[ichiA.idx],
					Ichi.push((PolicyDecision){ichiA.idx,b[ichiA.idx]-a[ichiA.idx]});
			else if(stat[ichiA.idx]=='1')
				stat[ichiA.idx]='2',Sum+=(b[ichiA.idx]-a[ichiA.idx]);
			Ichi.push(ichiB);
			Bine.push(bineA),Bine.push(bineB);
		}
	}
	printf("%lld\n",Sum);
	printf("%s\n",stat+1);
	return 0;
}