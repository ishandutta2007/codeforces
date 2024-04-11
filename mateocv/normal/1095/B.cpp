#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n; cin>>n;
	int a[n];// maximo=0, minimo=100005,max2=100005/*min2=0*/;
	
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		/*if(array[i]>maximo){maximo=array[i];
		}else if(array[i]>max2){max2=array[i];
		};
		if(array[i]<minimo){minimo=array[i];
		}/*else if(array[i]<min2){min2=array[i];
		};*/
		
	};
	
	
	sort(a,a+n);
	
	
	cout<<min(a[n-2]-a[0],a[n-1]-a[1]);
	
	
	
	
	
	
	return 0;
}