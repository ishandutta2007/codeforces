#include<cstdio>
const int N=100002;
int n,l,r,a[N],s1,s2,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	l=1;r=n;
	while(l<=r){
		if(a[l]>a[r])
			s1+=a[l++];
		else
			s1+=a[r--];
		if(l>r)break;
		if(a[l]>a[r])
			s2+=a[l++];
		else
			s2+=a[r--];		
	}
	printf("%d %d\n",s1,s2);
}