#include<cstdio>
const int N=200002;
int n,a[N],s[N],i,j,p,f[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s[a[i]]++,p+=s[a[i]]>1;
	printf("%d\n",p);
	for(i=j=1;i<=n;i++){
		while(s[j])j++;
		if(s[a[i]]>1){
			if(j<a[i]||f[a[i]])
				s[a[i]]--,
				a[i]=j,
				s[j]++;
			else
				f[a[i]]=1;
		}
		printf("%d ",a[i]);
	}
}