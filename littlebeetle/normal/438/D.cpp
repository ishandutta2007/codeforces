#include<cstdio>
const int N=400020;
int n,q,opt,i,j,D=1,a[N],t[N],x,y,l,r,g,p;
long long s[N],S;
char c;
void rd(int &a){
	a=0;
	while((c=getchar())<48);
	while(c>47)
		a=(a<<3)+(a<<1)+(c^48),
		c=getchar();
}
int main(){
	rd(n);rd(q);
	while(D<n+2)D<<=1;
	for(i=1;i<=n;i++)
		rd(a[i]),t[i+D]=i,s[i+D]=a[i];
	for(i=D-1;i;i--)
		t[i]=a[t[i<<1]]>a[t[i<<1|1]]?t[i<<1]:t[i<<1|1],
		s[i]=s[i<<1]+s[i<<1|1];
	while(q--){
		rd(opt);
		if(opt==1)	{
			rd(x);rd(y);
			S=0;
			for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
				if(~x&1)S+=s[x^1];
				if(  y&1)S+=s[y^1];
			}
			printf("%lld\n",S);
		}
		if(opt==2){
			rd(l);rd(r);rd(p);
			while(1){
				g=0;
				for(x=l+D-1,y=r+D+1;x^y^1;x>>=1,y>>=1){
					if((~x&1)&&a[t[x^1]]>a[g])g=t[x^1];
					if((  y&1)&&a[t[y^1]]>a[g])g=t[y^1];
				}
				if(a[g]<p)
					break;
				a[g]%=p;
				s[g+D]=a[g];
				for(i=g+D>>1;i;i>>=1)
					t[i]=a[t[i<<1]]>a[t[i<<1|1]]?t[i<<1]:t[i<<1|1],
					s[i]=s[i<<1]+s[i<<1|1];
			}
		}
		if(opt==3){
			rd(i);rd(x);
			a[i]=x;
			s[i+D]=x;
			for(i=i+D>>1;i;i>>=1)
				t[i]=a[t[i<<1]]>a[t[i<<1|1]]?t[i<<1]:t[i<<1|1],
				s[i]=s[i<<1]+s[i<<1|1];
		}
	}
}