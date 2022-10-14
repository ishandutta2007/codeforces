#include<bits/stdc++.h>
using namespace std;
int const N=23333;
int n,m,op,ans;
double f[N];
string s;
namespace rando{
	int const K=100000000;
	mt19937_64 rnd(chrono::steady_clock::
		now().time_since_epoch().count());
	auto gen=[](int l,int r){return rnd()%(r-l+1)+l;};
	auto ckprob=[](double x){return gen(1,K)<=K*x;};
}
int main(){
	ios::sync_with_stdio(0);
	double k=0.8;
	for(cin>>n>>m,fill(f,f+n,1.0);m--;){
		cin>>s;
		double p1=0.0,p2=0.0;
		for(int i=0;i<n;i++)
			if(s[i]<49)p1+=f[i];
			else p2+=f[i];
		cout<<rando::ckprob(p2/(p1+p2))<<endl;
		cin>>op;
		for(int i=0;i<n;i++)
			f[i]*=s[i]-48==op?1.0:k;
	}
}//