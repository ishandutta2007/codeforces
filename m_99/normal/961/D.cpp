#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
int n;
vector<long long> x,y;

long long get(int a,int b,int c,int d){
	return (x[a]-x[b]) * (y[c]-y[d]) - (y[a]-y[b]) * (x[c]-x[d]);
}

unsigned long xor128() {
	static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
	unsigned long t=(x^(x<<11));
	x=y; y=z; z=w;
	return (w=(w^(w>>19))^(t^(t>>8)));
}

int main(){
	
	cin>>n;
	
	x.resize(n),y.resize(n);
	
	rep(i,n){
		scanf("%lld %lld",&x[i],&y[i]);
	}
	
	if(n<=4){
		cout<<"YES"<<endl;
		return 0;
	}
	
	rep(_,300){
		int x = xor128()%n;
		int y = xor128()%n;
		if(x==y)continue;
		vector<int> inds;
		bool f = true;
		rep(i,n){
			if(i==x||y==i)continue;
			if(get(x,y,x,i)==0)continue;
			else{
				inds.push_back(i);
			}
		}
		if(inds.size()<=2){
			cout<<"YES"<<endl;
			return 0;
		}
		for(int i=2;i<inds.size();i++){
			if(get(inds[0],inds[1],inds[0],inds[i])==0)continue;
			f=false;
			break;
		}
		if(f){
			cout<<"YES"<<endl;
			return 0;
		}
			
	}
	
	cout<<"NO"<<endl;
		
		
	
    return 0;
}