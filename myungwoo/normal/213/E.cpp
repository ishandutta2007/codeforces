#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005
typedef unsigned long long ulld;

int N,M,A[MAXN],B[MAXN],pos[MAXN],ans;
ulld T,p4423[MAXN],ones;

struct NODE{
	ulld hash; int cnt;
	NODE *left,*right;
} root;

NODE *make()
{
	NODE *ret=(NODE*)malloc(sizeof(NODE));
	ret->hash = ret->cnt = 0;
	ret->left = ret->right = NULL;
	return ret;
}

void update(NODE *now,int s,int e,int p,int v)
{
	if (e < p || s > p) return;
	if (s == e){
		if (!v) now->hash = now->cnt = 0;
		else now->hash = v, now->cnt = 1;
		return;
	}
	int m=(s+e)>>1;
	if (now->left == NULL){
		now->left = make();
		now->right = make();
	}
	update(now->left,s,m,p,v);
	update(now->right,m+1,e,p,v);
	now->hash = now->left->hash*p4423[now->right->cnt]+now->right->hash;
	now->cnt = now->left->cnt+now->right->cnt;
}

int main()
{
	int i;
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	for (i=1;i<=M;i++) scanf("%d",B+i), pos[B[i]] = i;
	p4423[0] = 1;
	for (i=1;i<=N;i++) p4423[i] = p4423[i-1]*4423;
	for (i=0;i<N;i++) ones += p4423[i];
	for (i=1;i<=N;i++) T = T*4423+A[i];
	for (i=1;i<N;i++) update(&root,1,M,pos[i],i);
	for (i=N;i<=M;i++){
		update(&root,1,M,pos[i],i);
		if (root.hash == T) ans++;
		T += ones;
		update(&root,1,M,pos[i-N+1],0);
	}
	printf("%d",ans);
}