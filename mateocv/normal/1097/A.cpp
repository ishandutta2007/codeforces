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
	
	string mesa,carta1,carta2,carta3,carta4,carta5;
	cin>>mesa>>carta1>>carta2>>carta3>>carta4>>carta5;
	
	int igual=0;
	 if((carta1[0]==mesa[0])||(carta2[0]==mesa[0])||(carta3[0]==mesa[0])||(carta4[0]==mesa[0])||(carta5[0]==mesa[0])){
	cout<<"YES";} else if((carta1[1]==mesa[1])||(carta2[1]==mesa[1])||(carta3[1]==mesa[1])||(carta4[1]==mesa[1])||(carta5[1]==mesa[1])){
	cout<<"YES";} else {cout<<"NO";
	}
	
	return 0;
}