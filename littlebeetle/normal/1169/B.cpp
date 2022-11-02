#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=300002;
int m,n,i,a[N],b[N],cnt[N],s;
void Check(int x){
	memset(cnt,0,sizeof(cnt));
	s=0;
	for(i=2;i<=n;i++){
		if(a[i]!=x&&b[i]!=x){
			s++;
			cnt[a[i]]++;
			if(a[i]!=b[i])
				cnt[b[i]]++;
		}
	}
	for(i=0;i<N;i++)
		if(cnt[i]==s){
			printf("YES");
			exit(0);
		}
}
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",a+i,b+i);
	}
	Check(a[1]);
	Check(b[1]);
	printf("NO");
}