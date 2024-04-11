#include<cstdio>
const int N=102;
int n,i,a[N],s[N],s1,s2;
char c[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s[a[i]]++;
	for(i=1;i<=100;i++){
		if(s[i]==1)
			s1++;
		if(s[i]>2)
			s2++;
	}
	if(s1%2==1&&!s2){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(s1%2==0){
		s1=s1/2;
		for(i=1;i<=n;i++){
			c[i]='B';
			if(s[a[i]]==1&&s1){
				c[i]='A';
				s1--;
			}
		}
		printf("%s",c+1);
	}
	else{
		s1=s1/2;
		s2=1;
		for(i=1;i<=n;i++){
			c[i]='B';
			if(s[a[i]]==1&&s1){
				c[i]='A';
				s1--;
			}
			if(s[a[i]]>2&&s2){
				c[i]='A';
				s2--;
			}
		}
		printf("%s",c+1);
	}
}