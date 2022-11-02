#include<cstdio>
const int N=1000002;
int n,l1,l2,k1,k2,opt;
char f[N],g[N];
struct P{
	int x;
	char c;
}u,v;
P Get(int &k,int l,char *s){
	if(k>l)return (P){-1,'A'};
	int i=0;
	for(i=0;s[i+k]==s[i+k+1];i++);
	k+=i+1;
	return (P){i,s[k-1]};
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",f+1,g+1);
		for(l1=0;f[l1+1];l1++);
		for(l2=0;g[l2+1];l2++);
		k1=k2=1;
		opt=1;
		while((u=Get(k1,l1,f)).x!=-1&&(v=Get(k2,l2,g)).x!=-1){
			if(u.c!=v.c||u.x>v.x){
				opt=0;
				break;
			}
			if(k1>l1||k2>l2)
			break;
		}
		if(k1>l1&&k2>l2&&opt)
			printf("YES\n");
		else
			printf("NO\n");
	}
}