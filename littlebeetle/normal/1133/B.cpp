#include<cstdio>
const int N=102;
int n,k,i,a,s[N],S;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[a%k]++;
	}
	S+=s[0]/2;
	for(i=1;i*2<k;i++)
		S+=min(s[i],s[k-i]);
	if(i*2==k)
		S+=s[i]/2;
	printf("%d",S*2);
}