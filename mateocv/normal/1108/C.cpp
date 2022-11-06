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
	string mod[6]={"RGB","RBG","GRB","GBR","BRG","BGR"};
	/*string rgb,rbg;
	fore(i,0,n/3){
		rgb+="RGB";
		rbg+="RBG";
	}*/
	int camb[6];
	memset(camb,0,sizeof camb);
	fore(i,0,n){
		fore(j,0,6){
			if(s[i]==mod[j][i%3]){
				camb[j]++;
			}
		}
	}
	
	int maxi=-1,maxid=-1;
	fore(i,0,6){
		if(camb[i]>maxi){
			maxi=camb[i];
			maxid=i;
		}
	}

	cout<<n-camb[maxid]<<"\n";
	fore(i,0,n/3){
		cout<<mod[maxid];
	}
	fore(i,0,n%3){
		cout<<mod[maxid][i];
	}
	
	
	
	return 0;
}