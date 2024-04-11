#include<cstdio>
const int N=500002;
int cnt,n,i,k,L[N],R[N],p,ans;
char s[N];
int okL(){
	int f=0;
	for(i=1;i<=n;i++){
		if(s[i]=='(')
			f++;
		if(s[i]==')')
			f--;
		if(f<0)
			return f;
	}
	return f;
}
int okR(){
	int f=0;
	for(i=n;i;i--){
		if(s[i]==')')
			f++;
		if(s[i]=='(')
			f--;
		if(f<0)
			return f;
	}
	return f;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&cnt);
	while(cnt--){
		scanf("%s",s+1);
		for(n=0;s[n+1];n++);
		k=okL();
		if(k>=0){
			if(k==0)
				p++;
			else
				L[k]++;
		}
		else{
			k=okR();
			if(k>0)
				R[k]++;
		}
	}
	ans+=p/2;
	for(i=1;i<N;i++)
		ans+=min(L[i],R[i]);
	printf("%d",ans);
}