#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=1<<17;

int n,k,q;

int tot;
int p[MaxN];

int Binary_L(int x)
{
	if (p[1]>=x) return 1;
	int L=2,R=tot;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (p[mid]>=x&&p[mid-1]<x) return mid;
		(p[mid]>=x)?R=mid-1:L=mid+1;
	}
}

int Binary_R(int x)
{
	if (p[tot]<=x) return tot;
	int L=1,R=tot-1;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (p[mid]<=x&&p[mid+1]>x) return mid;
		(p[mid]<=x)?L=mid+1:R=mid-1;
	}
}

struct node
{
	int res,age;	//responsibility age
	int from;		//serial number
	int num;		//the number of members in the largest club
	int way;		//age rank
}man[MaxN];

bool cmp_res(node A,node B)
{
	return A.res<B.res;
}

bool cmp_age(node A,node B)
{
	return A.age<B.age;
}

bool cmp_from(node A,node B)
{
	return A.from<B.from;
}

int tree[MaxN<<1];

void Age_Insert(int i)
{
	for (int k=man[i].way+MaxN-1;k;k>>=1) ++tree[k];
}

int Age_Sum(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y) return tree[k];
	int mid=(L+R)>>1;
	if (y<=mid) return Age_Sum(k<<1,L,mid,x,y);
	if (x>mid) return Age_Sum(k<<1|1,mid+1,R,x,y);
	return Age_Sum(k<<1,L,mid,x,mid)+Age_Sum(k<<1|1,mid+1,R,mid+1,y);
}

void Num_Insert(int i)
{
	for (int k=man[i].way+MaxN-1;k;k>>=1) tree[k]=max(tree[k],man[i].num);
}

int Num_Max(int k,int L,int R,int x,int y)
{
	if (L==x&R==y) return tree[k];
	int mid=(L+R)>>1;
	if (y<=mid) return Num_Max(k<<1,L,mid,x,y);
	if (x>mid) return Num_Max(k<<1|1,mid+1,R,x,y);
	return max(Num_Max(k<<1,L,mid,x,mid),Num_Max(k<<1|1,mid+1,R,mid+1,y));
}

struct question
{
	int x,y;
	int res,xage,yage;
	int rank;
	int ans;
}task[MaxN];

bool cmp_task(question A,question B)
{
	return A.res>B.res;
}

bool cmp_rank(question A,question B)
{
	return A.rank<B.rank;
}

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i) scanf("%d",&man[i].res);
	for (int i=1;i<=n;++i) scanf("%d",&man[i].age);
	for (int i=1;i<=n;++i) man[i].from=i;
	sort(man+1,man+n+1,cmp_age);
	p[1]=man[1].age;
	tot=man[1].way=1;
	for (int i=2;i<=n;++i)
	{
		if (man[i].age==p[tot])
			man[i].way=tot;
		else
		{
			p[++tot]=man[i].age;
			man[i].way=tot;
		}
	}
	sort(man+1,man+n+1,cmp_res);
	for (int i=1,j=0;i<=n;++i)
	{
		while (j<n&&man[j+1].res==man[i].res)
		{
			++j;
			Age_Insert(j);
		}
		int L=Binary_L(man[i].age-k);
		int R=Binary_R(man[i].age+k);
		if (L<=R) man[i].num=Age_Sum(1,1,MaxN,L,R);
	}
}

void work()
{
	sort(man+1,man+n+1,cmp_from);
	cin>>q;
	for (int i=1;i<=q;++i)
	{
		scanf("%d%d",&task[i].x,&task[i].y);
		if (man[task[i].x].res<man[task[i].y].res) swap(task[i].x,task[i].y);
		task[i].res=man[task[i].x].res;
		task[i].xage=Binary_L(max(man[task[i].x].age,man[task[i].y].age)-k);
		task[i].yage=Binary_R(min(man[task[i].x].age,man[task[i].y].age)+k);
		task[i].rank=i;
	}
	sort(task+1,task+q+1,cmp_task);
	memset(tree,0,sizeof(tree));
	sort(man+1,man+n+1,cmp_res);
	for (int i=1,j=n+1;i<=q;++i)
	{
		while (j>1&&man[j-1].res>=task[i].res)
		{
			--j;
			Num_Insert(j);
		}
		if (task[i].xage<=task[i].yage) task[i].ans=Num_Max(1,1,MaxN,task[i].xage,task[i].yage);
	}
	sort(task+1,task+q+1,cmp_rank);
	for (int i=1;i<=q;++i)
		printf("%d\n",(task[i].ans)?task[i].ans:-1);
}

int main()
{
	init();
	work();
	return 0;
}