#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,b;
	cin>>t;
	for(int s=0;s<t;s++){
		cin>>b;
		int flag=0;
		for(int x3=0;x3<=b/3+1;x3++){
			for(int x5=0;x5<=b/5+1;x5++){
				for(int x7=0;x7<=b/3+1;x7++){
					if(x3*3+x5*5+x7*7==b){
						cout<<x3<<" "<<x5<<" "<<x7<<endl;
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}	
			if(flag==1){
				break;
			}
		}
		if(flag==0){
			cout<<"-1\n";
		}
	}
	return 0;
}