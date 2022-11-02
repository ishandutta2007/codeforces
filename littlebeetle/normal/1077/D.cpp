#include<cstdio>
const int N=200002;
int n,k,i,l,r,mid,a,s[N],t,o;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a),s[a]++;
	l=1;r=n;
	while(l<r){
		mid=(l+r+1)/2;
		t=0;
		for(i=0;i<N;i++)
			t+=s[i]/mid;
		if(t>=k)
			l=mid;
		else
			r=mid-1;
	}
	for(i=0;i<N&&o<k;i++){
		t=s[i]/l;
		while(t--&&o<k)
			printf("%d ",i),o++;
	}
	return 0;
}