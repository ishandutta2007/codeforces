#include<cstdio>
#include<deque>
using namespace std;
const int N=100002,D=350;
short cnt[D][N];
deque<int>Q[D];
int n,i,j,k,a,x[N],Ans,lastans;
int q,p,y,u,v,opt,l,r;
int id[N],L[D],R[D];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		id[i]=i/D;
		if(!L[i/D])
			L[i/D]=i;
		R[i/D]=i;
		scanf("%d",&a);
		Q[id[i]].push_back(a);
		cnt[id[i]][a]++;
	}
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
void Update(int l,int r){
	if(id[l]==id[r]){
		p=id[l];
		for(i=R[p];i>=L[p];i--){
			x[i]=Q[p].back();
			Q[p].pop_back();
		}
		y=x[r];
		for(i=r;i>l;i--)
			x[i]=x[i-1];
		x[i]=y;
		for(i=L[p];i<=R[p];i++)
			Q[p].push_back(x[i]);		
	}
	else{
		p=id[r];
		for(i=L[p];i<=r;i++){
			x[i]=Q[p].front();
			Q[p].pop_front();
		}
		y=x[r];
		cnt[p][y]--;
		for(i=r-1;i>=L[p];i--)
			Q[p].push_front(x[i]);	
		p=id[l];
		for(i=R[p];i>=l;i--){
			x[i]=Q[p].back();
			Q[p].pop_back();
		}
		Q[p].push_back(y);
		cnt[p][y]++;
		for(i=l;i<=R[p];i++){
			if(x[i]==k)
				Ans++;	
			Q[p].push_back(x[i]);
		}	
		for(i=id[l];i<id[r];i++){
			y=Q[i].back();
			Q[i].pop_back();
			Q[i+1].push_front(y);
			cnt[i][y]--;
			cnt[i+1][y]++;
		}
	}
}
void Query(int l,int r,int k){
	Ans=0;
	if(id[l]==id[r]){
		p=id[l];
		for(i=R[p];i>=L[p];i--){
			x[i]=Q[p].back();
			Q[p].pop_back();
		}
		for(i=l;i<=r;i++)
			if(x[i]==k)
				Ans++;
		for(i=L[p];i<=R[p];i++)
			Q[p].push_back(x[i]);
	}
	else{
		p=id[l];
		for(i=R[p];i>=l;i--){
			x[i]=Q[p].back();
			Q[p].pop_back();
		}
		for(i=l;i<=R[p];i++){
			if(x[i]==k)
				Ans++;	
			Q[p].push_back(x[i]);
		}
		p=id[r];
		for(i=L[p];i<=r;i++){
			x[i]=Q[p].front();
			Q[p].pop_front();
		}
		for(i=r;i>=L[p];i--){
			if(x[i]==k)
				Ans++;
			Q[p].push_front(x[i]);
		}
		for(i=id[l]+1;i<id[r];i++)
			Ans+=cnt[i][k];
	}
}
void work(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&l,&r);
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			if(l>r)
				swap(l,r);
			Update(l,r);
		}
		else{
			scanf("%d%d%d",&l,&r,&k);
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			if(l>r)
				swap(l,r);
			k=(k+lastans-1)%n+1;
			Query(l,r,k);
			printf("%d\n",Ans);
			lastans=Ans;
		}
	}
}
int main(){
	init();
	work();
	return 0;
}