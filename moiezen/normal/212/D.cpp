#include <cstdio>
int n,a[1000010],l[1000010],r[1000010],stack[1000010],top;
long long d[1000010];
int F(){
	char ch;while((ch=getchar())<'0'||ch>'9');
	int aa=ch-'0';while((ch=getchar())>='0'&&ch<='9')aa=aa*10+ch-'0';
	return aa;
}
int main(){
	n=F();
	for(int i=0;i<n;i++)a[i]=F();
	for(int i=0;i<n;i++){
		while(top&&a[stack[top-1]]>a[i])r[stack[--top]]=i;
		if(top)l[i]=stack[top-1];
		else l[i]=-1;
		stack[top++]=i;
	}
	while(top)r[stack[--top]]=n;
	for(int i=0;i<n;i++){
		int x=i-l[i],y=r[i]-i;
		if(x>y){int t=x;x=y;y=t;}
		d[1]+=a[i];d[x+1]-=a[i];d[y+1]-=a[i];d[x+y+1]+=a[i];
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	for(int i=1;i<=n;i++)d[i]=d[i]+d[i-1];
	int m,k;
	m=F();
	while(m--){
		k=F();
		printf("%.12f\n",d[k]*1.0/(n-k+1));
	}
}