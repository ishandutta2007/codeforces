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
	return x;
}

const int N=1001001;
char s[N];
int main(){
	int t=read();
	while(t--){
		int n=read(),k=read();
		scanf("%s",s);
		bool h=false;
		int l;
		int c=0;
		V v;
		D(i,n){
			if(s[i]=='W'){
				c++;
				if(h){
					v.push_back(i-l-1);
				}
				l=i;
				h=true;
			}
		}
		if(h){
			sort(v.begin(),v.end());
			int ans=c+min(k,n-c)*2;
			for(int x:v){
				if(k<x)break;
				// cerr<<"!"<<x<<endl;
				k-=x;
				ans++;
			}
			printf("%d\n",ans);
		}
		else{
			k=min(n,k);
			printf("%d\n",k==0?0:2*k-1);
		}
	}
	return 0;
}