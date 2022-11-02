#include<cstdio>
#include<iostream>
using namespace std;
const int N=20;
long long l,r,c[N][N],y,z,s,p,q;
int t,i,j,k;
long long d(long long x){
	s=0;y=x;i=0;z=1;
	while(y/10){
		s+=9*(c[i][0]+c[i][1]*9+c[i][2]*81);
		y/=10;
		z*=10;
		i++;
	}
	s+=(x/z%10-1)*(c[i][0]+c[i][1]*9+c[i][2]*81);
	i--;z/=10;
	p=1;
	//printf("%lld %d\n",s,i);
	while(i>=0){
		q=x/z%10;
		if(q){
			if(p==1)s+=(q-1)*(c[i][0]+c[i][1]*9)+c[i][2]*81+c[i][1]*9+c[i][0];
			if(p==2)s+=(q-1)*c[i][0]+c[i][1]*9+c[i][0];
			if(p==3)s+=c[i][0];
			p++;
		}
		//printf("%lld\n",s);
		i--;
		z/=10;
	}
	//printf("%lld ",s);
	return s;
}
int main(){
	cin>>t;
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	while(t--){
		cin>>l>>r;
		cout<<d(r+1)-d(l)<<endl;
	}
}