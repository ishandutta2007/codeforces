#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=2.1e5;
const int A=5.1e6;
typedef pair<int,int> P;
vector<P> mp[A];
int a[N];
int main(){
	int n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)F(j,1,i-1){
		int x=a[i]+a[j];
		vector<P> &qaq=mp[x];
		D(k,qaq.size()){
			P w=qaq[k];
			if(i!=w.first&&i!=w.second&&j!=w.first&&j!=w.second){
				puts("YES");
				printf("%d %d %d %d\n",w.second,w.first,j,i);
				exit(0);
			}
		}
		qaq.push_back(P(i,j));
	}
	puts("NO");
	return 0;
}