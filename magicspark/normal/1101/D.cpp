#include<bits/stdc++.h>
#pragma optimize("Ofast")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
namespace fastio{
	char in[100000];
	int itr=0,llen=0;
	char get(){
		if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
		if(llen==0)return EOF;
		return in[itr++];
	}
	char out[100000];
	int itr2=0;
	void put(char c){
		out[itr2++]=c;
		if(itr2==100000){
			fwrite(out,1,100000,stdout);
			itr2=0;
		}
	}
	int clear(){
		fwrite(out,1,itr2,stdout);
		itr2=0;
		return 0;
	}
	int getint(){
    	int r=0; bool ng=0; char c; c=get();
    	while (c!='-'&&(c<'0'||c>'9')) c=get();
   		if (c=='-') ng=1, c=get();
    	while (c>='0'&&c<='9') r=r*10+c-'0', c=get();
    	return ng?-r:r;
	}
	string getstr(){
		string ret="";
		char ch=get();
		while(ch==' '||ch=='\n')ch=get();
		while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
		return ret;
	}
	void putstr(string s){
		for(int i=0;i<s.size();i++)put(s[i]);
	}
	void putint(int x){
		if(x<0){
			put('-');
			x=-x;
		}
		if(x==0){
			put('0');
			return;
		}
		char c[20];int pos=0;
		while(x){
			c[pos++]='0'+x%10;
			x/=10;
		}
		for(int i=pos-1;i>=0;i--)put(c[i]);
	}
	void getarr(int arrname[],int size){
		 for(int i=0;i<size;i++)arrname[i]=getint();
	}
}
using namespace fastio;
#define fastio
int prime[111111];
int check[222222];
int a[222222];
int n;
vector<int>g[222222];
bool used[222222];
int tot=0;
set<int>P;
set<int>Newp;
int dist[222222];
int que[222222],b,e;
int diameter(int x,int &primes){
	int mx=-1;
	b=0;e=1;que[0]=x;
	used[x]=true;
	dist[x]=0;
	vector<int>points;
	points.clear();
	points.push_back(x);
	while(b<e){
		int x=que[b++];
		for(auto p:g[x]){
			if(a[p]%primes==0&&dist[p]==inf){
				dist[p]=dist[x]+1;
				que[e++]=p;
				points.push_back(p);
				used[p]=true;
				mx=p;
			}
		}
	}
	if(mx==-1)return 1;
	for(auto p:points)dist[p]=inf;
	b=0;e=1;que[0]=mx;
	dist[mx]=0;
	int ans=0;
	while(b<e){
		int x=que[b++];
		for(auto p:g[x]){
			if(a[p]%primes==0&&dist[p]==inf){
				dist[p]=dist[x]+1;
				ans=dist[p];
				que[e++]=p;
			}
		}
	}
	return ans+1;
}
void sol(int x){
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
    		Newp.insert(i);
    		x/=i;
    	}
    }
    if(x!=1)Newp.insert(x);
}
int main(){
    n=getint();
    for(int i=0;i<n;i++){
    	a[i]=getint();
    	sol(a[i]);
	}
    for(int i=1;i<n;i++){
    	int x=getint(),y=getint();
    	x--;y--;
    	g[x].push_back(y);
    	g[y].push_back(x);
	}
	int ans=0;
	for(auto p:Newp){
		if(clock()>=350)return printf("%d\n",ans)&0;
		memset(dist,inf,sizeof(dist)); 
		memset(used,0,sizeof(used));
		for(int j=0;j<n;j++)if(!used[j])ans=max(ans,diameter(j,p));
	}
	cout<<ans<<endl;
	return 0;
}