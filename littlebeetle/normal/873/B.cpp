#include<cstdio>
const int N=200002;
int n,i,f=N/2,p,a,s[N];
int main(){
	scanf("%d",&n);
	n++;
	s[f]=1;
	for(i=2;i<=n;i++){
		scanf("%1d",&a);
		f+=a*2-1;
		if(s[f]){
			if(i-s[f]>p)
				p=i-s[f];
		}
		else
		s[f]=i;
	}
	printf("%d",p);
}