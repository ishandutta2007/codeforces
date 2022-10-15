//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 10005
using namespace std;
long long n,lw111;
vector<pair<long long,long long> >ANS;
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int sum[N],lz[N],lson[N],rson[N],cnt;

void pushup(int k)
{
	sum[k]=sum[lson[k]]+sum[rson[k]];
}

void pushdown(int k,int l,int r)
{
	if (lz[k]==-1) return;
	if (!lson[k]) lson[k]=++cnt;
	if (!rson[k]) rson[k]=++cnt;
	sum[lson[k]]=(l+(r-l)/2-l+1)*lz[k];
	sum[rson[k]]=(r-(l+(r-l)/2+1)+1)*lz[k];
	lz[lson[k]]=lz[k];
	lz[rson[k]]=lz[k];
	lz[k]=-1;
}

void update(int &rt,int l,int r,int l1,int r1,int val)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
	if (l>r) return;
	if (!rt) rt=++cnt;
	if (l>=l1&&r<=r1)
	{
		sum[rt]=(r-l+1)*val;
		lz[rt]=val;
		return;
	}
	pushdown(rt,l,r);
	if (l1<=l+(r-l)/2) update(lson[rt],l,l+(r-l)/2,l1,r1,val);
	if (r1>l+(r-l)/2) update(rson[rt],l+(r-l)/2+1,r,l1,r1,val);
	pushup(rt);
}


long long lower(long long x){
	long long ANS=1;
	while(ANS<x) ANS<<=1;
	return ANS>>1;
}
void calc(long long x){
	long long p,q,fl;
	for(long long i=1;i<lw111;i<<=1)
		for(long long j=0;j<lw111;j+=i<<1)
			for(long long k=0;k<i;k++){
				p=j+k,q=j+k+i,fl=(p>n)||(q>n);
				if(!fl) !x?ANS.push_back((pair<long long,long long>){p+1,q+1}):ANS.push_back((pair<long long,long long>){n-p,n-q});
			}
}
signed main(){
	n=read(),lw111=lower(n);
	calc(0),calc(1);
	writeln(ANS.size()),puts("");
	for(long long i=0;i<ANS.size();i++)cout<<ANS[i].first<<" "<<ANS[i].second<<endl;
	return 0;
}