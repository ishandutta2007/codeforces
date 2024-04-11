#include<cstdio>
const int N=2000002;
int n,q,D=1,i,j,k,a,b,h[N],t[N],v[N],s[N],d[N],T,t1[N],t2[N],p[N],x,y,z;
void dfs(int i,int fa){
	d[i]=++T;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			s[i]+=s[v[j]];
		}
	s[i]++;
}
int max(int x,int y){
	return x>y?x:y;
}
char c;
void rd(int &a){
	a=0;
	while((c=getchar())<48);
	while(c>47)
		a=(a<<3)+(a<<1)+(c^48),
		c=getchar();
}
int main(){
	rd(n);
	for(i=1;i<n;i++){
		rd(a);rd(b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	while(D<n+2)D<<=1;
	rd(q);
	p[0]=2;
	for(i=1;i<=q;i++){
		rd(p[i]);rd(a);
		if(p[i]==1){
			for(x=d[a]+D-1,y=d[a]+s[a]+D;x^y^1;x>>=1,y>>=1){
				if(~x&1)t1[x^1]=i;
				if(  y&1)t1[y^1]=i;
			}
		}
		if(p[i]==2){
			for(x=d[a]+D;x;x>>=1)
				t2[x]=i;
		}
		if(p[i]==3){
			z=0;
			for(x=d[a]+D;x;x>>=1)
				z=max(z,t1[x]);
			for(x=d[a]+D-1,y=d[a]+s[a]+D;x^y^1;x>>=1,y>>=1){
				if(~x&1)z=max(z,t2[x^1]);
				if(  y&1)z=max(z,t2[y^1]);
			}	
			printf("%d\n",2-p[z]);
		}
	}
	return 0;
}