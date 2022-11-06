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

int val1(string st){
	int si=SZ(st);
	int suma=0;
	int sirve=0;
	fore(i,0,si){
		if(st[i]=='('){suma++;
		}else{suma--;
		};
		if(suma<0){sirve--;
		};
		
	};
	if(sirve==0){return 1;
	}else{return 0;
	}
	
	
}

int val2(string st){
	int si=SZ(st);
	int suma=0;
	int sirve=0;
	for(int i=si-1;i>=0;i--){
		if(st[i]==')'){suma++;
		}else{suma--;
		};
		if(suma<0){sirve--;
		};
		
	};
	if(sirve==0){return 1;
	}else{return 0;
	}
	
	
}

int saldo(string st){
	int si=SZ(st);
	int suma=0;
	fore(i,0,si){
		if(st[i]=='('){suma++;
		}else{suma--;
		};
		
	};
	return suma;
	
	
}

int main(){
	
	int n; cin>>n;
	string paren[n];
	fore(i,0,n){
		cin>>paren[i];
	};
	
/*	fore(iii,0,n){
			
			cout<<paren[iii]<<" ";
		}; */
	
	int utiles[n];
	int usados=0;
	fore(i,0,n){
		if(val1(paren[i])||val2(paren[i])){
			utiles[usados]=(saldo(paren[i]));
			usados++;
		};
	};
	
	//sort(utiles,utiles+usados);
	
/*	fore(iii,0,usados){
			
			cout<<utiles[iii]<<" ";
		};*/
	
	//set<int> conj;
	/*fore(iiii,0,usados){
			
		conj.insert(utiles[iiii]);
		};*/
	
	
	int basura=usados,pares=0,ii=0;
	
	while(basura>0){
	
	
		int pos=0,neg=0;
		
		fore(iii,0,usados){
			
			if(utiles[iii]==ii){pos++;
			}else if(utiles[iii]==-ii){neg++;
			};
		};
		
		basura-=pos+neg;
		if(ii==0){pares+=(pos/2);
		}else{
		pares+=min(pos,neg);}
		//cout<<pares;
		ii++;
		
		
	//}
};
	
	cout<<pares;

	return 0;
}