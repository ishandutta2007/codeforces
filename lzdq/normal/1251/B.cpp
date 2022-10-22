#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=55;
char s[N];
int n,sum[2],len[N];
inline void Init(){
	scanf("%d",&n);
	sum[0]=sum[1]=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		len[i]=strlen(s);
		for(int j=0;s[j];j++)
			sum[s[j]-48]++;
	}
	sort(len+1,len+n+1);
}
inline void Query(){
	for(int i=1;i<=n;i++){
		int q=len[i]&1;
		len[i]-=q;
		if(sum[0]>1){
			int p=sum[0]>>1;
			p<<=1;
			if(p>len[i]){
				sum[0]-=len[i];
				len[i]=0;
			}
			else{
				sum[0]-=p;
				len[i]-=p;
			}
		}
		if(sum[1]>1){
			int p=sum[1]>>1;
			p<<=1;
			if(p>len[i]){
				sum[1]-=len[i];
				len[i]=0;
			}
			else{
				sum[1]-=p;
				len[i]-=p;
			}
		}
		if(len[i]) return printf("%d\n",i-1),void();
		if(q){
			if(!sum[0]&&!sum[1]) return printf("%d\n",i-1),void();
			if(sum[0]&1) sum[0]--;
			else sum[1]--; 
		}
	}
	printf("%d\n",n);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)
		Init(),Query(); 
	return 0;
}