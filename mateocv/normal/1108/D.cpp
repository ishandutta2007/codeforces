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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int camb=0;
	char rgb[3]={'R','G','B'};
	map<char,int> num;
	num['R']=0;
	num['G']=1;
	num['B']=2;
	fore(i,1,n){
		if(s[i]==s[i-1]){
			 camb++;
			 if(rgb[(num[s[i]]+1)%3]!=s[i+1]&&i+1<n){
			 	s[i]=rgb[(num[s[i]]+1)%3];
			 }else{s[i]=rgb[(num[s[i]]+2)%3];
			 }
		}
	}
	
	cout<<camb<<"\n";
	cout<<s;
	
	return 0;
}