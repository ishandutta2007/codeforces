#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

int main(){
	int t=read();
	while(t--){
		int n=read();
		V v;
		while(n--)v.push_back(read());
		LL sum=0;
		for(int x:v)sum+=x;
		if(sum==0){
			puts("NO");
		}
		else{
			puts("YES");
			sort(v.begin(),v.end());
			if(sum>0)reverse(v.begin(),v.end());
			for(int x:v)printf("%d ",x);
			printf("\n");
		}
	}
	return 0;
}