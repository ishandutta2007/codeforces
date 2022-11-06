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
	int vert=0,hor=0;
	string s; cin>>s;
	fore(i,0,SZ(s)){
		if(s[i]=='0'){if(vert==0){
			cout<<"1 1\n"; vert=1-vert;
		}else{cout<<"3 1\n"; vert=1-vert;
		}
		}else{
			cout<<hor+1<<" 2\n";hor++; hor%=4; 
		}
	}
	 
	
	return 0;
}