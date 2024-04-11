#include<cstdio>
const int N=10002;
int n,a,i,j,ans,s[N];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		s[a]++;
	}
	for(i=1;i<N;i++)
		if(s[i]){
			ans++;
			for(j=i;j<N;j+=i)
				s[j]=0;
		}
	printf("%d",ans);
}