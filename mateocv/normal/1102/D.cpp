#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int contar(string &s, char c){
	int res=0;
	fore(i,0,SZ(s)){
		if(s[i]==c)res++;
	}
	return res;
}

void reemp(string &s, char a, int x, char b){
	if(b<a){reverse(s.begin(),s.end());
	}
	int van=0,i=0;
	while(van<x){
		if(s[i]==b){
			s[i]=a; van++;
		}
		i++;
	}
	if(b<a){reverse(s.begin(),s.end());
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int a,b,c;
	a=contar(s,'0')-n/3;
	b=contar(s,'1')-n/3;
	c=contar(s,'2')-n/3;
	
	if(abs(a)+abs(b)==abs(c)){
		if(c>0){
			reemp(s,'0',abs(a),'2');
			reemp(s,'1',abs(b),'2');
		}else{
			reemp(s,'2',abs(a),'0');
			reemp(s,'2',abs(b),'1');
		}
	}else
	
	if(abs(a)+abs(c)==abs(b)){
		if(b>0){
			reemp(s,'0',abs(a),'1');
			reemp(s,'2',abs(c),'1');
		}else{
			reemp(s,'1',abs(a),'0');
			reemp(s,'1',abs(c),'2');
		}
	}else 
	
	if(abs(b)+abs(c)==abs(a)){
		if(a>0){
			reemp(s,'2',abs(c),'0');
			reemp(s,'1',abs(b),'0');
		}else{
			reemp(s,'0',abs(c),'2');
			reemp(s,'0',abs(b),'1');
		}
	}
	
	cout<<s;
	
	return 0;
}