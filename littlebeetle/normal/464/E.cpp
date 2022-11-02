#include<cstdio>
const int N=400002,K=30,M=1000000007,C=131,Len=100030;
const long long P=2005032220040413ll;
typedef long long ll;
int n,m,S,T,D,i,j,k,a,b,c;
int h[N],t[N],v[N],w[N],rt[N],p[N],o,uzi,pre[N],Cnt[N];
int L[N*K],R[N*K],val[N*K],rt0,rt1,cnt,dis[N];
int newrt;
int bas[N],Hs1[N*K];
ll bae[N],Hs2[N*K];
bool usd[N];
void add(int a,int b,int c){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
	w[k]=c;
}
char ch;
void read(int &a){
	a=0;
	while((ch=getchar())<48);
	while(ch>47)
		a=a*10+ch-48,ch=getchar();
}
void init(){
	scanf("%d%d",&n,&m);
	while(m--){
		read(a);
		read(b);
		read(c);
		add(a,b,c);
		add(b,a,c);
	}
	scanf("%d%d",&S,&T);
	bas[0]=1;bae[0]=1;
	for(i=1;i<N;i++){
		bas[i]=bas[i-1]*2%M;
		bae[i]=bae[i-1]*C%P;
	}
}
void Pushup(int rt){
	val[rt]=val[L[rt]]+val[R[rt]];
	Hs1[rt]=(Hs1[L[rt]]+Hs1[R[rt]])%M;
	Hs2[rt]=Hs2[L[rt]]+Hs2[R[rt]];
}
void Build(int &rt,int l,int r,int va){
	rt=++cnt;
	if(l==r){
		val[rt]=va;
		Hs1[rt]=bas[l]*va;
		Hs2[rt]=bae[l]*va;
		return;
	}
	int mid=l+r>>1;
	Build(L[rt],l,mid,va);
	Build(R[rt],mid+1,r,va);
	Pushup(rt);
}
bool Equal(int &x,int &y){
	return Hs1[x]==Hs1[y]&&val[x]==val[y]&&Hs2[x]==Hs2[y];
}
bool cmp(int rtl,int rtr){
	int l=0,r=Len,mid;
	while(l<r){
		if(rtl==rtr)return 0;
		mid=l+r>>1;
		if(Equal(R[rtl],R[rtr])){
			rtl=L[rtl];
			rtr=L[rtr];
			r=mid;
		}
		else{
			rtl=R[rtl];
			rtr=R[rtr];
			l=mid+1;
		}
	}
	return val[rtl]>val[rtr];
}
int Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return val[rt];
	int mid=l+r>>1,s=0;
	if(x<=mid)
		s+=Query(L[rt],l,mid,x,y);
	if(y>mid)
		s+=Query(R[rt],mid+1,r,x,y);
	return s;
}
int Search(int odrt,int w){
	int l=w,r=Len,mid;
	while(l<r){
		mid=l+r>>1;
		if(Query(odrt,0,Len,w,mid)<=(mid-w))
			r=mid;
		else
			l=mid+1;
	}
	return r;
}
void Dirt(int pre,int &rt,int l,int r,int x){
	rt=++cnt;
	L[rt]=L[pre];
	R[rt]=R[pre];
	if(l==r){
		val[rt]=1;
		Hs1[rt]=bas[l];
		Hs2[rt]=bae[l];
		return;		
	}
	int mid=l+r>>1;
	if(x<=mid)
		Dirt(L[pre],L[rt],l,mid,x);
	else
		Dirt(R[pre],R[rt],mid+1,r,x);
	Pushup(rt);
}
void Cover0(int pre,int &rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		rt=pre;
		return;
	}
	int RT=++cnt;
	L[RT]=L[rt];
	R[RT]=R[rt];
	rt=RT;
	int mid=l+r>>1;
	if(x<=mid)
		Cover0(L[pre],L[rt],l,mid,x,y);
	if(y>mid)
		Cover0(R[pre],R[rt],mid+1,r,x,y);
	Pushup(rt);
}
void Add(int &newrt,int odrt,int w){
	int loc=Search(odrt,w);
	Dirt(odrt,newrt,0,Len,loc);
	if(w==loc)
		return;
	Cover0(rt0,newrt,0,Len,w,loc-1);
	return ;
}
void Pri(int x){
	
	if(x!=S)
	Pri(pre[x]);
	printf("%d ",x);
}
void Out(){
	if(Equal(rt[T],rt1))
		printf("-1");
	else
	printf("%d\n%d\n",Hs1[rt[T]],Cnt[T]+1),
	Pri(T);
}
void Dijkstra(){
	Build(rt0,0,Len,0);
	Build(rt1,0,Len,1);
	for(D=1;D<n+2;D<<=1);
	for(i=0;i<D;i++){
		rt[i]=rt1;
		dis[i]=1<<30;
		p[i+D]=i;
	}
	rt[S]=rt0;
	dis[S]=0;
	for(k=D-1;k;k--)
		if(rt[p[k<<1]]==rt[p[k<<1|1]])
			p[k]=p[k<<1];
		else
			p[k]=cmp(rt[p[k<<1]],rt[p[k<<1|1]])==0?p[k<<1]:p[k<<1|1];
	for(o=1;o<=n;o++){
		i=p[1];
		if(Equal(rt[i],rt1)||i==T){
			Out();
			return;
		}
		for(j=h[i];j;j=t[j])
			if(!usd[v[j]]){
				Add(newrt,rt[i],w[j]);
				if(cmp(rt[v[j]],newrt)){
					rt[v[j]]=newrt;
					pre[v[j]]=i;
					Cnt[v[j]]=Cnt[i]+1;
					for(k=v[j]+D>>1;k;k>>=1)
						if(rt[p[k<<1]]==rt[p[k<<1|1]])
							p[k]=p[k<<1];
						else
							p[k]=cmp(rt[p[k<<1]],rt[p[k<<1|1]])==0?p[k<<1]:p[k<<1|1];
				}
			}
		usd[i]=1;
		rt[i]=rt1;
		for(k=i+D>>1;k;k>>=1)
			if(rt[p[k<<1]]==rt[p[k<<1|1]])
				p[k]=p[k<<1];
			else
				p[k]=cmp(rt[p[k<<1]],rt[p[k<<1|1]])==0?p[k<<1]:p[k<<1|1];
	}
}
int main(){
	init();
	Dijkstra();
	//while(1);
	return 0;	
}