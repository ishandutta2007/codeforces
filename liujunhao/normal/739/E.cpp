#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define MAXN 2000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
double u[MAXN+10],p[MAXN+10],ans;
int n,r[MAXN+10],a,b;
struct cmp1{
	bool operator()(int x,int y)const{
		return (1-p[x])*u[x]>(1-p[y])*u[y];
	}
};
multiset<int,cmp1>s1;
inline bool cmp(int x,int y){
	return u[x]>u[y];
}
void read(){
	Read(n),Read(a),Read(b);
	int i;
	for(i=1;i<=n;i++)
		scanf("%lf",&p[i]);
	for(i=1;i<=n;i++){
		scanf("%lf",&u[i]);
		r[i]=i;
	}
}
struct node{
	double sum,val;
	int pri,size;
	node *ch[2];
}tree[MAXN*4+10],*tcnt=tree,*root[4];
inline double Get_sum(node *p){
	return p?p->sum:0;
}
inline int Get_size(node *p){
	return p?p->size:0;
}
inline void update(node *p){
	p->sum=Get_sum(p->ch[0])+Get_sum(p->ch[1])+p->val;
	p->size=Get_size(p->ch[0])+Get_size(p->ch[1])+1;
}
inline void Rotate(node *&x,bool d){
	node *y=x->ch[!d];
	x->ch[!d]=y->ch[d];
	y->ch[d]=x;
	update(x);
	x=y;
}
inline void init(node *p){
	p->sum=p->val=p->pri=p->size=0;
	p->ch[0]=p->ch[1]=0;
}
void insert(node *&p,double val){
	if(!p){
		init(p=++tcnt);
		p->pri=(rand()<<15)+rand();
		p->val=p->sum=val;
		p->size=1;
		return;
	}
	bool d=val<=p->val;
	insert(p->ch[d],val);
	if(p->ch[d]->pri>p->pri)
		Rotate(p,!d);
	update(p);
}
inline double get_sum(node *p,int k){
	if(!p)
		return 0;
	if(k<=Get_size(p->ch[0]))
		return get_sum(p->ch[0],k);
	else if(k<=Get_size(p->ch[0])+1)
		return Get_sum(p->ch[0])+p->val;
	else
		return Get_sum(p->ch[0])+p->val+get_sum(p->ch[1],k-Get_size(p->ch[0])-1);
}
void erase(node *&p,double val){
	if(p->val==val){
		if(!p->ch[0]){
			p=p->ch[1];
			return;
		}
		else if(!p->ch[1]){
			p=p->ch[0];
			return;
		}
		bool d=p->ch[0]->pri>p->ch[1]->pri;
		Rotate(p,d);
		erase(p->ch[d],val);
		update(p);
		return;
	}
	erase(p->ch[val<=p->val],val);
	update(p);
}
void solve(){
	int i,na,nb,j;
	sort(r+1,r+n+1,cmp);
	double sum=0,sumu=0,sump=0;
	for(i=1;i<=n;i++)
		insert(root[0],p[i]);
	ans=max(ans,get_sum(root[0],a));
	root[0]=0,tcnt=tree;
	for(i=1;i<=n;i++){
		tcnt=tree,root[0]=root[1]=0;
		s1.insert(r[i]);
		sump+=p[r[i]];
		sumu=0,sum=sump;
	//	tcnt=0;
		for(j=i+1;j<=n;j++)
			insert(root[0],p[r[j]]);
		for(j=i;j;j--)
			insert(root[1],u[r[j]]-p[r[j]]);
		if(i-b>a)
			break;
		ans=max(sump+get_sum(root[1],b)+get_sum(root[0],a-max((i-b),0)),ans);
		nb=b,na=a-max((i-b),0);
		for(auto j:s1){
			sumu+=u[j];
			sum-=p[j];
			nb--;
			if(nb<0)
				break;
			erase(root[1],u[j]-p[j]);
			insert(root[0],(1-u[j])*p[j]);
			ans=max(ans,sumu+sum+get_sum(root[1],nb)+get_sum(root[0],na));
		}
	}
}
int main()
{
	srand(2016120194);
	read();
	solve();
	printf("%f\n",ans);
}