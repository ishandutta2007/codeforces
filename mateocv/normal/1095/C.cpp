#include<bits/stdc++.h>
using namespace std;

int suma(int x){
	
	int result=0;
	
	while(x>0){
		result+=x%2;
		x/=2;
	}
	
	return result;
}

int main(){
	
	int n, k; cin>>n>>k;
	

	
	
	if((suma(n)>k)||k>n){cout<<"NO";
	}else{cout<<"YES"<<endl;
		
		int sol[k],usados=0,dec=n,pot=0,potr=1;
		
	/*	for(int jj=0;jj<k;jj++){
			sol[jj]=0;
		};*/
		
		while(dec>0){
			
			if(dec%2==1){
				
				for(int ii=0;ii<pot;ii++){
					potr*=2;
				};
				
				
				sol[usados]=potr;
				usados++;
				
			};
			
			pot++;
			dec/=2;
			potr=1;
			
		};
		
		while(usados<k){
			
			int find=-1;
			int busq=usados-1;
			
			while(find==-1){
				
				if(sol[busq]>1){find=busq;
				}else{busq--;
				};
			}
			
			sol[usados]=sol[busq]/2;
			sol[busq]/=2;
			usados++;
			
		}
		
		
		
		for(int i=0;i<k;i++){
			cout<<sol[i]<<" ";
		}
		
	}
		
		
	
	
	
	
	
	return 0;
}