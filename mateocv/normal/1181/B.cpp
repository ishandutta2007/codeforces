#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

string sum(string x,string y){
	string a=x; string b=y;
	if(SZ(b)>SZ(a))swap(a,b);
	string c;
	fore(i,0,SZ(a)-SZ(b))c+='0';
	b=c+b;
	//cout<<a<<" "<<b<<"\n";
	for(int i=SZ(a)-1;i>=1;i--){
		if(a[i]-'0'+b[i]-'0'>=10){
			a[i]+=b[i]-10-'0';
			a[i-1]++;
		}else{
			a[i]+=b[i]-'0';
		}
	}
	if(a[0]-'0'+b[0]-'0'>=10){
		a[0]+=b[0]-10-'0';
		a='1'+a;
	}else{
		a[0]+=b[0]-'0';
	}
	return a;
}

int main(){FIN;
	//cout<<sum("1234","567");
	ll l; cin>>l;
	string s; cin>>s;
	string r1,r2;
	ll e=(l+1)/2;
	while(e<l){
		if(s[e]=='0')e++;
		else break;
	}
	string a,b;
	fore(i,0,e)a+=s[i];
	fore(i,e,l)b+=s[i];
	r1=sum(a,b);
	//cout<<r1<<endl;
	a=""; b="";
	e=l/2;
	while(e>=0){
		if(s[e]=='0')e--;
		else break;
	}
	fore(i,0,e)a+=s[i];
	fore(i,e,l)b+=s[i];
	r2=sum(a,b);
	//cout<<r1<<" "<<r2<<"\n";
	if(SZ(r1)>SZ(r2)){
		cout<<r2;
	}else if(SZ(r1)<SZ(r2)){
		cout<<r1;
	}else if(r1>r2){
		cout<<r2;
	}else cout<<r1;
	
	return 0;
}