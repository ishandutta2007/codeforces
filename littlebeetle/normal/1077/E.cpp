#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
int n,i,j,k,a[N],b,s[N],t[N],g,ans,o;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=2,b=1;i<=n+1;i++)
		if(a[i]==a[i-1])
			b++;
		else
			s[b]++,b=1;
	for(k=N,i=N-1;i;i--){
		if(s[i])
			k=i;
		t[i]=k;
	}
	for(k=1;k<=n;k++){
		g=0;
		o=k;
		i=t[k];
		while(i!=N){
			j=s[i];
			while(j&&i>=o)
				g+=o,o<<=1,j--;
			if(max(o,i+1)>=N)
				break;
			i=t[max(o,i+1)];
		}
		if(g>ans)
			ans=g;
	}
	printf("%d",ans);
	return 0;
}