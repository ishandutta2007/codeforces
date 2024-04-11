#include<cstdio>
const int N=100002;
int n,a,i,s[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a),s[a]++;
	for(i=0;i<N;i++){
		if(s[i]>(n+1)/2){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}