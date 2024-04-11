//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
using namespace std;

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

int ret,cnt,l1,r1,n,K,mn,pre[100005],suc[100005],lg[100005],st[18][100005],Tag[20000000],Ans[20000000],Lson[20000000],Rson[20000000],mid,k,l,r,q,val,root;

int ST_query(int l,int r)
{
	int tp=lg[r-l+1];
	//cout<<"?!?!?!?!?!?!"<<l<<" "<<r<<" "<<min(st[tp][l],st[tp][r-(1<<tp)+1])<<endl;
	return min(st[tp][l],st[tp][r-(1<<tp)+1]);
}

int Query(int l,int r)
{
	l1=(l-1)/n+1,r1=(r-1)/n+1;
	//cout<<l<<" "<<r<<" "<<mn<<" nmsl"<<endl;
	if (r-l+1>=n) return mn;else
	if (l1==r1)
	{
		return ST_query((l-1)%n+1,(r-1)%n+1);
	} else
	return min(suc[(l-1)%n+1],pre[(r-1)%n+1]);
}
	

void push_down(int k,int l,int r)
{
	//cout<<"Push_down "<<l<<" "<<r<<" "<<Tag[k]<<endl;
	if (!Lson[k]) Lson[k]=++cnt,Ans[Lson[k]]=Query(l,l+(r-l)/2),Tag[Lson[k]]=-1;
	if (!Rson[k]) Rson[k]=++cnt,Ans[Rson[k]]=Query(l+(r-l)/2+1,r),Tag[Rson[k]]=-1;
	//cout<<"PU "<<Lson[k]<<" "<<Rson[k]<<" "<<Ans[Lson[k]]<<" "<<Ans[Rson[k]]<<endl;
	if (Tag[k]==-1) return;
	Ans[Lson[k]]=Tag[k],Tag[Lson[k]]=Tag[k];
	Ans[Rson[k]]=Tag[k],Tag[Rson[k]]=Tag[k];
	Tag[k]=-1;
}

void push_up(int k)
{
	Ans[k]=min(Ans[Lson[k]],Ans[Rson[k]]);
}

void update(int &k,int l,int r,int l1,int r1,int val)
{
	if (!k) 
	{
	    k=++cnt;
	    Ans[k]=Query(l,r);
	    Tag[k]=-1;
	}
	if (l>=l1&&r<=r1) 
	{
		Ans[k]=val;
		Tag[k]=val;
		return;
	}	
	push_down(k,l,r);
	int mid=l+(r-l)/2;
	if (l1<=mid) update(Lson[k],l,mid,l1,r1,val);
	if (r1>mid) update(Rson[k],mid+1,r,l1,r1,val);
	push_up(k);
	//cout<<k<<" "<<l<<" "<<r<<" "<<Ans[k]<<endl;
}

int query(int &k,int l,int r,int l1,int r1)
{
	if (!k)
	{
		k=++cnt;
		Ans[k]=Query(l,r);
		Tag[k]=-1;
	}
	//cout<<l<<" "<<r<<" "<<Ans[k]<<" "<<ret<<endl;
	if (l>=l1&&r<=r1) return Ans[k];
	push_down(k,l,r);
	int mid=l+(r-l)/2,ret=INT_MAX;
	if (l1<=mid) ret=min(ret,query(Lson[k],l,mid,l1,r1));
	if (r1>mid) ret=min(ret,query(Rson[k],mid+1,r,l1,r1));
	push_up(k);
	return ret;
}

signed main()
{
	n=read(),K=read();mn=INT_MAX;
	for (int i=1;i<=n;i++) st[0][i]=read(),mn=min(mn,st[0][i]);
	lg[1]=0;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;(1<<i)<=n;i++)
	{
	  for (int j=1;j+(1<<i)-1<=n;j++)
	    st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	
	pre[1]=st[0][1];for(int i=2;i<=n;i++)pre[i]=min(pre[i-1],st[0][i]);
	suc[n]=st[0][n];for(int i=n-1;i>=1;i--)suc[i]=min(suc[i+1],st[0][i]);
	//cout<<"nmsl"<<endl;
	q=read();
	for (int i=1;i<=q;i++)
	{
		k=read(),l=read(),r=read();
		if (k==1)
		{
			val=read();
			update(root,1,n*K,l,r,val);
		} else writeln(query(root,1,n*K,l,r));
	}
	//cout<<"???"<<Query(1,2)<<" "<<st[1][1]<<endl;
	return 0;
}
/*
50 10
54 34 41 84 36 45 24 83 90 31 19 77 16 4 85 87 83 4 61 60 60 2 66 92 83 27 44 50 53 85 18 50 82 12 39 19 15 52 64 2 26 73 97 1 53 38 60 46 51 51
50
2 379 498
2 262 303
2 342 368
1 187 426 46
2 90 451
2 88 107
1 187 430 22
2 163 471
2 213 349
1 211 271 98
2 202 344
2 101 398
2 352 353
1 189 343 26
2 20 36
1 361 375 20
2 26 416
2 186 414
2 218 455
*/