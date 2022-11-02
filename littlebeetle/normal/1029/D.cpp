#include<cstdio>
#include<map>
using namespace std;
const int N=200003;
map<int,int>p[12];
int n,k,i,j,a[N],l[N];
long long t[12],ans;
int g(int x){
	return x?k-x:0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1,t[0]=1;i<=11;i++)
		t[i]=t[i-1]*10;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		while(a[i]/t[l[i]])
			l[i]++;
		p[l[i]][a[i]%k]++;
	}
	for(i=1;i<=n;i++){
		if((a[i]*(t[l[i]]%k)+a[i])%k==0)
			ans--;
		for(j=1;j<=10;j++)
			ans+=p[j][g(a[i]*(t[j]%k)%k)];
	}
	printf("%I64d",ans);
	return 0;
}