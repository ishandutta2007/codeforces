#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

long long cuad(int x){return 1LL*x*x;}

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int n,x[2048],y[2048];

map<pair<long long, pair<int,int> >,int> w;

pair<int,int> rat(int p, int q){
	if(!p)return mp(0,1);
	if(!q)return mp(1,0);
	bool neg=(p>0&&q<0)||(p<0&&q>0);
	p=abs(p);q=abs(q);
	int m=gcd(p,q);
	p/=m;q/=m;
	if(neg)p=-p;
	return mp(p,q);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",x+i,y+i);
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			w[mp(cuad(y[j]-y[i])+cuad(x[j]-x[i]),rat(y[j]-y[i],x[j]-x[i]))]++;
		}
	}
	long long r=0;
	for(map<pair<long long,pair<int,int> >,int>::iterator it=w.begin();it!=w.end();++it)r+=(it->second*(it->second-1))/2;
	cout<<r/2<<endl;
	return 0;
}