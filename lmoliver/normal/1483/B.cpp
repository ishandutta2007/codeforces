#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

const int N=1.1e5;
int a[N];

void work(){
	int n=read();
	F(i,1,n)a[i]=read();
	set<int> ids;
	F(i,1,n)ids.insert(i);
	set<int> chk=ids;
	V ans;
	// cerr<<"work"<<endl;
	while(true){
		bool did=false;
		set<int>::iterator it=chk.begin();
		while(it!=chk.end()){
			set<int>::iterator it2=ids.upper_bound(*it);
			if(it2==ids.end())it2=ids.begin();
			if(gcd(a[*it],a[*it2])==1){
				// cerr<<*it<<" -> "<<*it2<<endl;
				ans.push_back(*it2);
				if(*it==*it2)break;
				did=true;
				if(chk.count(*it2))chk.erase(*it2);
				if(ids.count(*it2))ids.erase(*it2);
				it++;
			}
			else{
				set<int>::iterator it2=it;
				it2++;
				chk.erase(it);
				it=it2;
			}
		}
		if(!did)break;
	}
	printf("%d",(int)ans.size());
	D(i,ans.size())printf(" %d",ans[i]);
	printf("\n");
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}