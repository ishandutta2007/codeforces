#include<cstdio>
long long l,r,k;
void Read(long long &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int main()
{
	Read(l),Read(r),Read(k);
	long long t=r,cnt=0,ret=1;
	while(t){
		t/=k;
		cnt++;
	}
	for(int i=1;i<cnt;i++){
		if(ret>=l)
			printf("%I64d ",ret);
		ret*=k;
	}
	if(ret>=l)
		printf("%I64d\n",ret);
	else
		puts("-1");
}