#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define MAXQ 100000
#define MAXC 128
#define MAXN 100000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
char S[MAXN+10],T[MAXN+10],s[MAXN*2+10];
int Q,lens,lent,m,b[MAXN*2+10],arr[4][MAXN*2+10],*sa,*nsa,*rk,*nrk,n,height[MAXN*2+10],lg2[MAXN*2+10],l[MAXQ+10],r[MAXQ+10],k[MAXQ+10],x[MAXQ+10],y[MAXQ+10],ans[MAXQ+10],c[MAXN+10],d[MAXN+10],SIZEB;
vector<int>q[100+10][100];
	int mi[(1<<18)+10];
	inline void update(int i){
		mi[i]=min(mi[i<<1],mi[(i<<1)|1]);
	}
	void build(int *a,int i,int l,int r){
		if(l==r){
			mi[i]=a[l];
			return;
		}
		int mid((l+r)>>1);
		build(a,i<<1,l,mid);
		build(a,(i<<1)|1,mid+1,r);
		update(i);
	}
	int get_mi(int i,int l,int r,int ll,int rr){
		if(ll<=l&&r<=rr)
			return mi[i];
		if(ll>r||rr<l)
			return 0x7fffffff;
		int mid((l+r)>>1);
		return min(get_mi(i<<1,l,mid,ll,rr),get_mi((i<<1)|1,mid+1,r,ll,rr));
	}

void read(){
	scanf("%s%s",S,T);
	lens=strlen(S),lent=strlen(T);
	Read(Q);
	int i;
	for(i=0;i<lens;i++)
		s[i]=S[i];
	s[lens]='#';
	for(i=0;i<lent;i++)
		s[i+lens+1]=T[i];
	n=lens+lent+1;
	for(i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
    SIZEB=sqrt(lens/lg2[lens]);
}
void Get_sa(){
	int i,k;
	sa=arr[0],nsa=arr[1],rk=arr[2],nrk=arr[3];
	rk[n]=nrk[n]=-1;
	for(i=0;i<MAXC;i++)
		b[i]=0;
	for(i=0;i<n;i++)
		b[s[i]]++;
	for(i=1;i<MAXC;i++)
		b[i]+=b[i-1];
	for(i=0;i<n;i++)
		sa[--b[s[i]]]=i;
	for(rk[sa[0]]=0,i=1;i<n;i++){
		rk[sa[i]]=rk[sa[i-1]];
		if(s[sa[i]]!=s[sa[i-1]])
			rk[sa[i]]++;
	}
	for(k=1;rk[sa[n-1]]<n-1;k<<=1){
		for(i=0;i<n;i++)
			b[rk[sa[i]]]=i;
		for(i=n-1;i>=0;i--)
			if(sa[i]>=k)
				nsa[b[rk[sa[i]-k]]--]=sa[i]-k;
		for(i=n-k;i<n;i++)
			nsa[b[rk[i]]--]=i;
		for(nrk[nsa[0]]=0,i=1;i<n;i++){
			nrk[nsa[i]]=nrk[nsa[i-1]];
			if(rk[nsa[i]]!=rk[nsa[i-1]]||rk[nsa[i]+k]!=rk[nsa[i-1]+k])
				nrk[nsa[i]]++;
		}
		swap(rk,nrk);
		swap(sa,nsa);
	}
}
void Get_height(){
	int i,j,k=0;
	for(i=0;i<n;i++)
		if(!rk[i])
			height[rk[i]]=0;
		else{
			if(k)
				k--;
			for(j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
			height[rk[i]]=k;
		}
}

	int st[MAXN*2+10][19],Log;
	inline void prepare(int *a,int bg,int ed){
		for(Log=1;(1<<Log)<=ed-bg+1;Log++);
		Log--;
		int i,j;
		for(i=bg;i<=ed;i++)
			*st[i]=a[i];
		for(j=1;j<=Log;j++)
			for(i=bg;i+(1<<j)-1<=n;i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	inline int Get_mi(int l,int r){
		int t=lg2[r-l+1];
		return min(st[l][t],st[r-(1<<t)+1][t]);
	}

inline int Get_LCP(int i,int j){
	if(i>j)
		swap(i,j);
	return Get_mi(i+1,j);
}
inline int cmp(int i,int j){
	bool flag(0);
	if(i>j){
		swap(i,j);
		flag=1;
	}
	if(lent>j-i){
		int t=Get_LCP(rk[lens+1],rk[i]),t2,t3;
		if(i+t<j)
			return (S[i+t]>T[t])^flag;
		else
			t=j-i;
		t2=Get_LCP(rk[t+1+lens],rk[1+lens]);
		if(t+t2!=lent)
			return (T[t+t2]<T[t2])^flag;
		t3=Get_LCP(rk[t2+1+lens],rk[i]);
		if(t2+t3!=lent)
			return (S[i+t3]<T[t2+t3])^flag;
		return !flag;
	}
	else{
		int t=Get_LCP(rk[lens+1],rk[i]),t2,t3;
		if(t<lent)
			return (S[i+t]>T[t])^flag;
		t2=Get_LCP(rk[i],rk[i+lent]);
		if(i+lent+t2<j)
			return (S[i+t2]<S[i+lent+t2])^flag;
		else
			t2=j-lent-i;
		t3=Get_LCP(rk[i+t2],rk[lens+1]);
		if(t3<lent)
			return (S[i+t2+t3]<T[t3])^flag;
		return !flag;
	}
}
void solve(){
	Get_sa();
	Get_height();
	prepare(height,0,n-1);
	int i,j;
	for(i=0;i<=lens;i++)
		d[i]=i;
	sort(d,d+lens+1,cmp);
	for(i=0;i<=lens;i++)
		b[d[i]]=i;
	prepare(b,0,lens);
	for(i=1;i<=Q;i++){
		ans[i]=0x7fffffff;
		Read(l[i]),Read(r[i]),Read(k[i]),Read(x[i]),Read(y[i]);
		if(k[i]>SIZEB){
			int tl=l[i]/k[i],tr=(r[i]+k[i]-1)/k[i];
			for(j=tl;j<=tr;j++){
				int tx=j*k[i]+x[i],ty=j*k[i]+y[i];
				if(tx<l[i])
					tx=l[i];
				if(ty>r[i])
					ty=r[i];
				if(tx>ty)
					continue;
				ans[i]=min(ans[i],Get_mi(tx,ty));
			}
		}
		else
			for(j=x[i];j<=y[i];j++)
				q[k[i]][j].push_back(i);
	}
	for(i=1;i<=SIZEB;i++)
		for(j=0;j<i;j++){
			if(q[i][j].empty())
				continue;
			int cnt=0,tl,tr,x;
			for(x=j;x<=lens;x+=i)
				c[cnt++]=b[x];
			build(c,1,0,cnt-1);
			for(auto x:q[i][j]){
				tl=l[x]/i+(l[x]%i>j);
				tr=r[x]/i-(r[x]%i<j);
				if(tl>tr)
					continue;
				ans[x]=min(ans[x],get_mi(1,0,cnt-1,tl,tr));
			}
		}
}
void print(){
	int i;
	for(i=1;i<=Q;i++)
		printf("%d ",ans[i]<=lens?d[ans[i]]:-1);
}
int main()
{
	read();
	solve();
	print();
}