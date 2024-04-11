#include<bits/stdc++.h>
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
int q;
#define SZ ((1<<25)+1)
bool notprime[SZ];
int primes[(int)1e7+5];
int pre[SZ];
void init(){
	memset(notprime,false,sizeof(notprime));
	notprime[0]=notprime[1]=true;
	int pos=0;
	for(int i=2;i<SZ;i++){
		if(!notprime[i])primes[pos++]=i,pre[i]=i;
		for(int j=0;j<pos&&i*primes[j]<SZ;j++){
			notprime[i*primes[j]]=true;
			pre[i*primes[j]]=primes[j];
			if(i%primes[j]==0)break;
		}
	}
}
int main(){
	init();
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int ans;
		for(int i=1;i<=30;i++){
			if((1<<i)>x){
				ans=(1<<i)-1;
				break;
			}
		}
		if(ans==x){
			cout<<ans/pre[ans]<<endl;
		}else cout<<ans<<endl;
	}
	return 0;
}