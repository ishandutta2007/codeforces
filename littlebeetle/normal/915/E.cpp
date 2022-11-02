#include<cstdio>
const int N=16000002;
int n,q,x,y,k,rt=1,L[N],R[N],p[N],cnt=1,ans,s[N];
void Update(int rt,int l,int r){
	if(x<=l&&r<=y){
		p[rt]=k;
		if(k==2)
			s[rt]=r-l+1;
		else
			s[rt]=0;
		return;
	}
	int mid=l+r>>1;
	if(!L[rt])L[rt]=++cnt,s[L[rt]]=mid-l+1;
	if(!R[rt])R[rt]=++cnt,s[R[rt]]=r-mid;
	if(p[rt]){
		p[L[rt]]=p[R[rt]]=p[rt];	
		if(p[rt]==2)
			s[L[rt]]=mid-l+1,s[R[rt]]=r-mid;
		else
			s[L[rt]]=s[R[rt]]=0;
		p[rt]=0;
	}
	if(x<=mid)
		Update(L[rt],l,mid);
	if(y>mid)
		Update(R[rt],mid+1,r);
	s[rt]=s[L[rt]]+s[R[rt]];
}	
int main(){
	scanf("%d%d",&n,&q);
	s[1]=n;
	while(q--){
		scanf("%d%d%d",&x,&y,&k);
		Update(rt,1,n);
		printf("%d\n",s[1]);
	}
}