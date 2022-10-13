#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<assert.h>
using namespace std;
int n;
struct node{
	int pnt,id,flag;
	node(){}
	node(int _pnt,int _id,int _flag){
		pnt = _pnt;
		id = _id;
		flag = _flag;
	}
} a[222];
bool cmp(node P1,node P2){
	if(P1.pnt != P2.pnt)
		return P1.pnt > P2.pnt;
	return P1.id < P2.id;
}
int oldrank[222],newrank[222];
int old_pnt[222],new_pnt[222];
bool e[111][111];int deg[111];

int q[111];
int id1[111],id2[111];
int pnt1[111],pnt2[111];
bool cmp1(int x,int y){
	if(pnt1[x] != pnt1[y])
		return pnt1[x] > pnt1[y];
	return x<y;
}
bool cmp2(int x,int y){
	if(pnt2[x] != pnt2[y])
		return pnt2[x] > pnt2[y];
	return x<y;
}

int main(){
	scanf("%d",&n);
	int la=0;
	for(int i=1; i<=n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[la++]=node(x,i,-1);
		a[la++]=node(x+y,i,1);
		old_pnt[i] = x;
		new_pnt[i] = x+y;
	}
	sort(a,a+la,cmp);
	for(int i=0; i<la; i++)
		if(a[i].flag == -1)
			oldrank[a[i].id] = i;
		else
			newrank[a[i].id] = i;
	memset(e,0,sizeof(e));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(i==j)continue;
			if(newrank[i] < newrank[j] && newrank[j] < oldrank[i] && oldrank[i] < oldrank[j]){
//				printf("%d %d\n",j,i);
				e[j][i] = true;
			}
			if(oldrank[i] < oldrank[j] && oldrank[j] < newrank[i] && newrank[i] < newrank[j]){
//				printf("%d %d\n",i,j);
				e[i][j] = true;
			}
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(e[i][j])
				deg[j]++;
	int lq=0;
	for(int i=1; i<=n; i++)
		if(deg[i] == 0)
			q[++lq] = i;
	for(int i=1; i<=n; i++){
		assert(i<=lq);
		int x = q[i];
		for(int j=1; j<=n; j++)
			if(e[x][j]){
				if(--deg[j]==0)
					q[++lq]=j;
			}
	}
	int res=0;
	for(int i=1; i<=n; i++){
		pnt2[i] = old_pnt[i];
	}
	for(int i=1; i<=n; i++){
		memcpy(pnt1,pnt2,sizeof(pnt1));
		int x = q[i];
		pnt2[x] = new_pnt[x];
		for(int j=1; j<=n; j++)
			id1[j] = id2[j] = j;
		sort(id1+1, id1+n+1, cmp1);
		sort(id2+1, id2+n+1, cmp2);
		int now=0;
		for(int j=1; j<=n; j++)
			if(id1[j] != id2[j])
				now++;
		if(now>0)now--;
//		printf("%d\n",now);
		res+=now;
	}
	printf("%d\n",res);
	return 0;
}