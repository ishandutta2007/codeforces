#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=2.1e5;
char op[N];
int v[N];
void gg(){
	puts("NO");
	exit(0);
}

int main(){
	int n=read();
	stack<int> s;
	F(i,1,2*n){
		do{
			scanf("%c",&op[i]);
		}while(isspace(op[i]));
		if(op[i]=='+')s.push(i);
		else if(op[i]=='-'){
			v[i]=read();
			if(s.empty())gg();
			else{
				v[s.top()]=v[i];
				s.pop();
			}
		}
		else abort();
	}
	set<int> qaq;
	F(i,1,2*n){
		if(op[i]=='+'){
			// cerr<<"+ "<<v[i]<<endl;
			qaq.insert(v[i]);
		}
		else{
			// cerr<<"- "<<v[i]<<endl;
			if(qaq.empty()||*qaq.begin()!=v[i])gg();
			qaq.erase(qaq.begin());
		}
	}
	puts("YES");
	F(i,1,2*n)if(op[i]=='+')printf("%d ",v[i]);
	printf("\n");
	return 0;
}