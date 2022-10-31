#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
int n;
typedef unsigned long long LL;
inline LL gcd(LL a,LL b){
	LL t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	Read(n);
	int i;
	LL a,now=2,t;
	for(i=1;i<=n;i++){
		a=sqrt(now+0.5);
		if(a*a<now)
			a++;
		//t=sqrt(i+0.5);
	//	if(t*t!=i)
			t=i;
		t*=(i+1);
		if(a%t)
			t+=a/t*t;
		else
			t=a;
		
		printf("%I64u\n",t/i*t-now/i%(t/i*t));
		now=t;
	}
}