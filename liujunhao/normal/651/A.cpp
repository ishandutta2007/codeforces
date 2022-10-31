#include<cstdio>
int a,b,ans;
void Read(int &x){
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
	int i;
	Read(a),Read(b);
	while(1){
		b+=(a-1)>>1;
		ans+=(a-1)>>1;
		a-=((a-1)>>1)<<1;
		ans+=(b-1)>>1;
		a+=(b-1)>>1;
		b-=((b-1)>>1)<<1;
		if(a<=2&&b<=2)
			break;
	}
	if(!(a<2&&b<2))
		ans++;
	printf("%d\n",ans);
}