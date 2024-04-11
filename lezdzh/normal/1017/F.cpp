#include<cstdio>

using namespace std;

bool b[100001];
int a[100001];
int main(){
	int n,A,B,C,D;
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	for(int i=2;i<100000;i++){
		if(!b[i])a[++a[0]]=i;
		for(int j=i;j<100000;j+=i)
			b[j]=1;
	}
	unsigned ans=0;
	for(int i=1;i<=a[0];i++){
		unsigned o=a[i],w=0;
		for(long long oo=o;oo<=n;){
			w+=n/oo;
			oo*=o;
		}
		ans+=w*(((A*o+B)*o+C)*o+D);
	}
	for(int i=0;i<=100000;i++)
		b[i]=0;
	for(int i=100000;i<=n;i+=100000){
		register int l=i,r=i+100000-1;
		for(int j=1;j<=a[0];j++){
			register int o=a[j];
			for(register int k=(l-1+o)/o*o-l+1;k<=100000;k+=o)
				b[k]=1;
		}
		for(register int j=1;j<=100000;j++){
			if(!b[j]){
				unsigned o=l+j-1;
				ans+=n/o*(((A*o+B)*o+C)*o+D);
			}
			b[j]=0;
		}
	}
	printf("%I64d\n",(long long)ans);
}