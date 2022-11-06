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
#define fora(j) for(int j=-1;j<2;j+=2)
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int main(){
	
	int n; cin>>n;
	int rot[20];
	fore(iii,0,20){
		rot[iii]=0;
	};
	fore(i,0,n){
		cin>>rot[i];
	};
	int listo=0;

fora(i2){
	fora(i3){
		fora(i4){
			fora(i5){
				fora(i6){
					fora(i7){
						fora(i8){
							fora(i9){
								fora(i10){
									fora(i11){
										fora(i12){
											fora(i13){
												fora(i14){
													fora(i15){
														if((rot[0]+i2*rot[1]+i3*rot[2]+i4*rot[3]+i5*rot[4]+i6*rot[5]+i7*rot[6]+i8*rot[7]+i9*rot[8]+i10*rot[9]+i11*rot[10]+i12*rot[11]+i13*rot[12]+i14*rot[13]+i15*rot[14])%360==0){listo++;
														}
													
}
}
}
}	
}
}
}
}
}
}
}	
}
}
};

	if(listo>0){
		cout<<"YES";
	}else{cout<<"NO";
	};
	
	
	return 0;
}