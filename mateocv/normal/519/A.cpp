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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	char c;
	ll Wh=0, Bl=0;
	fore(i,0,64){//QRBNPK95331
		cin>>c;
		if(c=='Q')Wh+=9;
		if(c=='R')Wh+=5;
		if(c=='B')Wh+=3;
		if(c=='N')Wh+=3;
		if(c=='P')Wh+=1;
		if(c=='q')Bl+=9;
		if(c=='r')Bl+=5;
		if(c=='b')Bl+=3;
		if(c=='n')Bl+=3;
		if(c=='p')Bl+=1;
		
	}
	if(Wh>Bl)cout<<"White";
	if(Wh<Bl)cout<<"Black";
	if(Wh==Bl)cout<<"Draw";
	
	return 0;
}