#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200020;
int Q,n,cnt,sum,len,i,k;
char s[N];
int main(){
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&n);
		cnt=sum=0;
		for(i=0;i<n;i++){
			scanf("%s",s+1);
			for(len=0;s[len+1];len++);
			if(len%2)cnt++;
			for(k=1;k<=len;k++)
				if(s[k]=='1')
					sum++;
		}
		if(cnt==0&&sum%2)
			printf("%d\n",n-1);
		else
			printf("%d\n",n);
	}
}