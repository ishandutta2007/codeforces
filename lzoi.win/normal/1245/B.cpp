#include<cstdio>
#include<cstring>
const int N=105;
const int Z=3;
char s[N];
int Num[Z],Num_[Z],n,T,k,p[Z];
inline int Min(const int x,const int y){
	return x<y?x:y; 
}
inline void Print(const int x){
	if(x==0) putchar('R');
	if(x==1) putchar('P');
	if(x==2) putchar('S');
}
inline void Query_(){
	for(int i=0;i<n;i++){
		int q,l;
		if(s[i]=='R') q=0;
		if(s[i]=='P') q=1;
		if(s[i]=='S') q=2;
		l=(q+1)%Z;
		if(Num[l]){
			Print(l);
			Num[l]--;
		}else{
			for(int k=0;k<Z;k++)
				if(Num_[k]>0){
					Num_[k]--;
					Num[k]--;
					Print(k);
					break ;
				}
		}
	}
	putchar('\n');
}
inline void Query(){
	k=0;
	for(int i=0;i<n;i++){
		int q;
		if(s[i]=='R') q=0;
		if(s[i]=='P') q=1;
		if(s[i]=='S') q=2;
		p[q]++;
	}
	for(int i=0;i<Z;i++){
		int j=(i+1)%Z;
		k+=Min(Num[j],p[i]);
		Num_[j]-=p[i];
	}
	k<<=1;
	if(k>=n){
		puts("YES");
		Query_();
	}
	else puts("NO");
}
inline void Init(){
	scanf("%d",&n);
	memset(p,0,sizeof(p));
	for(int i=0;i<Z;i++)
		scanf("%d",Num+i),Num_[i]=Num[i];
	scanf("%s",s);
}
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Query();
	}
	return 0;
}