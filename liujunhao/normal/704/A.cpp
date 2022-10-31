#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
#define MAXN 300000
struct node{
	int sum;
	bool tag;
}tree[MAXN*4+10];
void push_down(int i){
	if(tree[i].tag){
		tree[i<<1].tag=tree[(i<<1)|1].tag=1;
		tree[(i<<1)|1].sum=tree[i<<1].sum=0;
		tree[i].tag=1;
	}
}
void update(int i){
	tree[i].sum=tree[i<<1].sum+tree[(i<<1)|1].sum;
}
void insert2(int i,int l,int r,int p){
	if(l==r){
		tree[i].sum=1;
		return;
	}
	int mid((l+r)>>1);
	push_down(i);
	if(p<=mid)
		insert2(i<<1,l,mid,p);
	else
		insert2((i<<1)|1,mid+1,r,p);
	update(i);
}
void insert(int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr){
		tree[i].tag=1,tree[i].sum=0;
		return;
	}
	if(ll>r||rr<l)
		return;
	int mid((l+r)>>1);
	push_down(i);
	insert(i<<1,l,mid,ll,rr);
	insert((i<<1)|1,mid+1,r,ll,rr);
	update(i);
}
int n,q;
vector<int>pos[MAXN+10];
int main()
{
	Read(n),Read(q);
	int cnt=0;
	int i,p,x;
	for(i=1;i<=q;i++){
		Read(p),Read(x);
		if(p==1){
			insert2(1,1,q,++cnt);
			pos[x].push_back(cnt);
		}
		else if(p==2){
			for(vector<int>::iterator j=pos[x].begin();j<pos[x].end();j++)
				insert(1,1,q,*j,*j);
			pos[x].clear();
		}
		else
			insert(1,1,q,1,x);
		printf("%d\n",tree[1].sum);
	}
}