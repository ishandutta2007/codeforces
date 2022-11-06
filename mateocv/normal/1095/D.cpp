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

int buscar(int x,int y,int z,int w){
	if((z==y)||(w==y)){return x;
	}else{return y;
	}
}

int main(){
	
	int n; cin>>n;
	int info[n][2];
	fore(i,0,n){
		cin>>info[i][0]>>info[i][1];
	};
	
	if(n==3){cout<<"1 2 3";
	}else{
	
	
	int chico=1;
	while(n--){
		cout<<chico<<" ";
	//	cout<<info[chico-1][0]<<" "<<info[chico-1][1]<<" "<<info[info[chico-1][0]-1][0]<<" "<<info[info[chico-1][0]-1][1]<<endl;
		chico=buscar(info[chico-1][0],info[chico-1][1],info[info[chico-1][0]-1][0],info[info[chico-1][0]-1][1]);
		
	};
}
	return 0;
}