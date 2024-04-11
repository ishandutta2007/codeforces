#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=1.6e3;
V a1[N];
V a2[N];
map<V,V> qaq;

V locks[N];
int lockcnt[N];

void gg(){
	puts("-1");
	exit(0);
}

int main(){
	int n=read(),m=read();
	F(i,1,n){
		a1[i]=V(m);
		D(j,m)a1[i][j]=read();
		qaq[a1[i]].push_back(i);
	}
	for(map<V,V>::iterator it=qaq.begin();it!=qaq.end();it++){
		reverse(it->second.begin(),it->second.end());
	}
	F(i,1,n){
		a2[i]=V(m);
		D(j,m)a2[i][j]=read();
		V &v=qaq[a2[i]];
		if(v.size()==0)gg();
		a2[i].push_back(v.back());
		v.pop_back();
	}
	V ans;
	F(i,0,m){
		F(j,1,n-1){
			if(a2[j][i]>a2[j+1][i]){
				locks[j].push_back(i);
				// cerr<<"lock "<<i<<" @"<<j<<endl;
				lockcnt[i]++;
			}
		}
	}
	V st;
	F(i,0,m)if(lockcnt[i]==0)st.push_back(i);
	while(!st.empty()){
		int x=st.back();
		st.pop_back();
		if(x==m){
			printf("%d\n",(int)ans.size());
			while(!ans.empty()){
				printf("%d ",ans.back()+1);
				ans.pop_back();
			}
			printf("\n");
			exit(0);
		}
		else{
			ans.push_back(x);
			F(i,1,n-1)if(a2[i][x]<a2[i+1][x]){
				D(j,locks[i].size()){
					if(--lockcnt[locks[i][j]]==0){
						st.push_back(locks[i][j]);
					}
				}
				locks[i].clear();
			}
		}
	}
	gg();
	return 0;
}