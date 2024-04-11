#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
const int N=10003;
int n,i,j,cnt1[N],cnt2[N],a[N];
int x[N],y[N],k;
char s1[N],s2[N];
queue<int>q[N];
void init(){
	scanf("%d%s%s",&n,s1+1,s2+1);
	for(i=1;i<=n;i++){
		s1[i]-=97;
		s2[i]-=97;
		cnt1[s1[i]]++;
		cnt2[s2[i]]++;
	}
	for(i=0;i<N;i++)
		if(cnt1[i]!=cnt2[i]){
			printf("-1");
			exit(0);
		}
	for(i=1;i<=n;i++)
		q[s2[i]].push(i);
	for(i=1;i<=n;i++)
		a[i]=q[s1[i]].front(),
		q[s1[i]].pop();
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
void work(){
	for(i=1;i<=n;i++)
		for(j=1;j+i<=n;j++)
			if(a[j]>a[j+1]){
				k++;
				x[k]=j;
				swap(a[j],a[j+1]);
			}
	printf("%d\n",k);
	for(i=1;i<=k;i++)
		printf("%d ",x[i]);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}